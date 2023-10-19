#include "global.h"

void HandleError(HWND hwnd, LPCTSTR errMsg) {
    TCHAR msg[256];
    _stprintf(msg, _T("Error: %s"), errMsg);
    MessageBox(hwnd, msg, _T("Error"), MB_ICONERROR | MB_OK);
}