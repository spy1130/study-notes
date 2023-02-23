#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、无类型是不可以创建变量的
void test01()
{
	//void a = 10; //编译器直接报错，因为不知道给a分配多少内存空间
}


//2、可以限定函数返回值
void func()
{
	//return 10;
}

void test02()
{
	//func();
	//printf("%d\n", func());
}


//3、限定函数参数列表
int func2(void)
{
	return 10;
}
void test03()
{
	//printf("%d\n", func2(10));
}


//4、void *  万能指针
void test04()
{
	void * p = NULL;

	int  * pInt = NULL;
	char * pChar = NULL;

	//pChar = (char *)pInt;
	pChar = p; //万能指针  可以不需要强制类型转换就可以给等号左边赋值

	printf("size of void *   = %d\n", sizeof(p));

}

int main(){
	//test02();
	//test03();
	test04();
	system("pause");
	return EXIT_SUCCESS;
}