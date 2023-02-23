#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Maker
{
public:
	Maker()
	{
		cout << "无参构造函数" << endl;
	}
	Maker(int a)
	{
		cout << "有参构造函数" << endl;
	}
	Maker(const Maker &maker)
	{
		cout << "拷贝构造函数" << endl;
	}
	~Maker()
	{
		cout << "析构函数" << endl;
	}
};
//1.对象以值方式给函数参数
void func(Maker m)//Maker m=m1;
{

}

void test01()
{
	Maker m1;
	func(m1);

}
//2.用一个已有的对象去初始化另一个对象
void test02()
{
	Maker m1;
	Maker m2(m1);
}

//3.函数的局部对象以值的方式从函数返回
//vs Debug模式下，会调用拷贝构造，vs Release模式下不会调用拷贝构造，qt也不调用
Maker func2()
{
	//局部对象
	Maker m;
	cout << "局部对象的地址:" << &m << endl;

	return m;
}

void test03()
{
	
	Maker m1 = func2();

	cout << "m1对象的地址：" << &m1 << endl;
}

int main()
{
	test03();
	system("pause");
	return EXIT_SUCCESS;
}

