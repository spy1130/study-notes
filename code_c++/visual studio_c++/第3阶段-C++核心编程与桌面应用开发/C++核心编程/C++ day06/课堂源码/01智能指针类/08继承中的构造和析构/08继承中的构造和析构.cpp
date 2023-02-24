#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Father
{
public:
	Father()
	{
		cout << "Father构造函数" << endl;
	}
	~Father()
	{
		cout << "Father析构函数" << endl;
	}
};

class Son :public Father
{
public:
	Son()
	{
		cout << "Son构造函数" << endl;
	}
	~Son()
	{
		cout << "Son析构函数" << endl;
	}
};
//先调用父类的构造函数，再调用本身的构造函数，析构函数调用顺序反之
void test01()
{
	Son s;
}

class A
{
public:
	A()
	{
		cout << "A 的构造" << endl;
	}
	~A()
	{
		cout << "A 的析构" << endl;
	}
public:
	Son s;
};

class B
{
public:
	B()
	{
		cout << "B 的构造" << endl;
	}
	~B()
	{
		cout << "B 的析构" << endl;
	}
};

class C
{
public:
	C()
	{
		cout << "C 的构造" << endl;
	}
	~C()
	{
		cout << "C 的析构" << endl;
	}
};

class D:public A
{
public:
	D()
	{
		cout << "D 的构造" << endl;
	}
	~D()
	{
		cout << "D 的析构" << endl;
	}
public:
	B b;
	C c;
};
void test02()
{
	D d;
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

