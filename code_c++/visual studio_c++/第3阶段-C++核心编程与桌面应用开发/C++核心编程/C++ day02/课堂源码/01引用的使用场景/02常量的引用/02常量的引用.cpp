#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


int main()
{
	//普通引用
	int a = 10;
	int &ref = a;
	ref = 20;

	//int &ret2 = 10;//不能给字面量取别名 err
	const int &ref3 = 10;//可以给const修饰的引用赋予字面量
	//const修饰符修饰的引用的原理
	//编译器会把上面的代码变为：int tmp=10;const int &ref3=tmp;
	//ref3 = 200;err

	//bool类型
	//bool类型定义的变量只有两个值，true和false,真和假，1和0
	bool is = 0;//注意：is的值除0以外，都是真
	if (is)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}

