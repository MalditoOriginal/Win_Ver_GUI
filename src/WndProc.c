#include "win_ver.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
        if (MessageBox(hwnd, _T"Do you want to exit?", _T"Confirmation", MB_ICONQUESTION | MB_YESNO)) {
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