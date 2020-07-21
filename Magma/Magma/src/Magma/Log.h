#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Magma {

	class MAGMA_API Log {
		
	public : 
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

//Core log macros
#define MG_CORE_TRACE(...)		::Magma::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MG_CORE_INFO(...)		::Magma::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MG_CORE_WARNING(...)	::Magma::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MG_CORE_ERROR(...)		::Magma::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MG_CORE_FATAL(...)		::Magma::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define MG_TRACE(...)			::Magma::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MG_INFO(...)			::Magma::Log::GetClientLogger()->info(__VA_ARGS__)
#define MG_WARNING(...)			::Magma::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MG_ERROR(...)			::Magma::Log::GetClientLogger()->error(__VA_ARGS__)
#define MG_FATAL(...)			::Magma::Log::GetClientLogger()->fatal(__VA_ARGS__)

