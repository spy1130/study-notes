#pragma once

#include<stdio.h>

//这是告诉C++编译器，找下面的函数，要以C语言的方式去寻找
#ifdef __cplusplus
extern "C"
{
#endif
	void func();


#ifdef __cplusplus
}
#endif


