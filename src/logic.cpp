#include "global.h"

TCHAR* FormatServicePackInfo(const OSVERSIONINFOEXA& osvi) {
    TCHAR buffer[256];
    if (osvi.szCSDVersion[0] != '\0') {
        _stprintf(buffer, _T("Service Pack: %s"), osvi.szCSDVersion);
    } else {
        _stprintf(buffer, _T("Service Pack: None"));
    }
    return _tcsdup(buffer);
}

void DisplayVersionInfo(HWND hwnd) {
    OSVERSIONINFOEXA osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEXA));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXA);

    if (GetVersionExA((LPOSVERSIONINFOA)&osvi)) {
        TCHAR buffer[256];
        _stprintf(buffer, _T("Windows Version: %d.%d\nBuild Number: %ld"), osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber);

        LPCTSTR edition = GetWindowsEdition(osvi.wProductType);
        _stprintf(buffer, _T("%s\nEdition: %s"), buffer, edition);

        TCHAR* service_pack = FormatServicePackInfo(osvi);
        _tcscat(buffer, _T("\n")); // Use _tcscat as a safer alternative
        _tcscat(buffer, service_pack);
        free(service_pack);

        MessageBox(hwnd, buffer, _T("Version Info"), MB_ICONINFORMATION | MB_OK);
    } else {
        HandleError(hwnd, _T("Failed to retrieve OS version information."));
    }
}



LPCTSTR GetWindowsEdition(WORD productType) {
    LPCTSTR edition = _T("Unknown");

    if (productType == VER_NT_WORKSTATION) {
        edition = _T("Client");
    } else if (productType == VER_NT_SERVER) {
        edition = _T("Sercer");
    } else if (productType == VER_NT_DOMAIN_CONTROLLER) {
        edition = _T("Domain Controller");
    }
    return edition;
}