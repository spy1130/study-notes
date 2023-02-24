#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//1.什么是拷贝构造
class Maker
{
public:
	Maker()
	{
		cout << "无参构造函数" << endl;
		a = 20;
	}
	//拷贝构造函数
	Maker(const Maker &m)
	{
		cout << "拷贝构造函数" << endl;
		a = m.a;
		
	}
	//打印函数
	void printMaker()
	{
		cout << "a=" << a << endl;
	}
private:
	int a;
};



void test01()
{
	Maker m1;
	m1.printMaker();

	//用一个已有的对象去初始化另一个对象
	Maker m2(m1);
	m2.printMaker();
}
//2.编译器提供了默认的拷贝构造函数
class Maker2
{
public:
	Maker2()
	{
		cout << "无参构造函数" << endl;
		a = 20;
	}
	//编译器提供了默认的拷贝构造函数
	//Maker2(const Maker2 &m)
	//{
	//	//默认拷贝构造函数进行了成员变量的简单拷贝
	//	a = m.a;
	//}

	//打印函数
	void printMaker()
	{
		cout << "a=" << a << endl;
	}
private:
	int a;
};


void test02()
{
	Maker2 m1;
	m1.printMaker();

	
	Maker2 m2(m1);
	m2.printMaker();
}
//3.拷贝构造函数中形参要用引用
class Maker3
{
public:
	Maker3(int Ma)
	{
		cout << "有参构造函数" << endl;
		ma = Ma;
	}
	Maker3(const Maker3 &m)
	{
		cout << "拷贝构造函数" << endl;
	}
private:
	int ma;
};

void test03()
{
	Maker3 m1(10);//调用有参构造

	Maker3 m2(m1);//调用拷贝构造

	Maker3 m3 = m1;//调用拷贝构造

	//如果拷贝构造函数中的形参不是引用
	/*
	Maker3(const Maker3 m)//const Maker3 m=m1;   const Maker3 m(m1);
	{
		cout << "拷贝构造函数" << endl;
	}

	1.Maker3 m2(m1);
	2.const Maker3 m=m1;
	3.const Maker3 m(m1);
	4.const Maker3 m=m1;
	5.进入死循环
	*/
}


int main()
{
	test03();
	system("pause");
	return EXIT_SUCCESS;
}

