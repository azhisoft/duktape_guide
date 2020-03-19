# 在 c 中定义一个 js 全局数组

- ### 定义一个 int 数组

```c
// 定义一个全局的 int 数组
duk_int_t	idx = duk_push_array(ctx);

duk_push_int(ctx, 100);
duk_put_prop_index(ctx, idx, 0);
duk_push_int(ctx, 157);
duk_put_prop_index(ctx, idx, 1);
duk_push_int(ctx, 54);
duk_put_prop_index(ctx, idx, 2);

duk_put_global_string(ctx, "Array1");
```
​	在 js 中调用：
```javascript
// 访问 c 定义的全局数组，并尝试添加值
Array1.push(1000);

for(var i = 0; i < Array1.length; i ++) {
	print("Array1[" + i + "]: " + Array1[i]);
}
```
- ### 定义一个 string 数组

```c
// 定义一个全局的 string 数组
duk_push_global_object(ctx);
duk_int_t	idx = duk_push_array(ctx);

duk_push_string(ctx, "Hello");
duk_put_prop_index(ctx, idx, 0);
duk_push_string(ctx, ",");
duk_put_prop_index(ctx, idx, 1);
duk_push_string(ctx, "array");
duk_put_prop_index(ctx, idx, 2);

duk_put_prop_string(ctx, -2, "Array2");
duk_pop(ctx);
```
​	在 js 中调用：
```javascript
// 访问 c 定义的全局数组，并尝试添加值
Array2.push(".");

print("Array2: " + JSON.stringify(Array2));
```
- ### 定义一个数组的数组

```c
// 定义一个全局的数组数组
duk_push_global_object(ctx);
duk_int_t	idx = duk_push_array(ctx);

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
```
​	在 js 中调用：
```javascript
// 访问 c 定义的全局数组
for(var i = 0; i < Array3.length; i ++) {
	print("Array3[" + i + "]: " + JSON.stringify(Array3[i]));
}
```

- ### 定义一个对象数组

```c
// 定义一个全局的对象数组
duk_push_global_object(ctx);
duk_int_t	idx = duk_push_array(ctx);

duk_int_t	sidx = duk_push_object(ctx);

duk_push_int(ctx, 1);
duk_put_prop_string(ctx, sidx, "id");
duk_push_string(ctx, "duktape");
duk_put_prop_string(ctx, sidx, "name");
duk_push_string(ctx, "2.3.0");
duk_put_prop_string(ctx, sidx, "version");

duk_put_prop_index(ctx, idx, 0);

sidx = duk_push_object(ctx);

duk_push_int(ctx, 1);
duk_put_prop_string(ctx, sidx, "id");
duk_push_string(ctx, "v8");
duk_put_prop_string(ctx, sidx, "name");
duk_push_string(ctx, "1.0");
duk_put_prop_string(ctx, sidx, "version");

duk_put_prop_index(ctx, idx, 1);

duk_put_prop_string(ctx, -2, "Array4");
duk_pop(ctx);
```
​	在 js 中调用：
```javascript
// 访问 c 定义的全局数组
for(var i = 0; i < Array4.length; i ++) {
	print("Array4[" + i + "]: " + JSON.stringify(Array4[i]));
}
```

