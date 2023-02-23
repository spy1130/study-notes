#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


int main()
{
	//这种方式不能进行隐式转换，必须显示的转换
	char *p = (char *)malloc(64);
	system("pause");
	return EXIT_SUCCESS;
}

