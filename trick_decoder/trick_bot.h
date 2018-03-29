#include <stdio.h>
#include <windows.h>

#include "peconv.h"

#include "include\types.h"

//RVA to the function of the default bot that is in the resources
#define TRICK_DEFAULT_RVA 0x10b30 

class TrickBotWrapper
{
public:
	TrickBotWrapper(t_offsets _config)
		: config(_config), malware(nullptr), vMalwareSize(0)
	{
		decode_str = nullptr;
	}

	~TrickBotWrapper()
	{
		peconv::free_pe_buffer(malware, vMalwareSize);
	}

	int decodeString(char* input_buf, char *output_buf, size_t output_buf_size);
	
	bool loadRes();

	bool loadFile(char *path);

protected:
	bool load(BYTE *raw_buffer, size_t raw_size);

	t_offsets config;

	BYTE *malware;
	size_t vMalwareSize;

	int (__cdecl *decode_str)(char* input_buf, char *output_buf);
};
