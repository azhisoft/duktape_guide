// sample.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include <iostream>

#include <tchar.h>

#include "duktape_2.3.0/duktape.h"


duk_ret_t duk_globals_function_print(duk_context *ctx)
{
	const char*	text = duk_safe_to_string(ctx, 0);

	std::cout << text << std::endl;

	return 0;
}

void duk_globals_init(duk_context* ctx)
{
	duk_push_string(ctx, "sample");
	duk_put_global_string(ctx, "appname");

	duk_push_c_function(ctx, duk_globals_function_print, 1);
	duk_put_global_string(ctx, "print");
}
