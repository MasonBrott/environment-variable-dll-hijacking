#include <Windows.h>
#include <Shlobj.h>
#include <fstream>

// start export directions
#pragma once
#pragma comment(linker,"/export:AcceptEx=C:\\\\Windows\\\\System32\\\\mswsock.dll.AcceptEx,@1")
#pragma comment(linker,"/export:dn_expand=C:\\\\Windows\\\\System32\\\\mswsock.dll.dn_expand,@57")
#pragma comment(linker,"/export:EnumProtocolsA=C:\\\\Windows\\\\System32\\\\mswsock.dll.EnumProtocolsA,@2")
#pragma comment(linker,"/export:EnumProtocolsW=C:\\\\Windows\\\\System32\\\\mswsock.dll.EnumProtocolsW,@3")
#pragma comment(linker,"/export:GetAcceptExSockaddrs=C:\\\\Windows\\\\System32\\\\mswsock.dll.GetAcceptExSockaddrs,@4")
#pragma comment(linker,"/export:GetAddressByNameA=C:\\\\Windows\\\\System32\\\\mswsock.dll.GetAddressByNameA,@5")
#pragma comment(linker,"/export:GetAddressByNameW=C:\\\\Windows\\\\System32\\\\mswsock.dll.GetAddressByNameW,@6")
#pragma comment(linker,"/export:GetNameByTypeA=C:\\\\Windows\\\\System32\\\\mswsock.dll.GetNameByTypeA,@7")
#pragma comment(linker,"/export:GetNameByTypeW=C:\\\\Windows\\\\System32\\\\mswsock.dll.GetNameByTypeW,@8")
#pragma comment(linker,"/export:getnetbyname=C:\\\\Windows\\\\System32\\\\mswsock.dll.getnetbyname,@58")
#pragma comment(linker,"/export:GetServiceA=C:\\\\Windows\\\\System32\\\\mswsock.dll.GetServiceA,@9")
#pragma comment(linker,"/export:GetServiceW=C:\\\\Windows\\\\System32\\\\mswsock.dll.GetServiceW,@10")
#pragma comment(linker,"/export:GetSocketErrorMessageW=C:\\\\Windows\\\\System32\\\\mswsock.dll.GetSocketErrorMessageW,@11")
#pragma comment(linker,"/export:GetTypeByNameA=C:\\\\Windows\\\\System32\\\\mswsock.dll.GetTypeByNameA,@12")
#pragma comment(linker,"/export:GetTypeByNameW=C:\\\\Windows\\\\System32\\\\mswsock.dll.GetTypeByNameW,@13")
#pragma comment(linker,"/export:inet_network=C:\\\\Windows\\\\System32\\\\mswsock.dll.inet_network,@59")
#pragma comment(linker,"/export:MigrateWinsockConfiguration=C:\\\\Windows\\\\System32\\\\mswsock.dll.MigrateWinsockConfiguration,@14")
#pragma comment(linker,"/export:MigrateWinsockConfigurationEx=C:\\\\Windows\\\\System32\\\\mswsock.dll.MigrateWinsockConfigurationEx,@15")
#pragma comment(linker,"/export:NPLoadNameSpaces=C:\\\\Windows\\\\System32\\\\mswsock.dll.NPLoadNameSpaces,@16")
#pragma comment(linker,"/export:NSPStartup=C:\\\\Windows\\\\System32\\\\mswsock.dll.NSPStartup,@17")
#pragma comment(linker,"/export:ProcessSocketNotifications=C:\\\\Windows\\\\System32\\\\mswsock.dll.ProcessSocketNotifications,@18")
#pragma comment(linker,"/export:rcmd=C:\\\\Windows\\\\System32\\\\mswsock.dll.rcmd,@60")
#pragma comment(linker,"/export:rexec=C:\\\\Windows\\\\System32\\\\mswsock.dll.rexec,@61")
#pragma comment(linker,"/export:rresvport=C:\\\\Windows\\\\System32\\\\mswsock.dll.rresvport,@62")
#pragma comment(linker,"/export:s_perror=C:\\\\Windows\\\\System32\\\\mswsock.dll.s_perror,@63")
#pragma comment(linker,"/export:sethostname=C:\\\\Windows\\\\System32\\\\mswsock.dll.sethostname,@64")
#pragma comment(linker,"/export:SetServiceA=C:\\\\Windows\\\\System32\\\\mswsock.dll.SetServiceA,@19")
#pragma comment(linker,"/export:SetServiceW=C:\\\\Windows\\\\System32\\\\mswsock.dll.SetServiceW,@20")
#pragma comment(linker,"/export:StartWsdpService=C:\\\\Windows\\\\System32\\\\mswsock.dll.StartWsdpService,@21")
#pragma comment(linker,"/export:StopWsdpService=C:\\\\Windows\\\\System32\\\\mswsock.dll.StopWsdpService,@22")
#pragma comment(linker,"/export:Tcpip4_WSHAddressToString=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHAddressToString,@23")
#pragma comment(linker,"/export:Tcpip4_WSHEnumProtocols=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHEnumProtocols,@24")
#pragma comment(linker,"/export:Tcpip4_WSHGetBroadcastSockaddr=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHGetBroadcastSockaddr,@25")
#pragma comment(linker,"/export:Tcpip4_WSHGetProviderGuid=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHGetProviderGuid,@26")
#pragma comment(linker,"/export:Tcpip4_WSHGetSockaddrType=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHGetSockaddrType,@27")
#pragma comment(linker,"/export:Tcpip4_WSHGetSocketInformation=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHGetSocketInformation,@28")
#pragma comment(linker,"/export:Tcpip4_WSHGetWildcardSockaddr=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHGetWildcardSockaddr,@30")
#pragma comment(linker,"/export:Tcpip4_WSHGetWinsockMapping=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHGetWinsockMapping,@31")
#pragma comment(linker,"/export:Tcpip4_WSHGetWSAProtocolInfo=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHGetWSAProtocolInfo,@29")
#pragma comment(linker,"/export:Tcpip4_WSHIoctl=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHIoctl,@32")
#pragma comment(linker,"/export:Tcpip4_WSHJoinLeaf=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHJoinLeaf,@33")
#pragma comment(linker,"/export:Tcpip4_WSHNotify=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHNotify,@34")
#pragma comment(linker,"/export:Tcpip4_WSHOpenSocket=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHOpenSocket,@35")
#pragma comment(linker,"/export:Tcpip4_WSHOpenSocket2=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHOpenSocket2,@36")
#pragma comment(linker,"/export:Tcpip4_WSHSetSocketInformation=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHSetSocketInformation,@37")
#pragma comment(linker,"/export:Tcpip4_WSHStringToAddress=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip4_WSHStringToAddress,@38")
#pragma comment(linker,"/export:Tcpip6_WSHAddressToString=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHAddressToString,@39")
#pragma comment(linker,"/export:Tcpip6_WSHEnumProtocols=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHEnumProtocols,@40")
#pragma comment(linker,"/export:Tcpip6_WSHGetProviderGuid=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHGetProviderGuid,@41")
#pragma comment(linker,"/export:Tcpip6_WSHGetSockaddrType=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHGetSockaddrType,@42")
#pragma comment(linker,"/export:Tcpip6_WSHGetSocketInformation=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHGetSocketInformation,@43")
#pragma comment(linker,"/export:Tcpip6_WSHGetWildcardSockaddr=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHGetWildcardSockaddr,@45")
#pragma comment(linker,"/export:Tcpip6_WSHGetWinsockMapping=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHGetWinsockMapping,@46")
#pragma comment(linker,"/export:Tcpip6_WSHGetWSAProtocolInfo=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHGetWSAProtocolInfo,@44")
#pragma comment(linker,"/export:Tcpip6_WSHIoctl=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHIoctl,@47")
#pragma comment(linker,"/export:Tcpip6_WSHJoinLeaf=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHJoinLeaf,@48")
#pragma comment(linker,"/export:Tcpip6_WSHNotify=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHNotify,@49")
#pragma comment(linker,"/export:Tcpip6_WSHOpenSocket=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHOpenSocket,@50")
#pragma comment(linker,"/export:Tcpip6_WSHOpenSocket2=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHOpenSocket2,@51")
#pragma comment(linker,"/export:Tcpip6_WSHSetSocketInformation=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHSetSocketInformation,@52")
#pragma comment(linker,"/export:Tcpip6_WSHStringToAddress=C:\\\\Windows\\\\System32\\\\mswsock.dll.Tcpip6_WSHStringToAddress,@53")
#pragma comment(linker,"/export:TransmitFile=C:\\\\Windows\\\\System32\\\\mswsock.dll.TransmitFile,@54")
#pragma comment(linker,"/export:WSARecvEx=C:\\\\Windows\\\\System32\\\\mswsock.dll.WSARecvEx,@55")
#pragma comment(linker,"/export:WSPStartup=C:\\\\Windows\\\\System32\\\\mswsock.dll.WSPStartup,@56")
// end export directions

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

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  fdwreason, LPVOID lpReserved)
{   
    static HANDLE hThread;
    switch (fdwreason)
    {
    case DLL_THREAD_ATTACH:
    case DLL_PROCESS_ATTACH:
        {
            CreateTextFile();
        }
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
