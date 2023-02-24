#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//抽象类
class Father
{
public:
	virtual void func1() = 0;//接口的声明
	virtual void func2(int a) = 0;
	virtual void func3(int a,int b) = 0;
};

class Son :public Father
{
public:
	virtual void func1()//接口的实现
	{

	}
	virtual void func2(int a)
	{

	}
	virtual void func3(int a, int b)
	{

	}
};

void test()
{
	Son s;
	s.func1();
}


int main()
{

	system("pause");
	return EXIT_SUCCESS;
}

