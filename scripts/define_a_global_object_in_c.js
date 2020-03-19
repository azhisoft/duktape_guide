
// 调用 c 定义的全局函数 print
print("Hello, Duktape.");

// 访问 c 定义的全局常量，并尝试修改常量值
print("AppName: " + AppName);
AppName = "Hello, " + AppName;
print("AppName(new): " + AppName);

// 访问 c 定义的全局变量，并尝试修改变量值
print("Full version: " + Version);
Version = "v" + Version;
print("Full version(new): " + Version);

print("Version: " + Major + "." + Minor);
Major ++; Minor ++;
print("Version(new): " + Major + "." + Minor);
