#pragma once
#include "./Core/Common.h"
#include "./Core/Base.h"
#include <d3d11.h>
#include <wrl.h>

// This is kep in the Source folder because it is only used in the RenderSystem.cpp file and not exposed to other parts of the engine. 
// It contains the implementation details of the RenderSystem class, which is responsible for managing the rendering process, 
// including setting up the rendering pipeline, handling draw calls, and managing resources related to rendering. 
// By keeping this class in the Source folder, we can ensure that it is not accessible to other parts of the engine, 
// which helps to maintain encapsulation and reduce dependencies between different components of the engine.
namespace DX3D
{
	class RenderSystem final: public Base
	{
	public:
		explicit RenderSystem(const RenderSystemDesc& desc);
		virtual ~RenderSystem() override;

	private:
		Microsoft::WRL::ComPtr<ID3D11Device> m_d3dDevice;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_d3dContext;
	};
}
