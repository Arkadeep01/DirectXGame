#pragma once
#include "./Core/Core.h"
#include "../Core/Base.h"

namespace DX3D
{
	// We are implementing the GraphicsEngine class, which is responsible for managing the graphics rendering pipeline and related resources.
	// Final is used so that no other class can inherit from GraphicsEngine, ensuring that its implementation remains unchanged and preventing unintended modifications through inheritance.
	class GraphicsEngine final : public Base
	{
	public:
		explicit GraphicsEngine(const GraphicsEngineDesc& desc);
		virtual ~GraphicsEngine() override;

	private:
		std::unique_ptr<RenderSystem> m_renderSystem{};
	};

}

