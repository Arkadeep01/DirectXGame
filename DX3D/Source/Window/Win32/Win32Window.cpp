#define UNICODE
#define _UNICODE
#include <Window/Window.h>
#include <Windows.h>
#include <stdexcept>

static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}


DX3D::Window::Window(const WindowDesc& desc) : Base(desc.base), m_size(desc.size)
{
	auto registerWindowClassFunction = []()
		{
			WNDCLASSEX wc{};
			wc.cbSize = sizeof(WNDCLASSEX);
			wc.lpszClassName = L"DX3DWindowClass";
			wc.lpfnWndProc = &WindowProcedure;
			wc.hInstance = GetModuleHandle(NULL);

			return RegisterClassEx(&wc);
		};


	auto windowClassId = registerWindowClassFunction();
	if (!windowClassId)
		DX3DLogErrorAndThrow("Failed to register window class");

	RECT rc{ 0, 0, m_size.width, m_size.height};
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE);

	m_handle = CreateWindowEx(0, MAKEINTATOM(windowClassId), L"Vertex Horizon | C++ 3D Game Engine",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, GetModuleHandle(NULL), NULL);

	if (!m_handle)
		DX3DLogErrorAndThrow("CreateWindowEx Failed.");

	ShowWindow(m_handle, SW_SHOW);
}

DX3D::Window::~Window()
{
	DestroyWindow(m_handle);
}