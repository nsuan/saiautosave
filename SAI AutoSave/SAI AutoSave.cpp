// SAI AutoSave.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#define MINUTE_WAIT 1L


BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam) {
	TCHAR className[MAX_PATH];
	
	if (!hWnd)
		return TRUE;		// Not a window

	GetClassName(hWnd, className, _countof(className)); 
	//Is this the SAI window? If so, send Ctrl+S, then fuck off for another 5 minutes
	if (_tcscmp(className, _T("sfl_window_class")) == 0) {
		PostMessage(hWnd, WM_KEYDOWN, VK_CONTROL, 0);
		PostMessage(hWnd, WM_KEYDOWN, (TCHAR)'S', 0);
		PostMessage(hWnd, WM_KEYUP, (TCHAR)'S', 0);
		PostMessage(hWnd, WM_KEYUP, VK_CONTROL, 0);
		return 0;
	}
	return 1;
		
}
int _tmain(int argc, _TCHAR* argv[])
{
	while (true) {
		FreeConsole();
		Sleep(MINUTE_WAIT * 60 * 1000); // sleep five minutes
		EnumWindows(EnumWindowsProc,NULL);
	}
	return 0;
}

