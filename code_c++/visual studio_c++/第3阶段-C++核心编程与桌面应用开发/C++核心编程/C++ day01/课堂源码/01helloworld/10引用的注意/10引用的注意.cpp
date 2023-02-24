#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


int main()
{
	//1.引用创建时，必须初始化。
	//int &pRef;err

	//2.引用一旦初始化不能改变它的指向
	int a = 10;
	int &pRef = a;//给a的空间取别名为pRef;
	int b = 20;
	pRef = b;//赋值操作

	cout << &a << endl;
	cout << &pRef << endl;//2个地址一样

	system("pause");
	return EXIT_SUCCESS;
}

