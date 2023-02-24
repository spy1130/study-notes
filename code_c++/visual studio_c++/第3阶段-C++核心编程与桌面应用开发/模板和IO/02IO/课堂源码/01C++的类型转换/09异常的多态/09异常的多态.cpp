#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//异常的基类
class Father
{
public:
	virtual void printM()
	{

	}
};
//1.有继承
class SonNULL :public Father
{
public:
	virtual void printM()//2.重写父类的虚函数
	{
		cout << "空指针异常" << endl;
	}
};

class SonOut :public Father
{
public:
	virtual void printM()
	{
		cout << "越位溢出" << endl;
	}
};

void func(int a,int b)
{
	if (a == 0)
	{
		throw SonNULL();
	}
	
	if (b == 0)
	{
		throw SonOut();
	}
	
}

void test()
{
	int a = 0;
	int b = 10;
	try
	{
		func(a,b);
	}
	catch (Father &f)//3.父类引用指向子类对象
	{
		f.printM();
	}
}
int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

