#pragma once
#include "stdexcept"
#include "memory"

namespace DX3D
{
	class Base;
	class Window;
	class Gaming;

	class GraphicsEngine;
	class RenderSystem;

	class Logger;
	class SwapChain;
	class Display;

	using i32 = int;
	using ui32 = unsigned int;
	using f32 = float;
	using d64 = double;

	using SwapChainPtr = std::shared_ptr<SwapChain>;
}