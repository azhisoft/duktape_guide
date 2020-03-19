// sample.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include <iostream>

#include <tchar.h>

#include "duktape_2.3.0/duktape.h"


// 定义一个本地 c 函数，打印一段文本到标准输出
duk_ret_t duk_global_function_say_hello(duk_context *ctx)
{
	std::cout << "Hello, I am sample." << std::endl;

	return 0;
}

void duk_function_init(duk_context* ctx)
{
	// 定义一个全局的 sayHello 函数
	// function sayHello() {
	//     [native code]
	// }
	duk_push_global_object(ctx);
	duk_push_c_function(ctx, duk_global_function_say_hello, 0);
	duk_put_prop_string(ctx, -2, "sayHello");
	duk_pop(ctx);
}
