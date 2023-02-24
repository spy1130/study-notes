#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
//一个类如重载了函数调用符号，那么这个类实例化出的对象也叫仿函数
//仿函数的作用：1.方便代码维护 2.方便有权限的调用函数。3.作为算法的策略（后将）
class Maker
{
public:
	Maker()
	{
		name = "翠花";
	}
	void printMaker()
	{
		cout << name + "你好漂亮" << endl;
	}

	void operator()()
	{
		cout << "hello" << endl;
	}

	void operator()(int v1,int v2)
	{
		cout << v1+v2 << endl;
	}
public:
	string name;
};

void func2()
{

}

void test()
{
	Maker func;

	func();//看起来像函数，其实func是对象

	func(10, 20);

	func.printMaker();
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

