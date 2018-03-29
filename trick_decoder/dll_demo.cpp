//this is just a snippet showing how the DLL can be applied in a separate project

#include <Windows.h>
#include <iostream>

#include "trick_decoder_api.h"
#pragma comment(lib, "trick_decoder.lib")

void main()
{
	char out_buf[0x1000] = { 0 };
	char input_str[] = "NJI1vHuq5HuFyY48zb21fQdKYQUCvHul5kdWyd46zJIA5aUWvr";

	t_offsets config = { 0 };
	config.stringDecodeRVA = 0x10b30;

	trick_init_ctx("C:\\tests\\0a7da84873f2a4fe0fcc58c88bbbe39d.mwr", config);
	size_t len = trick_decodeStr(input_str, out_buf, sizeof(out_buf));
	trick_release_ctx();

	config.stringDecodeRVA = 0xa62c;
	trick_init_ctx("C:\\tests\\329618825e8047eb7ebfd0523383f44c.mwr", config);
	len = trick_decodeStr("Eq22wIu9gUcFQvK9MINRsIKFUb+aWOuL86", out_buf, sizeof(out_buf));

	system("pause");
}