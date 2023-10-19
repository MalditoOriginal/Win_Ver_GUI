#include "global.h"

// Define a function to check if it's Windows 10 based on the provided conditions.
bool IsWindows10(const OSVERSIONINFOEX& osvi) {
    return (osvi.dwMajorVersion == 10 && osvi.dwMinorVersion == 0 &&
            osvi.wProductType != VER_NT_WORKSTATION) ||
           (osvi.wProductType == VER_NT_WORKSTATION);
}

void DisplayVersionInfo(HWND hwnd) {
    OSVERSIONINFOEX osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    TCHAR buffer[256];

    if (GetVersionEx((LPOSVERSIONINFO)&osvi)) {
        if (IsWindows10(osvi)) {
            // Windows 10 detected with the specified conditions
            _stprintf(buffer, _T("This is Windows 10"));
        } else {
            _stprintf(buffer, _T("This is not Windows 10"));
        }
        MessageBox(hwnd, buffer, _T("Version Info"), MB_ICONINFORMATION | MB_OK);
    } else {
        HandleError(hwnd, _T("Failed to retrieve OS version information."));
    }
}
