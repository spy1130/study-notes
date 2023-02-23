#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	Maker()//默认的构造函数，函数体是空的
	{

	}
	~Maker()//默认的析构函数，函数体也是空
	{

	}
	//编译器默认提供默认的构造函数和析构函数
	void printfMaker()
	{
		a = 100;
		cout << "a=" << a << endl;
	}
private:
	int a;
};

void test01()
{
	Maker m;
	m.printfMaker();
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}

