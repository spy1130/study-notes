#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01()
{
	int a = 10;
	int &b = a;//给a的空间取别名叫b
	b = 100;
	cout << a << endl;

	
}

void func(int &a)
{
	a = 200;
}

void test02()
{
	int a = 10;
	func(a);
	cout << "a=" << a << endl;
}

int main()
{
	test02();
	
	system("pause");
	return EXIT_SUCCESS;
}

