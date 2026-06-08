#pragma once
#include <Window/Window.h>
#include <Core/Core.h>

namespace DX3D
{
	class Display final: public Window
	{
	public:
		explicit Display(const DisplayDesc& desc);

	private:
		SwapChainPtr m_swapChain;
	};
}
