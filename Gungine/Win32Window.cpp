#include "GungineApp.h"
#include "Win32Window.h"

TCHAR TITLE_BAR_TEXT[] = "Gungine";
TCHAR WINDOW_CLASS_NAME[] = "Gunegine Win32 Window Class";

int gungine::Win32Window::create(int width, int height) {
	
	// Current instance of application
	HINSTANCE hInstance = GetModuleHandle(NULL);

	/// Create window class structure
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wcex.lpfnWndProc = gungine::wndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = WINDOW_CLASS_NAME;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!wcex.lpfnWndProc) {
		MessageBox(NULL, _T("hInstance null!"), _T("Gungine"), NULL);
		return 1;
	}

	/// Register window
	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("Gungine"), NULL);
		return 1;
	}

	HWND hWnd = CreateWindow(
		WINDOW_CLASS_NAME,
		TITLE_BAR_TEXT,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CS_OWNDC,
		width, height,
		NULL,
		NULL,
		hInstance,
		NULL
		);

	if (!hWnd) {
		MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("Gungine"), NULL);
		return 1;
	}

	/// Display window
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
	
	/// Listen for messages from OS
	MSG msg;
	HDC hdc = GetDC(hWnd);
	GungineApp* app = GungineApp::get();
	while (app->running) {
		//std::cout << "LOOP\n";

		while (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
			GetMessage(&msg, NULL, 0, 0);
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		app->preRender();
		app->render();
		app->postRender();
		SwapBuffers(hdc);
	}

	//return (int)msg.wParam;
	return 0;
}

int gungine::Win32Window::setupPixelFormat(HDC hdc) {
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
		PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
		32,                        //Colordepth of the framebuffer.
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24,                        //Number of bits for the depthbuffer
		8,                        //Number of bits for the stencilbuffer
		0,                        //Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	int pfn = ChoosePixelFormat(hdc, &pfd);

	if (pfn == 0) {
		MessageBox(NULL, _T("Call to ChoosePixelFormat failed!"), _T("Gungine"), NULL);
		return 1;
	}

	SetPixelFormat(hdc, pfn, &pfd);
	return 0;
}

LRESULT CALLBACK gungine::wndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	static HDC hdc = NULL;
	static HGLRC contextH = NULL;
	GungineApp* app = GungineApp::get();
	std::ostringstream ss;

	switch (msg) {

	case WM_CREATE:
		hdc = GetDC(hWnd);

		Win32Window::setupPixelFormat(hdc);

		/// THESE ARE OPENGL CALLS AND SHOULD BE DECOUPLED FROM THE WIN32 WINDOW
		///////////////////////////////////////////////////////////////////////////////
		if (hdc == NULL) {
			MessageBoxA(0, _T("HIIIIIII"), "Err", 0);
		}
		
		contextH = wglCreateContext(hdc);
		wglMakeCurrent(hdc, contextH);

		if (wglGetCurrentContext() == 0) {
			ss << GetLastError();
			MessageBoxA(0, ss.str().c_str(), "GetContextErr", 0);
		}

		if (wglGetCurrentDC() == 0) {
			ss << GetLastError();
			MessageBoxA(0, ss.str().c_str(), "GetDCErr", 0);
		}
		
		
		//MessageBoxA(0, (char*)glGetString(GL_VERSION), "OPENGL VERSION", 0);
		///////////////////////////////////////////////////////////////////////////////

		app->onStart();
		break;

	case WM_PAINT:
		PAINTSTRUCT ps;
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
	case WM_QUIT:
	case WM_CLOSE:
		wglMakeCurrent(hdc, NULL);
		wglDeleteContext(contextH);
		PostQuitMessage(0);

		app->onEnd();
		break;

		/// Consider using these messages in the future
	case WM_SIZE:
		break;

	case WM_ACTIVATEAPP:
		break;

	case WM_LBUTTONDOWN:
		break;

	case WM_RBUTTONDOWN:
		break;

	case WM_MOUSEMOVE:
		break;

	case WM_LBUTTONUP:
		break;

	case WM_RBUTTONUP:
		break;

	case WM_KEYUP:
		break;

	case WM_KEYDOWN:
		break;
	
	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}