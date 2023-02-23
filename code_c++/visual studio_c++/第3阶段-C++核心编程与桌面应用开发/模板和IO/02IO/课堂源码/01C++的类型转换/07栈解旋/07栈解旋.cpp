#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Maker
{
public:
	Maker()
	{
		cout << "Maker的构造" << endl;
	}
	Maker(const Maker &m)
	{
		cout << "Maker的拷贝构造" << endl;
	}
	~Maker()
	{
		cout << "Maker的析构" << endl;
	}
};

void func()
{
	//在抛出异常的函数中，如果抛出异常之后，但函数没有结束，这时，栈上申请的对象都会被释放
	//这就叫栈解旋
	Maker m;
	throw m;//这个m是Maker m拷贝一份的

	cout << "func函数结束" << endl;
}

void test()
{
	try
	{
		func();
		cout << "func()代码后" << endl;
	}
	catch (Maker)
	{
		cout << "接收一个Maker类型的异常" << endl;
	}

	cout << "....." << endl;
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

