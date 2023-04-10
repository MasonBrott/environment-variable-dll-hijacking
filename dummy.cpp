#include <Windows.h>
#include <Shlobj.h>
#include <fstream>

extern "C" __declspec(dllexport) void CreateTextFile()
{
    WCHAR publicDocsPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_COMMON_DOCUMENTS, NULL, 0, publicDocsPath) != S_OK) {
        return;
    }

    std::wstring filePath = std::wstring(publicDocsPath) + L"\\test.txt";

    // Create and open the file
    FILE* file = _wfopen(filePath.c_str(), L"w");

    if (file != nullptr) {
        // Write arbitrary text to the file
        fwprintf(file, L"Hello, this is some arbitrary text!\n");

        // Close the file
        fclose(file);
    }
}

bool APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpreserved)
{
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
