#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"test.h"
int myFunc(int a, int b = 0)//int b=0;这就是函数的默认参数，不一定是0
{
	return a + b;
}
void test01()
{
	//函数的默认参数的作用
	//当函数内常要用到形参的某个值，但偶尔要使用其他值
	//增加函数的灵活性
	cout << myFunc(10, 20) << endl;
	cout << myFunc(10)<< endl;
}

//注意1：函数的默认参数后面的参数必须都是默认参数
int myFunc2(int a, int b = 0, int c=2,int d=3)
{
	return a + b + c + d;
}
//注意2：函数的声明和实现不能同时有函数的默认参数
void myFunc3(int a, int b);
void myFunc3(int a, int b = 0)
{

}

//函数的占位参数,占位参数在后面运算符重载时区分前加加或后加加
void func(int a,int=10)//占位参数也有默认值
{

}

void test02()
{
	func(10);
}
//占位参数和默认参数混搭
void func2(int=10, int a=0)
{

}
void test03()
{
	func2();
	func2(10);
	func2(10,30);
}

int main()
{
//test01();
	myfunc(10);
	system("pause");
	return EXIT_SUCCESS;
}

