#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker//这个是类
{
public:
	int a;//成员属性（成员变量）
	void func()//成员方法（成员函数）
	{
		cout << "func" << endl;
	}
};



int main()
{
	Maker m;//m就是对象

	system("pause");
	return EXIT_SUCCESS;
}

