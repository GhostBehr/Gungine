#pragma once

#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <tchar.h>

#include "GungineWindow.h"

namespace gungine {
	class Win32Window : public GungineWindow {
	public:
		virtual int create();
		static int setupPixelFormat(HDC hdc);
	};

	
	LRESULT CALLBACK wndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
}