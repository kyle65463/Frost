#pragma once

#include "core.h"
#include "spdlog/spdlog.h"

namespace Frost {

	class FROST_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core macros
#define FS_CORE_TRACE(...)    ::Frost::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FS_CORE_INFO(...)     ::Frost::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FS_CORE_WARN(...)     ::Frost::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FS_CORE_ERROR(...)    ::Frost::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FS_CORE_CRITICAL(...) ::Frost::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client macros
#define FS_TRACE(...)         ::Frost::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FS_INFO(...)          ::Frost::Log::GetClientLogger()->info(__VA_ARGS__)
#define FS_WARN(...)          ::Frost::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FS_ERROR(...)         ::Frost:Log::GetClientLogger()->error(__VA_ARGS__)
#define FS_CRITICAL(...)      ::Frost::Log::GetClientLogger()->critical(__VA_ARGS__)