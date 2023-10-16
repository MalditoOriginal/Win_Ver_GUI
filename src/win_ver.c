#include "win_ver.h"

HWND InitializeWindow(HINSTANCE hInstance) {
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), 
    CS_CLASSDC, WndProc, 
    0L, 
    0L, 
    hInstance, 
    NULL, 
    NULL, 
    NULL, 
    NULL, 
    _T("WinVerApp"), NULL 
    };
    if (!RegisterClassEx(&wc)) {
        return NULL;
    }

    int winWidth = 400;
    int winHeight = 200;
    LPCTSTR winTitle = _T("Windows Version Info");

    HWND hwnd = CreateWindow(wc.lpszClassName, winTitle, WS_OVERLAPPEDWINDOW, 100, 100, winWidth, winHeight, NULL, NULL, wc.hInstance, NULL);

    if (!hwnd) {
        return NULL;
    }

    ShowWindow(hwnd, SW_SHOWDEFAULT);
    UpdateWindow(hwnd);

    return hwnd;
}

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