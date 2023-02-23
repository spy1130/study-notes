#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1.引用作为函数参数
void func(int &a, int &b)
{
	int sum = a + b;
	cout << "sum=" << sum << endl;
}

void test01()
{
	int a = 10;
	int b = 20;
	func(a, b);
}
//2.引用作为函数的返回值
int& func2()
{
	int b = 10;//不要返回局部变量的引用
	int &p = b;
	return p;
}
int &func3()
{
	static int b = 10;
	return b;
}
void test02()
{
	int &q = func2();
	q = 100;
	cout << q << endl;

	func2() = 200;
	cout << q << endl;
////---------上面的代码是错误，只是编译器没有检测出来
	cout << "func2="<<func2() << endl;

	func3() = 100;//如果要函数当左值，那么该函数必须返回引用
	cout << "func3()=" << func3() << endl;
}
int main()
{

	test02();
	system("pause");
	return EXIT_SUCCESS;
}

