#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test()
{
	int a = 1;
	cout << ++a << endl;
	cout << a++ << endl;
	cout << a << endl;

	++(++a);
}

class Maker
{
	friend ostream &operator<<(ostream &out, Maker &m);
public:
	Maker(int a)
	{
		this->a = a;
	}
	//重载前置加加
	Maker &operator++()
	{
		++this->a;
		return *this;
	}

	//后置加加,
	Maker operator++(int)//占位参数，必须是int
	{
		//后置加加，先返回，后加加
		Maker tmp(*this);//1.*this里面的值a是等于2,拷贝构造
		++this->a;//这个对象的a等3
		return tmp;
	}
private:
	int a;
};

ostream &operator<<(ostream &out, Maker &m)
{
	out << m.a << endl;
	return out;
}

void test02()
{
	Maker m1(1);
	cout << m1 << endl;//1
	cout << ++m1 << endl;//2
	//++(++m1);
	cout << m1++ << endl;//2  这里返回的拷贝的tmp对象
	cout << m1 << endl;//3 这里返回的是++this->a的对象

	//同等条件下，优先使用前置加加，不需要产生新的对象和调用拷贝构造

}

int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

