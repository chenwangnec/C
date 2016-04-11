#include <windows.h>
#include <stdio.h>
#include <vfw.h>
#include<tchar.h>
#pragma comment( lib, "vfw32.lib" )

#include<tlhelp32.h>//½ø³Ì
void GetVersionInfo();
void SystemInfonation();
void GetUser();
void GetMouseMoveSpeed();
void GetSystemTimeInfo();
void GetCapInfo();
void GetDiskTypeInfo();
void GetProcessInf();