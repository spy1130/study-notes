#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//加强一
//自定义的数据类型
struct Maker
{
	char name[64];
	int age;
};

void test01()
{
	 Maker a;//不需要加struct就可以定义变量

}
//加强二
struct Maker2
{
	int a;
	void func()//结构体内可以写函数
	{
		cout << "func" << endl;
	}
};
void test02()
{
	Maker2 a2;
	a2.func();
}

int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

