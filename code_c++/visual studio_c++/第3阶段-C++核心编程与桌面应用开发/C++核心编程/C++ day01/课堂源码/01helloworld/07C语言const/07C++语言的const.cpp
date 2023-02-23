#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
const int aa = 10;//没有内存

void test01()
{
	//发生了常量折叠
	cout << "aa=" << aa << endl;//在编译阶段，编译器：cout<<"aa="<<10<<endl;

	//禁止优化volatile
	//volatile const int bb = 20;//栈区
	 const int bb = 20;
	int *p = (int*)&bb;
	*p = 200;
	cout << "bb=" << bb << endl;//cout << "bb=" << 20 << endl;
	cout << "*p=" << *p << endl;

	cout << "a的地址=" << (int)&bb << endl;
	cout << "p指向的地址" << (int)p << endl;


}
int main()
{
	test01();

	//C++语言中const修饰的全局变量具有内部链接属性
	extern const int c;
	cout << "c=" << c << endl;
	system("pause");
	return EXIT_SUCCESS;
}

