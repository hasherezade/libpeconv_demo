#include <stdio.h>
#include <windows.h>

#include "peconv.h"
#include "trick_bot.h"

TrickBotWrapper *trickBot = nullptr;

size_t decodeStr(char *input_str, char* out_buf, size_t out_buf_size)
{
	if (trickBot == nullptr) {
		//init default bot from the resources
		t_offsets config = { 0 };
		config.stringDecodeRVA = TRICK_DEFAULT_RVA;
		trickBot = new TrickBotWrapper(config);
		if (!trickBot->loadRes()) {
			std::cerr << "Failed to load the bot" << std::endl;
			return 0;
		}
	}
	if (trickBot->decodeString(input_str, out_buf, out_buf_size) > 0) {
		std::cout << out_buf << std::endl;
	} else {
		std::cerr << "[-] Failed to decode the string" << std::endl;
	}
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Args: <string to decode>" << std::endl;
		system("pause");
		return 0;
	}
	
	size_t v_size = 0;

	char* input_str = nullptr;
	if (argc >= 2) {
		input_str = argv[1];
	}
	char out_buf[0x1000] = { 0 };
	decodeStr(input_str, out_buf, sizeof(out_buf));

	system("pause");

	return 0;
}
