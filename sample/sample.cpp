// sample.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include <iostream>

#include <tchar.h>

#include "define_a_global_object_in_c.h"


bool read_file_text(const char* filename, std::string& text)
{
	FILE*	file = NULL;
	
	fopen_s(&file, filename, "r");

	if (file)
	{
		fseek(file, 0, SEEK_END);

		long	length = ftell(file);

		fseek(file, 0, SEEK_SET);

		char*	buf = new char[length + 2];
		long	readed = fread(buf, 1, length, file);

		buf[readed] = buf[readed + 1] = 0;

		text = buf;

		delete[] buf;

		return true;
	}

	return false;
}

void init_context(duk_context* ctx)
{
	duk_globals_init(ctx);
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << "usage: sample.exe filename" << std::endl;

		return 0;
	}

	const char*	scriptfile = argv[1];
	std::string	script;

	if (scriptfile && *scriptfile)
		read_file_text(scriptfile, script);

	if (!script.empty())
	{
		duk_context	*ctx = duk_create_heap_default();

		if (ctx)
		{
			init_context(ctx);

			duk_push_lstring(ctx, script.c_str(), (duk_size_t)script.length());

			if (duk_peval(ctx) != 0)
			{
				std::cout << "PEVAL: " << duk_safe_to_string(ctx, -1) << std::endl;
			}

			duk_destroy_heap(ctx);
		}
	}
	else
	{
		std::cout << "Script file not found, or file is empty." << std::endl;
	}

	return 0;
}
