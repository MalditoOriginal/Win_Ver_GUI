#include "win_ver.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    (void)hPrevInstance;
    (void)lpCmdLine;
    (void)nCmdShow;
    
    hwnd = InitializeWindow(hInstance);
    if (!hwnd) {
        HandleError(hwnd, _T("Failed to create the application window."));
        return 1;
    }

    DisplayVersionInfo(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}