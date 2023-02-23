//#define _CRT_SECURE_NO_WARNINGS  //VS不建议使用传统库函数,如果不用这个宏，会出现一个错，编号：C4996
#include<stdio.h>   // std 标准 i input  输入   o  output 输出 
#include<string.h>  // strcpy   strcmp  strcat  strstr
#include<stdlib.h>  // malloc  free


//1、typedef使用  简化结构体关键字 struct
//struct Person
//{
//	char name[64];
//	int age;
//};
//typedef struct Person  myPerson;

//主要用途  给类型起别名
//语法  typedef  原名  别名
typedef struct Person
{
	char name[64];
	int age;
}myPerson;

void test01()
{
	struct Person p1 = { "张三", 19 };

	myPerson p2 = { "李四", 20 };
}


// 2、区分数据类型
void test02()
{
	//char * p1, p2;  //p1是char *  而 p2 是char


	typedef char * PCHAR;
	PCHAR p1, p2;


	char *p3, *p4; // p3 和 p4都是char *
}


//3、提高代码移植性
typedef int MYINT; //typedef long long MYINT; 只需要替换 long long 就可以了
void test03()
{
	MYINT a = 10;

	MYINT a2 = 10;
}


//程序入口
int main1(){

	


	system("pause"); // 按任意键暂停  阻塞功能

	return EXIT_SUCCESS; //返回 正常退出值  0
}