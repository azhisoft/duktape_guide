
sayHello();

// 调用 c 定义的全局函数 print
print("Hello, Duktape.");

// 访问 c 定义的全局常量，并尝试修改常量值
print("AppName: " + AppName);
AppName = "Hello, " + AppName;
print("AppName(new): " + AppName);

// 访问 c 定义的全局变量，并尝试修改变量值
print("Version: " + Major + "." + Minor);
Major ++; Minor ++;
print("Version(new): " + Major + "." + Minor);

print("Full version: " + Version);
Version = "v" + Version;
print("Full version(new): " + Version);

// 访问 c 定义的全局数组，并尝试添加值
Array1.push(1000);

for(var i = 0; i < Array1.length; i ++) {
	print("Array1[" + i + "]: " + Array1[i]);
}

Array2.push(".");

print("Array2: " + JSON.stringify(Array2));

for(var i = 0; i < Array3.length; i ++) {
	print("Array3[" + i + "]: " + JSON.stringify(Array3[i]));
}

for(var i = 0; i < Array4.length; i ++) {
	print("Array4[" + i + "]: " + JSON.stringify(Array4[i]));
}

// 访问 c 定义的全局对象
for(var n in Object1) {
	print("Object1." + n + ": " + Object1[n]);	
}

for(var n in Object2) {
	print("Object2." + n + ": " + JSON.stringify(Object2[n]));
}
