#include <Windows.h>
#include <Shlobj.h>
#include <stdio.h>
#include <wchar.h>

__declspec(dllexport) void CreateTextFile()
{
    WCHAR publicDocsPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_COMMON_DOCUMENTS, NULL, 0, publicDocsPath) != S_OK) {
        return;
    }

    WCHAR filePath[MAX_PATH];
    wcscpy(filePath, publicDocsPath);
    wcscat(filePath, L"\\test.txt");

    // Create and open the file
    FILE* file;
    
    fwprintf(file, L"Hello, this is some arbitrary text!\n");

    // Close the file
    fclose(file);
    
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    static HANDLE hThread;
    switch (ul_reason_for_call)
    {
    case DLL_THREAD_ATTACH:
    case DLL_PROCESS_ATTACH:
        CreateTextFile();
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}