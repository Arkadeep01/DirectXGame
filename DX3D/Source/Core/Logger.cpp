#include <Core/Logger.h>
#include <iostream>

DX3D::Logger::Logger(LogLevel logLevel) : m_logLevel(logLevel)
{
	std::clog << "Vertex Horizon || C++ 3D Game" << "\n";
}

void DX3D::Logger::log(LogLevel level, const char* message) const
{
	auto logLevelToString = [](LogLevel level)
		{
			switch (level)
			{
			case DX3D::Logger::LogLevel::Error:
				return "ERROR";
			case DX3D::Logger::LogLevel::Warning:
				return "WARNING";
			case DX3D::Logger::LogLevel::Info:
				return "INFO";
			default:
				return "UNKNOWN";
			}
		};

	if (level > m_logLevel) return;
	std::clog << "[DX3D " << logLevelToString(level) << "]:" << message << "\n";
}
