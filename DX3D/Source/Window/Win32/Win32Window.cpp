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


DX3D::Window::Window(const WindowDesc& desc) : Base(desc.base)
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
	{
		getLogger().log(Logger::LogLevel::Error, "RegisterClassEx Failed.");
		throw std::runtime_error("Failed to register window class");
		MessageBox(NULL, L"Failed to register window class", L"Error", MB_ICONERROR);
		return;
	}

	RECT rc{ 0, 0, 1280, 720 };
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, FALSE);

	m_handle = CreateWindowEx(0, MAKEINTATOM(windowClassId), L"Vertex Horizon | C++ 3D Game Engine",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, GetModuleHandle(NULL), NULL);

	if (!m_handle)
	{
		getLogger().log(Logger::LogLevel::Error, "CreateWindowEx Failed.");
		throw std::runtime_error("Failed to create window");
		MessageBox(NULL, L"Failed to create window", L"Error", MB_ICONERROR);
		return;
	};

	ShowWindow(m_handle, SW_SHOW);
}

DX3D::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(m_handle));
}