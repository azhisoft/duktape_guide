# 在 c 中定义 js 全局函数的几种方式

- ### 还是 print()

```c
// 定义一个本地 c 函数，用于打印信息到标准输出
duk_ret_t duk_globals_function_print(duk_context *ctx)
{
	const char*	text = duk_safe_to_string(ctx, 0);

	std::cout << text << std::endl;

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

- ### 看看 sayHello()

```c
// 定义一个本地 c 函数，打印一段文本到标准输出
duk_ret_t duk_global_function_say_hello(duk_context *ctx)
{
	std::cout << "Hello, I am sample." << std::endl;

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

- ### 看看 sayHello

```c
// 定义一个本地 c 函数，打印一段文本到标准输出
duk_ret_t duk_global_function_say_hello(duk_context *ctx)
{
	std::cout << "Hello, I am sample." << std::endl;

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
