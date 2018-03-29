#pragma once

#include <Windows.h>

#ifdef PECONV_PROJECT_EXPORTS
#define PECONV_PROJECT_API __declspec(dllexport)
#else
#define PECONV_PROJECT_API __declspec(dllimport)
#endif

extern "C" {
	void PECONV_PROJECT_API __stdcall info(void);
	size_t PECONV_PROJECT_API __stdcall trick_decodeStr(char *input_str, char* out_buf, size_t out_buf_size);
};
