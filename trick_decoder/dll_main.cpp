#include <Windows.h>

#define PECONV_PROJECT_EXPORTS
#include "api.h"

#include "trick_bot.h"

//replace by your own DLL name, update "main.def"
#define LIB_NAME "PEconv Project"

//replace by your own function, update "api.h" and "main.def"
void __stdcall info(void)
{
	char info[] = "This is a string decoder for Trick Bot.\n"
		"It uses original TrickBot inside, but the malware is never executed.\n"
		"Only its function for string decoding is wrapped and exported by this DLL.";

	MessageBox(NULL, info, "PEconv Project", MB_ICONINFORMATION);
}

size_t __stdcall trick_decodeStr(char *input_str, char* out_buf, size_t out_buf_size)
{
	TrickBotWrapper trickBot;
	if (!trickBot.loadRes()) {
		std::cerr << "Failed to load the bot" << std::endl;
		return 0;
	}
	if (trickBot.decodeString(input_str, out_buf, out_buf_size) > 0) {
		std::cout << out_buf << std::endl;
	} else {
		std::cerr << "Failed to decode the string" << std::endl;
	}
	return 0;
}

BOOL WINAPI DllMain (HANDLE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	switch (fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}
