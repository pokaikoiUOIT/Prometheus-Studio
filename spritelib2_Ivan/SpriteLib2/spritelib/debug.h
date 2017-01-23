#pragma once

#include <cstdio>
#include <Windows.h>

#include <string.h>
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define SPRITELIB_ERROR(a_message, ...)\
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0C);\
	printf("ERR: %s()(file:%s,ln:%d) "a_message"\n",  __FUNCTION__,__FILENAME__, __LINE__, ##__VA_ARGS__);\
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07)

#define SPRITELIB_WARNING(a_message, ...)\
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0E);\
	printf("WRN: %s()(file:%s,ln:%d) "a_message"\n",  __FUNCTION__,__FILENAME__, __LINE__, ##__VA_ARGS__);\
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07)