#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	Maker()
	{
		
	}
public:
	//1.静态成员变量的生命周期是整个程序，作用域在类内
	static int a;
};
//2.静态成员变量要在类内声明，类外初始化
int Maker::a = 100;
void test01()
{
	//3.静态成员变量属于类，不属于对象，是所有对象共享
	cout << Maker::a << endl;
	Maker m;
	cout << m.a << endl;
	//4.静态成员变量可以用类访问，也可以用对象访问
}

class Maker2
{
public:
	Maker2()
	{

	}
	//静态成员函数只能访问静态成员变量
	static void setA(int a)
	{
		a2 = a;
		cout << "a2=" << a2 << endl;
		//a1 = a;不能访问普通成员变量
	}
public:
	int a1;
	static int a2;
};
int Maker2::a2 = 200;
void test02()
{
	Maker2::setA(300);
}
class Maker3
{
private:
	static void func()
	{
		cout << "a3=" << a3 << endl;
	}
private:
	static int a3;
};
int Maker3::a3 = 300;
void test03()
{
	//Maker3::func();err
}
//const修饰的静态成员变量最好在类内初始化
class Maker4
{
public:
	const static int a = 20;
	const static int b;
};
//类外也可以初始化
const int Maker4::b = 30;


class Maker5
{
public:
	void func()
	{
		cout << "a=" << a << endl;
	}
public:
	static int a;
};

//类外也可以初始化
int Maker5::a = 30;

void test04()
{
	Maker5 m;

	m.func();
	
}
int main()
{
	
	test04();
	system("pause");
	return EXIT_SUCCESS;
}

