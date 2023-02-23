#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int func(int a, int b)
{
	if (b == 0)
	{
		//2.抛出异常
		throw 10;//抛出一个int类型的异常，
	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;
	//1.把有可能出现异常的代码块放到try中
	try
	{
		func(a, b);
	}
	catch (int &a)//3.接收一个int类型的异常
	{
		cout << "接收一个int类型的异常" << endl;
		
	}

}
int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

