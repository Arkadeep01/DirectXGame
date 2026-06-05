#pragma once
#include <Core/Base.h>
#include <Core/Core.h>
#include <Window/Window.h> 

namespace DX3D
{
	class Gaming : public Base
	{
	public:
		Gaming();
		virtual ~Gaming() override;

		virtual void run() final;

	private:
		std::unique_ptr<Window> m_display{};
		bool GameisRunning{ true };
	};
}
