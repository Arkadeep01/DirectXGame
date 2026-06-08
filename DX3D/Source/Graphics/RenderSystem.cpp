#include "RenderSystem.h"
#include "GraphicsLogUtils.h"
#include "SwapChain.h"

using namespace DX3D;
DX3D::RenderSystem::RenderSystem(const RenderSystemDesc& desc): Base(desc.base)
{
	// We are implementing the constructor of the RenderSystem class, which is responsible for initializing the rendering system.
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	DX3DGraphicsLogErrorAndThrow(D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0, D3D11_SDK_VERSION, &m_d3dDevice, &featureLevel, &m_d3dContext), 
		"Direct3D11 Initialization Failed.");

	DX3DGraphicsLogErrorAndThrow(m_d3dDevice->QueryInterface(IID_PPV_ARGS(&m_dxgiDevice)),
		"QueryInterface Failed to retrieve IDXGI-Device.");

	DX3DGraphicsLogErrorAndThrow(m_dxgiDevice->GetParent(IID_PPV_ARGS(&m_dxgiAdapter)),
		"GetParent Failed to retrieve IDXGI-Adapter.");
	
	DX3DGraphicsLogErrorAndThrow(m_dxgiAdapter->GetParent(IID_PPV_ARGS(&m_dxgiFactory)),
		"GetParent Failed to retrieve IDXGI-Factory.");
}

DX3D::RenderSystem::~RenderSystem()
{
}

SwapChainPtr DX3D::RenderSystem::createSwapChain(const SwapChainDesc& desc) const
{
	return std::make_shared<SwapChain>(desc, getGraphicsResourceDesc()) ;
}

GraphicsResourceDesc DX3D::RenderSystem::getGraphicsResourceDesc() const noexcept
{
	return { {m_logger}, shared_from_this(), *m_d3dDevice.Get(), *m_dxgiFactory.Get() };
}
