#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Maker
{
public:
	void printMaker()
	{
		cout << "除数不能为0" << endl;
	}
};

int func(int a, int b)
{
	if (b == 0)
	{
		//Maker m;
		//throw m;//抛出一个Maker类型的异常
		throw 20.22;//抛出一个double类型的异常
		
	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;

	try
	{
		func(a, b);
		
	}
	catch (int)
	{
		cout << "接收一个int类型的异常" << endl;
	}
	catch (Maker maker)
	{
		cout << "接收一个Maker类型的异常" << endl;
		maker.printMaker();
	}
	catch (double s)
	{
		//不想处理异常，可以往上抛出，抛给调用本函数的函数
		throw;
	}


}

int main()
{
	try
	{
		test();
	}
	catch (double d)
	{
		cout << "接收一个double类型的异常" << endl;
	}




	system("pause");
	return EXIT_SUCCESS;
}

