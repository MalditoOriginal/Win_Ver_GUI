#ifndef WIN_VER_H
#define WIN_VER_H

#define UNICODE
#define _UNICODE
#include <windows.h>
#include <tchar.h>
#include <winuser.h>

// Function prototypes
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
HWND InitializeWindow(HINSTANCE hInstance);
void DisplayVersionInfo(HWND hwnd);
void HandleError(HWND hwnd, LPCTSTR errMsg);

// Global variable to store the window handle
HWND hwnd;

#endif
