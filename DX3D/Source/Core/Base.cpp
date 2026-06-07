#include <Core/Base.h>
using namespace DX3D;

DX3D::Base::Base(const BaseDesc& desc) : m_logger(desc.logger)
{
}

DX3D::Base::~Base()
{
}

Logger& DX3D::Base::getLogger() const noexcept
{
	return m_logger;
}
