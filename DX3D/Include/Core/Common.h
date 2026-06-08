#pragma once
#include "Core.h"
#include "Logger.h"
#include "Math/Rect.h"

namespace DX3D
{
	struct BaseDesc
	{
		Logger& logger;
	};

	struct WindowDesc
	{
		BaseDesc base;
		Rect size{};
	};

	struct DisplayDesc
	{
		WindowDesc window;
		RenderSystem& renderSystem;
	};

	struct GraphicsEngineDesc
	{
		BaseDesc base;
	};
	struct RenderSystemDesc
	{
		BaseDesc base;
	};
	struct GameDesc
	{
		Rect windowSize{ 1280, 720 };
		Logger::LogLevel logLevel = Logger::LogLevel::Error;
	};

	struct SwapChainDesc
	{
		void* winHandle{};
		Rect winSize{};
	};
}