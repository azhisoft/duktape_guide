# 在 c 中定义一个 js 全局常/变量

- ### 定义常量

```c
// 定义一个全局的 AppName 常量，在 js 中不可修改
// const AppName = "sample";
duk_push_global_object(ctx);
duk_push_string(ctx, "AppName");
duk_push_string(ctx, "sample");
duk_def_prop(ctx, -3, DUK_DEFPROP_HAVE_VALUE);
```
​	在 js 中调用：
```javascript
// 访问 c 定义的全局常量，并尝试修改常量值
print("AppName: " + AppName);
AppName = "Hello, " + AppName;
print("AppName(new): " + AppName);
```

- ### 定义变量

```c
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
```
​	在 js 中调用：
```javascript
// 访问 c 定义的全局变量，并尝试修改变量值
print("Version: " + Major + "." + Minor);
Major ++; Minor ++;
print("Version(new): " + Major + "." + Minor);

print("Full version: " + Version);
Version = "v" + Version;
print("Full version(new): " + Version);
```

- ### 绑定本地 c 变量的全局变量

```c
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

// 定义 js 全局变量的另一种方式，允许 js 直接访问本地 c 变量
// var NatvieVar;
duk_push_global_object(ctx);
duk_push_string(ctx, "NativeVar");
duk_push_c_function(ctx, duk_globals_function_get_native_var, 0);
duk_push_c_function(ctx, duk_globals_function_set_native_var, 1);
duk_def_prop(ctx, -4, DUK_DEFPROP_HAVE_GETTER | DUK_DEFPROP_HAVE_SETTER);
```
​	在 js 中调用：
```javascript
// 访问 c 定义的全局常量，并尝试修改常量值
print("NativeVar: " + NativeVar);
NativeVar += 10;
print("NativeVar(new): " + NativeVar);
```

