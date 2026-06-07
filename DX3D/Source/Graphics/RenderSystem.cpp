#include "RenderSystem.h"

DX3D::RenderSystem::RenderSystem(const RenderSystemDesc& desc): Base(desc.base)
{
	// We are implementing the constructor of the RenderSystem class, which is responsible for initializing the rendering system.
	D3D_FEATURE_LEVEL featureLevel{};
	UINT createDeviceFlags{};

#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	auto hr = D3D11CreateDevice(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, createDeviceFlags, NULL, 0, D3D11_SDK_VERSION, &m_d3dDevice, &featureLevel, &m_d3dContext);

	if (FAILED(hr))
	{
		getLogger().log(Logger::LogLevel::Error, "Direct3D11 Initialization Failed.");
		throw std::runtime_error("Failed to create D3D11 device and context.");
	}}

DX3D::RenderSystem::~RenderSystem()
{
}
