#pragma once

#ifdef MG_PLATFORM_WINDOWS
	#ifdef MG_BUILD_DLL
		#define MAGMA_API __declspec(dllexport)
	#else
		#define MAGMA_API __declspec(dllimport)
	#endif
#else
	#error Magma support only Windows
#endif

#ifdef MG_ENABLE_ASSERTS
	#define MG_ASSERT(x, ...) { if(!(x)) { MG_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define MG_CORE_ASSERT(x, ...) { if(!(x)) { MG_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define MG_ASSERT(x, ...)
	#define MG_CORE_ASSERT(x, ...)

#endif