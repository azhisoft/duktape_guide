﻿// sample.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"

#include <tchar.h>

#include "duktape_2.3.0/duktape.h"


// 定义一个本地 c 函数，用于打印信息到标准输出
duk_ret_t duk_globals_function_print(duk_context *ctx)
{
	const char*	text = duk_safe_to_string(ctx, 0);

	printf("%s\n", text);

	return 0;
}

// 定义一个本地 c 变量
int		native_var = 0;

// 当 js 取变量值时，返回本地 c 变量的值
duk_ret_t duk_globals_function_get_native_var(duk_context *ctx)
{
	duk_push_int(ctx, native_var);

	return 1;
}

// 当 js 为变量赋值时，更新本地 c 变量的值
duk_ret_t duk_globals_function_set_native_var(duk_context *ctx)
{
	native_var = duk_to_int(ctx, 0);

	return 0;
}

void duk_globals_init(duk_context* ctx)
{
	// 快速定义一个全局的 print 函数
	// function print(text) {
	//     [native code]
	// }
	duk_push_c_function(ctx, duk_globals_function_print, 1);
	duk_put_global_string(ctx, "print");

	// 定义一个全局的 AppName 常量，在 js 中不可修改
	// const AppName = "sample";
	duk_push_global_object(ctx);
	duk_push_string(ctx, "AppName");
	duk_push_string(ctx, "sample");
	duk_def_prop(ctx, -3, DUK_DEFPROP_HAVE_VALUE);

	// 定义一个全局的 Major 变量，可在 js 中修改变量值
	// var Major = 1;
	duk_push_global_object(ctx);
	duk_push_string(ctx, "Major");
	duk_push_int(ctx, 1);
	duk_def_prop(ctx, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | DUK_DEFPROP_WRITABLE);

	// 定义一个全局的 Minor 变量，可在 js 中修改变量值
	// var Minor = 0;
	duk_push_global_object(ctx);
	duk_push_string(ctx, "Minor");
	duk_push_int(ctx, 0);
	duk_def_prop(ctx, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | DUK_DEFPROP_WRITABLE);

	// 定义全局变量的另一种便捷方式
	// var Version = "1.0.0.0";
	duk_push_string(ctx, "1.0.0.0");
	duk_put_global_string(ctx, "Version");

	// 定义 js 全局变量的另一种方式，允许 js 直接访问本地 c 变量
	// var NativeVar;
	duk_push_global_object(ctx);
	duk_push_string(ctx, "NativeVar");
	duk_push_c_function(ctx, duk_globals_function_get_native_var, 0);
	duk_push_c_function(ctx, duk_globals_function_set_native_var, 1);
	duk_def_prop(ctx, -4, DUK_DEFPROP_HAVE_GETTER | DUK_DEFPROP_HAVE_SETTER);

	// 定义一个全局的 int 数组
	// var Array1 = [ 100, 157, 54 ];
	duk_int_t	idx = duk_push_array(ctx);

	duk_push_int(ctx, 100);
	duk_put_prop_index(ctx, idx, 0);
	duk_push_int(ctx, 157);
	duk_put_prop_index(ctx, idx, 1);
	duk_push_int(ctx, 54);
	duk_put_prop_index(ctx, idx, 2);

	duk_put_global_string(ctx, "Array1");

	// 定义一个全局的 string 数组
	// var Array2 = [ "Hello", ",", "array" ];
	duk_push_global_object(ctx);
	idx = duk_push_array(ctx);

	duk_push_string(ctx, "Hello");
	duk_put_prop_index(ctx, idx, 0);
	duk_push_string(ctx, ",");
	duk_put_prop_index(ctx, idx, 1);
	duk_push_string(ctx, "array");
	duk_put_prop_index(ctx, idx, 2);

	duk_put_prop_string(ctx, -2, "Array2");
	duk_pop(ctx);

	// 定义一个全局的数组数组
	// var Array3 = [
	//     [ "Hello", ",", "sub", "array", "." ],
	//     [ 100, 157, 54 ]
	// ];
	duk_push_global_object(ctx);
	idx = duk_push_array(ctx);

	duk_int_t	sidx = duk_push_array(ctx);

	duk_push_string(ctx, "Hello");
	duk_put_prop_index(ctx, sidx, 0);
	duk_push_string(ctx, ",");
	duk_put_prop_index(ctx, sidx, 1);
	duk_push_string(ctx, "sub");
	duk_put_prop_index(ctx, sidx, 2);
	duk_push_string(ctx, "array");
	duk_put_prop_index(ctx, sidx, 3);
	duk_push_string(ctx, ".");
	duk_put_prop_index(ctx, sidx, 4);

	duk_put_prop_index(ctx, idx, 0);

	sidx = duk_push_array(ctx);

	duk_push_int(ctx, 100);
	duk_put_prop_index(ctx, sidx, 0);
	duk_push_int(ctx, 157);
	duk_put_prop_index(ctx, sidx, 1);
	duk_push_int(ctx, 54);
	duk_put_prop_index(ctx, sidx, 2);

	duk_put_prop_index(ctx, idx, 1);

	duk_put_prop_string(ctx, -2, "Array3");
	duk_pop(ctx);

	// 定义一个全局的对象数组
	// var Array4 = [
	//     { id: 1, name: "duktape", version: "2.3.0" },
	//     { id: 2, name: "v8", version: "1.0" }
	// ];
	duk_push_global_object(ctx);
	idx = duk_push_array(ctx);

	sidx = duk_push_object(ctx);

	duk_push_int(ctx, 1);
	duk_put_prop_string(ctx, sidx, "id");
	duk_push_string(ctx, "duktape");
	duk_put_prop_string(ctx, sidx, "name");
	duk_push_string(ctx, "2.3.0");
	duk_put_prop_string(ctx, sidx, "version");

	duk_put_prop_index(ctx, idx, 0);

	sidx = duk_push_object(ctx);

	duk_push_int(ctx, 2);
	duk_put_prop_string(ctx, sidx, "id");
	duk_push_string(ctx, "v8");
	duk_put_prop_string(ctx, sidx, "name");
	duk_push_string(ctx, "1.0");
	duk_put_prop_string(ctx, sidx, "version");

	duk_put_prop_index(ctx, idx, 1);

	duk_put_prop_string(ctx, -2, "Array4");
	duk_pop(ctx);

	// 定义一个全局的简单对象
	// var Object1 = {
	//     id: 1,
	//     name: "duktape",
	//     version: "2.3.0"
	// };
	duk_push_global_object(ctx);
	idx = duk_push_object(ctx);

	duk_push_int(ctx, 1);
	duk_put_prop_string(ctx, idx, "id");
	duk_push_string(ctx, "duktape");
	duk_put_prop_string(ctx, idx, "name");
	duk_push_string(ctx, "2.3.0");
	duk_put_prop_string(ctx, idx, "version");

	duk_put_prop_string(ctx, -2, "Object1");
	duk_pop(ctx);

	// 定义一个全局的复合对象
	// var Object1 = {
	//     id: 1,
	//     name: "duktape",
	//     version: "2.3.0",
	//     supportedOS: [ "Windows", "Linux", "MacOS", "RTOS" ],
	//     latestVersion: {
	//         id: 1,
	//         name: "duktape",
	//         version: "2.3.0"
	//     }
	// };
	duk_push_global_object(ctx);
	idx = duk_push_object(ctx);

	duk_push_int(ctx, 1);
	duk_put_prop_string(ctx, idx, "id");
	duk_push_string(ctx, "duktape");
	duk_put_prop_string(ctx, idx, "name");
	duk_push_string(ctx, "2.3.0");
	duk_put_prop_string(ctx, idx, "version");

	sidx = duk_push_array(ctx);

	duk_push_string(ctx, "Windows");
	duk_put_prop_index(ctx, sidx, 0);
	duk_push_string(ctx, "Linux");
	duk_put_prop_index(ctx, sidx, 1);
	duk_push_string(ctx, "MacOS");
	duk_put_prop_index(ctx, sidx, 2);
	duk_push_string(ctx, "RTOS");
	duk_put_prop_index(ctx, sidx, 3);
	duk_push_string(ctx, "etc.");
	duk_put_prop_index(ctx, sidx, 4);

	duk_put_prop_string(ctx, idx, "supportedOS");

	sidx = duk_push_object(ctx);

	duk_push_int(ctx, 1);
	duk_put_prop_string(ctx, sidx, "id");
	duk_push_string(ctx, "duktape");
	duk_put_prop_string(ctx, sidx, "name");
	duk_push_string(ctx, "2.3.0");
	duk_put_prop_string(ctx, sidx, "version");

	duk_put_prop_string(ctx, idx, "latestVersion");

	duk_put_prop_string(ctx, -2, "Object2");
	duk_pop(ctx); 
}
