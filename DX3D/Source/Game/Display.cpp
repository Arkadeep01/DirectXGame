#include <Game/Display.h>
#include "../Graphics/RenderSystem.h"

DX3D::Display::Display(const DisplayDesc& desc): Window(desc.window)
{
	m_swapChain = desc.renderSystem.createSwapChain({ m_handle, m_size });
}

