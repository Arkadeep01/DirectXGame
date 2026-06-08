#include <Graphics/GraphicsEngine.h>
#include "RenderSystem.h"

using namespace DX3D;
DX3D::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc): Base(desc.base)
{
	// We are implementing the constructor of the GraphicsEngine class, which is responsible for initializing the graphics engine.
	m_renderSystem = std::make_shared<RenderSystem>(RenderSystemDesc{m_logger});
}

DX3D::GraphicsEngine::~GraphicsEngine()
{
}

RenderSystem& DX3D::GraphicsEngine::getRenderSystem() const noexcept
{
	return *m_renderSystem;
}
