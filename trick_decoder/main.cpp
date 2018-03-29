#include <stdio.h>
#include <windows.h>

#include "peconv.h"
#include "trick_bot.h"

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Args: <string to decode>" << std::endl;
		system("pause");
		return 0;
	}

	size_t v_size = 0;
	char* mal_path = argv[1];
	
	char* input_str = nullptr;
	if (argc >= 2) {
		input_str = argv[1];
	}
	TrickBotWrapper trickBot;
	if (!trickBot.loadRes()) {
		std::cerr << "Failed to load the bot" << std::endl;
		return -1;
	}
	char out_buf[0x1000] = { 0 };
	if (trickBot.decodeString(input_str, out_buf, sizeof(out_buf)) > 0) {
		std::cout <<out_buf << std::endl;
	} else {
		std::cerr << "Failed to decode the string" << std::endl;
	}
	return 0;
}
