#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//栈 注意事项 ，不要返回局部变量的地址
int * func()
{
	int a = 10;
	return &a;
}

void test01()
{
	int * p = func();

	//结果已经不重要了，因为a的内存已经被释放了，我们没有权限去操作这块内存
	printf("a = %d\n", *p);
	printf("a = %d\n", *p);
}


char * getString()
{
	char str[] = "hello world";
	return str;
}

void test02()
{
	char * p = NULL;
	p = getString();
	printf("%s\n", p);
}

int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}