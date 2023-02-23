#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、静态变量
static int a = 10; //特点：只初始化一次，在编译阶段就分配内存，属于内部链接属性，只能在当前文件中使用

void test01()
{
	static int b = 20; //局部静态变量,作用域只能在当前test01中

	//a 和 b的生命周期是一样的
}


//2、全局变量

extern int g_a = 100; //在C语言下 全局变量前都隐藏加了关键字  extern，属于外部链接属性

void test02()
{
	extern int g_b;//告诉编译器 g_b是外部链接属性变量，下面在使用这个变量时候不要报错

	printf("g_b = %d\n", g_b);

}

int main(){
	test02();
	

	system("pause");
	return EXIT_SUCCESS;
}