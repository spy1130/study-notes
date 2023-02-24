#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	Maker()
	{
		cout << "构造函数" << endl;
	}

	Maker(int a)
	{
		cout << "有参构造函数" << endl;
	}
	~Maker()
	{
		cout << "析构函数" << endl;
	}
};

void test01()
{
	//用C语言方式申请堆区空间，不会调用构造函数，
	Maker *m = (Maker*)malloc(sizeof(Maker));
	//对象释放时不会调用析构函数
	free(m);
}

void test02()
{
	//用new方式申请堆区空间，会调用类的构造函数
	Maker *m = new Maker;

	//释放堆区空间，会调用类的析构函数
	delete m;
	m = NULL;

	Maker *m2 = new Maker(10);

	delete m2;
	m2 = NULL;
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

