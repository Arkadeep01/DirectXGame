#pragma once
#include <Core/Base.h>
#include <Core/Core.h>
#include <Window/Window.h> 

namespace DX3D
{
	class Gaming : public Base
	{
	public:
		explicit Gaming(const GameDesc& desc);
		virtual ~Gaming() override;

		virtual void run() final;

	private:
		// Creating the Unique pointer for the logger.
		std::unique_ptr<Logger> m_loggerPtr{};

		// Initating the Graphics Engine in the Gaming class, 
		// which is responsible for managing the graphics rendering pipeline and related resources.
		std::unique_ptr<GraphicsEngine> m_graphicsEngine{};

		// This function keeps the game window into the Gaming Loop.
		std::unique_ptr<Window> m_display{};
		bool GameisRunning{ true };
	};
}
