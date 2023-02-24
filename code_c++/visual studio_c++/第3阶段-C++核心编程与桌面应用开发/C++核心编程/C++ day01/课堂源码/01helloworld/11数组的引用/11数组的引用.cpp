#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	//第一种方法
	//1.定义数组类型
	typedef int(MY_ARR)[5];//数组类型
	//2.建立引用
	MY_ARR &arref = arr;//建立引用，int &b=a;

	//第二种方法
	//直接定义引用
	int(&arref2)[5] = arr;// int &b=a

	//第三种方法
	typedef int(&MY_ARR3)[5];//建立引用数组类型
	MY_ARR3 arref3 = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << arref[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		arref2[i] = 100 + i;
		cout << arref2[i] << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}

