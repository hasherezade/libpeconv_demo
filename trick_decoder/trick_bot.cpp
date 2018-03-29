#include "trick_bot.h"
#include "resource.h"

/*
using original, unpacked trickbot: 0a7da84873f2a4fe0fcc58c88bbbe39d
10ab0,decode_from_the_list
10b30,decode_string
1EC24;enc_string_list
*/

bool TrickBotWrapper::loadRes()
{
	size_t raw_size = 0;
	BYTE *raw_crackme = peconv::load_resource_data(raw_size, TRICK_LDR_32, RT_RCDATA, peconv::get_current_module_handle());
	if (!raw_crackme) {
		std::cerr << "Failed to load the resource!" << std::endl;
		return false;
	}
	bool is_ok = this->load(raw_crackme, raw_size);
	peconv::free_resource_data(raw_crackme);
	return is_ok;
}

bool TrickBotWrapper::load(BYTE *raw_buffer, size_t raw_size)
{
	this->malware = peconv::load_pe_executable(raw_buffer, raw_size, this->vMalwareSize);
	if (!malware) {
		return false;
	}
	ULONGLONG func_offset = (ULONGLONG)malware + 0x10b30;
	decode_str = (int (__cdecl *) (char*, char*)) func_offset;
	return true;
}

int TrickBotWrapper::decodeString(char* input_buf, char *output_buf, size_t output_buf_size)
{
	if (this->malware == nullptr) return 0;
	if (decode_str == nullptr) return 0;
	if (input_buf == nullptr || output_buf == nullptr) return 0;

	size_t len = strlen(input_buf);
	if (output_buf_size < len) {
		std::cerr << "Too small output buffer!" << std::endl;
		return 0;
	}
	memset(output_buf, 0, output_buf_size);
	return decode_str(input_buf, output_buf);
}
