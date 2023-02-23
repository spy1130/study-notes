#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int func(int a, int b)
{
	if (b == 0)
	{
		//第二步：
		throw 10;//抛出一个int类型的异常，
		cout << "throw后的代码" << endl;
	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;
	
	try
	{
		func(a, b);//第一步：
		cout << "func后的代码" << endl;
	}
	catch (int)//第三步：
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

