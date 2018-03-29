#include <stdio.h>
#include <windows.h>

#include "peconv.h"

class TrickBotWrapper
{
public:
	TrickBotWrapper()
	{
		malware = nullptr;
		vMalwareSize = 0;

		decode_str = nullptr;
	}

	~TrickBotWrapper()
	{
		peconv::free_pe_buffer(malware, vMalwareSize);
	}

	int decodeString(char* input_buf, char *output_buf, size_t output_buf_size);
	
	bool loadRes();

protected:
	bool load(BYTE *raw_buffer, size_t raw_size);

	BYTE *malware;
	size_t vMalwareSize;

	int (__cdecl *decode_str)(char* input_buf, char *output_buf);
};
