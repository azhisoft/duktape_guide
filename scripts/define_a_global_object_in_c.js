
sayHello();

// ���� c �����ȫ�ֺ��� print
print("Hello, Duktape.");

// ���� c �����ȫ�ֳ������������޸ĳ���ֵ
print("AppName: " + AppName);
AppName = "Hello, " + AppName;
print("AppName(new): " + AppName);

// ���� c �����ȫ�ֱ������������޸ı���ֵ
print("Version: " + Major + "." + Minor);
Major ++; Minor ++;
print("Version(new): " + Major + "." + Minor);

print("Full version: " + Version);
Version = "v" + Version;
print("Full version(new): " + Version);

// ���� c �����ȫ�����飬���������ֵ
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

// ���� c �����ȫ�ֶ���
for(var n in Object1) {
	print("Object1." + n + ": " + Object1[n]);	
}

for(var n in Object2) {
	print("Object2." + n + ": " + JSON.stringify(Object2[n]));
}
