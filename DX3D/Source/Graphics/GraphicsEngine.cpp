#include <Graphics/GraphicsEngine.h>
#include "RenderSystem.h"

DX3D::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& desc): Base(desc.base)
{
	// We are implementing the constructor of the GraphicsEngine class, which is responsible for initializing the graphics engine.
	m_renderSystem = std::make_unique<RenderSystem>(RenderSystemDesc{m_logger});
}

DX3D::GraphicsEngine::~GraphicsEngine()
{
}
