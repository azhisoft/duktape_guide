
// ���� c �����ȫ�ֺ��� print
print("Hello, Duktape.");

// ���� c �����ȫ�ֳ������������޸ĳ���ֵ
print("AppName: " + AppName);
AppName = "Hello, " + AppName;
print("AppName(new): " + AppName);

// ���� c �����ȫ�ֱ������������޸ı���ֵ
print("Full version: " + Version);
Version = "v" + Version;
print("Full version(new): " + Version);

print("Version: " + Major + "." + Minor);
Major ++; Minor ++;
print("Version(new): " + Major + "." + Minor);
