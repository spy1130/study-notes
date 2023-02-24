#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test()
{
	int a = 10;
	int b = 20;
	printf("%d\n", a > b ? a : b);
	//(a > b ? a : b) = 100;err
	//这个表达式返回的是右值，是数值，返回的是20
	//20 = 100;
	*(a > b ? &a : &b) = 100;
	printf("b=%d\n", b);
}

int main2()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

