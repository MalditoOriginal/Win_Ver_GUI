#ifndef WIN_VER_H
#define WIN_VER_H

#define UNICODE
#define _UNICODE
#include <windows.h>
#include <tchar.h>
#include <winuser.h>

// Global variable to store the window handle
HWND hwnd;

// Core prototypes
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Logic prototypes
HWND InitializeWindow(HINSTANCE hInstance);
void HandleError(HWND hwnd, LPCTSTR errMsg);

// GUI prototype
void DisplayVersionInfo(HWND hwnd);
#endif
