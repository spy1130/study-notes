#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test()
{
	int a = 10;
	const int b = a;//如果用变量给const修饰的局部变量赋值，那么编译器不会优化
	int *p = (int*)&b;
	*p = 100;
	cout << "b=" << b << endl;
	cout << "*p=" << *p << endl;
}

//自定义数据类型，编译器不能优化
struct Maker
{
	Maker()//构造函数
	{
		a = 100;
	}
	int a;
};

void test02()
{
	//数据类型定义变量
	//类实例化对象
	const Maker ma;
	cout << ma.a << endl;
	Maker *p = (Maker*)&ma;
	p->a = 200;
	cout << ma.a << endl;//没有优化，因为不能优化自定义数据类型
}

int main()
{
	test02();

	system("pause");
	return EXIT_SUCCESS;
}

