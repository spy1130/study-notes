#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//参数的个数不同
void func()
{
	cout << "func()" << endl;
}

void func(int a)
{
	cout << "func(int a)" << endl;
}

//参数的类型不同
//void func(char c)
//{
//	cout << "func(char c)" << endl;
//}
//参数的顺序不同
void func(int a, double b)
{
	cout << "func(int a, double b)" << endl;
}
void func(double b, int a)
{
	cout << "func(double b, int a)" << endl;
}

void test01()
{
	int a = 10;
	double b = 3.14;
	//编译器是通过你调用函数时，传入的参数来判断调用重载的哪个函数
	func();
	//func(b);// err double转换不了成为int或char
	func(a, b);
	func(b, a);
	char c = 'c';
	func(c);//char转换int成功，调用int参数的函数
}

//函数重载和函的默认参数一起使用
void myfunc(int a, int b = 0)
{
	cout << "myfunc(int a, int b = 0)" << endl;
}

void myfunc(int a)
{
	cout << "myfunc(int a)" << endl;
}

void test02()
{
	//myfunc(10); //err,二义性问题，不知道调用哪个函数
}

int main()
{
	test01();

	
	system("pause");
	return EXIT_SUCCESS;
}

