#pragma once
#include <Core/Base.h>
#include <Windows.h>

namespace DX3D
{
	class Window : public Base
	{
	public:
		Window();
		virtual ~Window() override;

	private:
		HWND m_handle;
	};
}