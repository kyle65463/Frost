#pragma once

#ifdef FS_PLATFORM_WINDOWS
	#ifdef FS_BUILD_DLL
		#define FROST_API __declspec(dllexport)
	#else
		#define FROST_API __declspec(dllimport)
#endif
#else
	#error Only support Windows
#endif