#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"test.h"
using namespace std;



//命名空间
namespace A{//A是空间的名字，
	int a;
	void func()
	{

	}
}
//命名空间可以嵌套命名空间
namespace Maker
{
	int a;
	namespace B
	{
		int b=40;
	}
}
//void test()
//{
//	cout << Maker::c << endl;
//}


namespace Maker
{
	
	int c=30;
	
}
int mya = 10;

//类似于static int d=50;
namespace
{
	int d = 50;
}
//命名空间取别名

void test01()
{
	//			新名字    旧名字
	namespace nameMaker = Maker;

	cout << nameMaker::a << endl;
}


int main()
{
	
	int mya = 20;
	//就近原则
	cout << "mya=" << mya << endl;
	cout << "::mya=" << ::mya << endl;
	cout << Maker::a << endl;
	cout << Maker::c << endl;
	cout << Maker::B::b << endl;
	//test();
	myMaker1::func();
	

	cout << d << endl;
	system("pause");
	return EXIT_SUCCESS;
}

