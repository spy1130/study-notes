#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class BMW
{
public:

	BMW()
	{
		cout << "BMW有参构造" << endl;
	}

	~BMW()
	{
		cout << "BMW析构" << endl;
	}
};

class Buick
{
public:
	Buick()
	{
		cout << "Buick构造" << endl;
	}

	~Buick()
	{
		cout << "Buick析构" << endl;
	}
};

class Maker
{
public:
	
	Maker() 
	{
		cout << "Maker构造" << endl;
	}

	~Maker()
	{
		cout << "Maker析构" << endl;
	}
private:
	
	Buick bui;//成员对象
	BMW bmw;//成员对象
};
//1.如果类有成员对象，那么先调用成员对象的构造函数，再调用本身的构造函数
//析构函数的调用顺序反之
//2.成员对象的构造函数调用和定义顺序一样
//3.注意，如果有成员对象，那么实例化对象时，必须保证成员对象的构造和析构能被调用
void test01()
{
	Maker m;
}

class BMW2
{
public:
	BMW2()
	{

	}
	BMW2(int a)
	{
		cout << "BMW2有参构造" << a << endl;
	}

	~BMW2()
	{
		cout << "BMW2析构" << endl;
	}
};

class Buick2
{
public:
	Buick2()
	{

	}
	Buick2(int b,int c)
	{
		cout << "Buick2构造" << endl;
	}

	~Buick2()
	{
		cout << "Buick2析构" << endl;
	}
};

class Maker2
{
public:
	//初始化列表
	//注意1：初始化列表只能写在构造函数
	/*Maker2() :bmw(10)
	{
		cout << "Maker2构造" << endl;
	}*/
	//如果有多个对象需要指定调用某个构造函数，用逗号隔开
	Maker2(int a,int b,int c) :bmw(a), bui(b,c)
	{
		cout << "Maker2构造" << endl;
	}
	//注意2:如果使用了初始化列表，那么所有的构造函数都要写初始化列表
	Maker2(const Maker &m2) :bmw(40), bui(10,20)
	{

	}
	Maker2(int a,int b)
	{

	}
	/*void printMaker2() : bmw(10)
	{

	}*/

	~Maker2()
	{
		cout << "Maker2析构" << endl;
	}
private:

	Buick2 bui;//成员对象
	BMW2 bmw;//成员对象
};

//初始化列表是调用成员对象的指定构造函数
void test02()
{
	Maker2 m(30,10,20);
}


int main()
{
	test05();

	system("pause");
	return EXIT_SUCCESS;
}

