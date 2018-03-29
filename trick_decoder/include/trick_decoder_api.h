#pragma once

#include <Windows.h>

#include "types.h"

#ifdef PECONV_PROJECT_EXPORTS
#define PECONV_PROJECT_API __declspec(dllexport)
#else
#define PECONV_PROJECT_API __declspec(dllimport)
#endif

extern "C" {
	void PECONV_PROJECT_API __stdcall info(void);

	bool PECONV_PROJECT_API __stdcall trick_init_ctx(char *filepath, t_offsets config);
	bool PECONV_PROJECT_API __stdcall trick_release_ctx();

	size_t PECONV_PROJECT_API __stdcall trick_decodeStr(char *input_str, char* out_buf, size_t out_buf_size);
};
