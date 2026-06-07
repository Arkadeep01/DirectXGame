#pragma once
#include "Logger.h"
#include "Common.h"

namespace DX3D
{
	class Base
	{
	public:
		explicit Base(const BaseDesc& desc);
		virtual ~Base();
		virtual Logger& getLogger() const noexcept final;

	protected:
		Base(const Base&) = delete;
		Base(Base&&) = delete;
		Base& operator = (const Base&) = delete;
		Base& operator = (Base&&) = delete;

	protected:
		Logger& m_logger;

	};
}

