#include <Game/Gaming.h>
#include <Windows.h>
#include <Graphics/GraphicsEngine.h>
#include <Core/Logger.h>

DX3D::Gaming::Gaming(const GameDesc& desc) :
	Base({*std::make_unique<Logger>(desc.logLevel ).release()}),
	m_loggerPtr(&m_logger)
{
	// Logger is the First Attribute
	m_graphicsEngine = std::make_unique<GraphicsEngine>(GraphicsEngineDesc{ BaseDesc{m_logger} });
	m_display = std::make_unique<Window>(WindowDesc{BaseDesc{m_logger}});

	m_loggerPtr->log(Logger::LogLevel::Info, "Game Initiated...");
}

DX3D::Gaming::~Gaming()
{
	m_loggerPtr->log(Logger::LogLevel::Info, "Game Deallocation Started...");
}