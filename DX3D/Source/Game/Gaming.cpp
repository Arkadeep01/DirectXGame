#include <Game/Gaming.h>
#include <Windows.h>

DX3D::Gaming::Gaming()
{
	m_display = std::make_unique<Window>();
}

DX3D::Gaming::~Gaming()
{
}