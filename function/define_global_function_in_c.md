# 在 c 中定义 js 全局函数的几种方式

- ### 方式一

  使用 duk_push_c_function() 和 duk_put_global_string() 定义：

```c
// 定义一个本地 c 函数，用于打印信息到标准输出
duk_ret_t duk_globals_function_print(duk_context *ctx)
{
	const char*	text = duk_safe_to_string(ctx, 0);

	printf("%s\n", text);

	return 0;
}

// 定义一个全局的 print 函数，可在 js 中调用本地 c 函数
// function print(text) {
//     [native code]
// }
duk_push_c_function(ctx, duk_globals_function_print, 1);
duk_put_global_string(ctx, "print");
```
​	在 js 中调用：
```javascript
// 调用 c 定义的全局函数 print
print("Hello, Duktape.");
```

- ### 方式二

  使用 duk_push_c_lightfunc() 和 duk_put_global_string() 定义：

```c
// 定义一个本地 c 函数，打印一段文本到标准输出
duk_ret_t duk_global_function_say_hey(duk_context *ctx)
{
	const char*	text = duk_safe_to_string(ctx, 0);

	printf("Hey, %s.\n", text);

	return 0;
}

// 定义一个全局的 sayHey 函数
// function sayHello(who) {
//     [native code]
// }
duk_push_c_lightfunc(ctx, duk_global_function_say_hey, 1, 0, 0);
duk_put_global_string(ctx, "sayHey");
```
​	在 js 中调用：
```javascript
// 调用 c 定义的全局函数 sayHey
sayHey("guy");
```

- ### 方式三

  使用 duk_push_global_object()、duk_push_c_function() 和 duk_put_prop_string() 定义：

```c
// 定义一个本地 c 函数，打印一段文本到标准输出
duk_ret_t duk_global_function_say_hello(duk_context *ctx)
{
	printf("Hello, I am sample.\n");

	return 0;
}

// 定义一个全局的 sayHello 函数
// function sayHello() {
//     [native code]
// }
duk_push_global_object(ctx);
duk_push_c_function(ctx, duk_global_function_say_hello, 0);
duk_put_prop_string(ctx, -2, "sayHello");
duk_pop(ctx);
```
​	在 js 中调用：
```javascript
// 调用 c 定义的全局函数 sayHello
sayHello();
```

