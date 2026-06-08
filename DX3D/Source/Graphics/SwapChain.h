#pragma once
#include "GraphicsResource.h"

namespace DX3D
{
	class SwapChain final: public GraphicsResource
	{
	public:
		SwapChain(const SwapChainDesc& desc, const GraphicsResourceDesc& gdesc);

	private:
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain{};
	};
}


