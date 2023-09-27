#ifndef WIN_VER_H
#define WIN_VER_H

#include <windows.h>

// Function declarations
HWND InitializeWindow(HINSTANCE hInstance);
void DisplayVersionInfo(HWND hwnd);
void HandleError(HWND hwnd);

#endif
