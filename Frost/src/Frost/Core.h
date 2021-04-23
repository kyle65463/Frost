#pragma once

#ifdef FS_PLATFORM_WINDOWS
#ifdef FS_BUILD_DLL
#define FROST_API __declspec(dllexport)
#else
#define FROST_API __declspec(dllimport)
#endif
#elif FS_PLATFORM_MACOSX
#define FROST_API
#else
#define FROST_API
#endif

#define FS_ASSERT(x, ...)                                   \
	{                                                       \
		if (!(x))                                           \
		{                                                   \
			FS_ERROR("Assertion failed: {0}", __VA_ARGS__); \
		}                                                   \
	}
#define FS_CORE_ASSERT(x, ...)                                   \
	{                                                            \
		if (!(x))                                                \
		{                                                        \
			FS_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); \
		}                                                        \
	}

#define BIT(x) (1 << x)

#define FS_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)