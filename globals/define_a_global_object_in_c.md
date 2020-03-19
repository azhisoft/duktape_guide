# 在 c 中定义一个 js 全局对象

- ### 定义简单对象

```c
// 定义一个全局的简单对象
// var Object1 = {
//     id: 1,
//     name: "duktape",
//     version: "2.3.0"
// };
duk_push_global_object(ctx);
duk_int_t	idx = duk_push_object(ctx);

duk_push_int(ctx, 1);
duk_put_prop_string(ctx, idx, "id");
duk_push_string(ctx, "duktape");
duk_put_prop_string(ctx, idx, "name");
duk_push_string(ctx, "2.3.0");
duk_put_prop_string(ctx, idx, "version");

duk_put_prop_string(ctx, -2, "Object1");
duk_pop(ctx);
```
​	在 js 中调用：
```javascript
// 访问 c 定义的全局对象
for(var n in Object1) {
	print("Object1." + n + ": " + Object1[n]);	
}
```

- ### 定义复合对象

```c
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
duk_int_t	idx = duk_push_object(ctx);

duk_push_int(ctx, 1);
duk_put_prop_string(ctx, idx, "id");
duk_push_string(ctx, "duktape");
duk_put_prop_string(ctx, idx, "name");
duk_push_string(ctx, "2.3.0");
duk_put_prop_string(ctx, idx, "version");

duk_int_t	sidx = duk_push_array(ctx);

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
```
​	在 js 中调用：
```javascript
// 访问 c 定义的全局对象
for(var n in Object2) {
	print("Object2." + n + ": " + JSON.stringify(Object2[n]));
}
```

