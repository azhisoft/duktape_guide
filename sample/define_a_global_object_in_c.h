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
	// 定义一个全局的 print 函数，可在 js 中调用本地 c 函数
	duk_push_c_function(ctx, duk_globals_function_print, 1);
	duk_put_global_string(ctx, "print");

	// 定义一个全局的 AppName 常量，在 js 中不可修改
	duk_push_global_object(ctx);
	duk_push_string(ctx, "AppName");
	duk_push_string(ctx, "sample");
	duk_def_prop(ctx, -3, DUK_DEFPROP_HAVE_VALUE);

	// 定义一个全局的 Major 变量，可在 js 中修改变量值
	duk_push_global_object(ctx);
	duk_push_string(ctx, "Major");
	duk_push_int(ctx, 1);
	duk_def_prop(ctx, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | DUK_DEFPROP_WRITABLE);

	// 定义一个全局的 Minor 变量，可在 js 中修改变量值
	duk_push_global_object(ctx);
	duk_push_string(ctx, "Minor");
	duk_push_int(ctx, 0);
	duk_def_prop(ctx, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | DUK_DEFPROP_WRITABLE);

	// 定义全局变量的另一种便捷方式
	duk_push_string(ctx, "1.0.0.0");
	duk_put_global_string(ctx, "Version");
}
