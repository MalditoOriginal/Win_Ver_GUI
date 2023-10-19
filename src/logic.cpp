#include "global.h"

void DisplayVersionInfo(HWND hwnd) {
    OSVERSIONINFOEXA osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEXA));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXA);

    if (GetVersionExA((LPOSVERSIONINFOA)&osvi)) {
        TCHAR buffer[256];
        _stprintf(buffer, _T("Windows Version: %d.%d\nBuild Number: %ld\nService Pack: %s"), osvi.dwMajorVersion, osvi.dwMinorVersion, osvi.dwBuildNumber, osvi.szCSDVersion);
        MessageBox(hwnd, buffer, _T("Version Info"), MB_ICONINFORMATION | MB_OK);
    } else {
        HandleError(hwnd, _T("Failed to retrieve OS version information."));
    }
}


void HandleError(HWND hwnd, LPCTSTR errMsg) {
    TCHAR msg[256];
    _stprintf(msg, _T("Error: %s"), errMsg);
    MessageBox(hwnd, msg, _T("Error"), MB_ICONERROR | MB_OK);
}