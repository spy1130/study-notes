#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//普通函数
int myPlus(int a, int b)
{
	return a + b;
}

template<class T>
int myPlus2(T a, T b)
{
	return a + b;
}

void test()
{
	int a = 10;
	int b = 20;
	char c = 'a';
	//普通函数可以进行隐式转换
	myPlus(a, c);
	//函数模版不能直接的进行隐式转换
	//myPlus2(a, c);
	myPlus2<int>(a, c);//如果要进行隐性转换，必须加上参数列表
}
int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}

