#include <windows.h>
#include <tchar.h>
#include "win_ver.h"

HWND hwnd;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

HWND InitializeWindow(HINSTANCE hInstance) {
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, hInstance, NULL, NULL, NULL, NULL, _T("WinVerApp"), NULL };
    RegisterClassEx(&wc);

    HWND hwnd = CreateWindow(wc.lpszClassName, _T("Windows Version Info"), WS_OVERLAPPEDWINDOW, 100, 100, 400, 200, NULL, NULL, wc.hInstance, NULL);

    ShowWindow(hwnd, SW_SHOWDEFAULT);
    UpdateWindow(hwnd);

    return hwnd;
}

void DisplayVersionInfo(HWND hwnd) {
    OSVERSIONINFOEX osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (GetVersionExA((LPOSVERSIONINFO)&osvi)) {
        TCHAR buffer[256];
        _stprintf(buffer, _T("Windows Version: %d.%d"), osvi.dwMajorVersion, osvi.dwMinorVersion);
        MessageBox(hwnd, buffer, _T("Version Info"), MB_ICONINFORMATION | MB_OK);

        _stprintf(buffer, _T("Build Number: %ld"), osvi.dwBuildNumber);
        MessageBox(hwnd, buffer, _T("Version Info"), MB_ICONINFORMATION | MB_OK);

        _stprintf(buffer, _T("Service Pack: %s"), osvi.szCSDVersion);
        MessageBox(hwnd, buffer, _T("Version Info"), MB_ICONINFORMATION | MB_OK);
    } else {
        HandleError(hwnd);
    }
}

void HandleError(HWND hwnd) {
    MessageBox(hwnd, _T("Error getting OS version"), _T("Error"), MB_ICONERROR | MB_OK);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    hwnd = InitializeWindow(hInstance);
    if (!hwnd) {
        HandleError(hwnd);
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
