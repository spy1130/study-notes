#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、const修饰的全局变量,即使语法通过，但是运行时候受到常量区的保护，运行失败
const int a = 10; //放在常量区

void test01()
{
	//a = 100; //直接修改 失败

	int * p = &a;
	*p = 100;

	printf("%d\n", a);

}

//2、const修饰的局部变量
void test02()
{
	const int b = 10; //分配到栈上
	//b = 100; //直接修改失败的


	//间接修改 成功
	//C语言下 称为伪常量
	int * p = &b;
	*p = 100;
	printf("b = %d\n", b);

	//int a[b];//伪常量是不可以初始化数组的
}


//字符串常量
void test03()
{
	char * p1 = "hello world";
	char * p2 = "hello world";
	char * p3 = "hello world";

	printf("%d\n", p1);
	printf("%d\n", p2);
	printf("%d\n", p3);
	printf("%d\n", &"hello world");


	p1[0] = 'z'; //不允许修改字符串常量
	printf("%c\n", p1[0]);

}


int main(){
	//test01();
	//test02();
	test03();
	system("pause");
	return EXIT_SUCCESS;
}