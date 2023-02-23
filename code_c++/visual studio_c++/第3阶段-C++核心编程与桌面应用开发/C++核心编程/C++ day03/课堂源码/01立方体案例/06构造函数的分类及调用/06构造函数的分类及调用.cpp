#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	//按照参数分类:无参，有参
	Maker()
	{
		cout << "无参构造" << endl;
	}
	Maker(int a)
	{
		cout << "有参构造" << endl;
	}
	//按照类型:普通构造函数，拷贝构造函数
	Maker(const Maker &m)
	{
		cout << "拷贝构造" << endl;
	}

	//默认的赋值函数，后面讲
};

void test01()
{
	Maker m;//调用无参构造函数
	Maker m1(10);//调用有参构造
	Maker m2(m1);//调用拷贝构造

	//不常用
	Maker m4 = Maker(10);//调用的是有参构造函数
	Maker m3 = m2;//调用拷贝构造
	cout << "=====" << endl;
	Maker m5 = 10;//Maker m5=Maker(10);
	cout << "=======" << endl;

	Maker m6;
	m6 = m5;//赋值操作

}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}

