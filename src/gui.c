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