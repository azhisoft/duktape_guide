# 在 c 中定义一个 js 全局常/变量

- ### 定义一个常量

```c
// 定义一个全局的 AppName 常量，在 js 中不可修改
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

