#ifndef GLOBAL_H
#define GLOBAL_H

#define UNICODE
#define _UNICODE
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#include <winnt.h>
#include <windows.h>
#include <tchar.h>

// Core prototypes
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Logic prototypes
HWND InitializeWindow(HINSTANCE hInstance);
LPCTSTR GetWindowsEdition(WORD productType);
void HandleError(HWND hwnd, LPCTSTR errMsg);

// GUI prototype
void DisplayVersionInfo(HWND hwnd);
#endif