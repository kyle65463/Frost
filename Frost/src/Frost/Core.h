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

#define BIT(x) (1 << x)