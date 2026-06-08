#include <Game/Gaming.h>
#include <Windows.h>
#include <Graphics/GraphicsEngine.h>
#include <Core/Logger.h>
#include <Game/Display.h>

DX3D::Gaming::Gaming(const GameDesc& desc) :
	Base({*std::make_unique<Logger>(desc.logLevel ).release()}),
	m_loggerPtr(&m_logger)
{
	// Logger is the First Attribute
	m_graphicsEngine = std::make_unique<GraphicsEngine>(GraphicsEngineDesc{ BaseDesc{m_logger} });
	m_display = std::make_unique<Display>(DisplayDesc{ {m_logger, desc.windowSize}, m_graphicsEngine->getRenderSystem() });

	DX3DLogInfo("Game Initiated...");
}

DX3D::Gaming::~Gaming()
{
	DX3DLogInfo("Game Deallocation Started...");
}