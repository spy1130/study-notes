#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//结构体的默认权限是公有的，类的默认权限是私有的
//结构体
struct Maker1
{
	int a;
	void func()
	{

	}
public:
	int b;
};
//类
class Maker2
{
	int a;
	void func()
	{

	}
public:
	int b;
};

//继承
struct SonMaker1 :public Maker1
{

};

class SonMaker2 :public Maker2
{

};


int main()
{
	Maker1 m1;
	Maker2 m2;
	m1.b;
	m2.b;

	m1.a;
	//m2.a;
	system("pause");
	return EXIT_SUCCESS;
}

