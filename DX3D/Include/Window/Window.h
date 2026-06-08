#pragma once
#include <Core/Base.h>
#include <Windows.h>
#include <Core/Common.h>

namespace DX3D
{
	class Window : public Base
	{
	public:
		explicit Window(const WindowDesc& desc);
		virtual ~Window() override;

	protected:
		HWND m_handle;
		Rect m_size{};
	};
}