#include "global.h"

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

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
            if (MessageBox(hwnd, _T("Do you want to exit?"), _T("Confirmation"), MB_ICONQUESTION | MB_YESNO) == IDYES) {
                DestroyWindow(hwnd);
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}