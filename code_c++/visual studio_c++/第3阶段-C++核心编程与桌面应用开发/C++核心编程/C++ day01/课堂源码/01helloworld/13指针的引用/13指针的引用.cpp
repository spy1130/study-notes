#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void test01()
{
	char* p = "翠花";
	char* &p1 = p;
	cout << p1 << endl;
}
//被调函数
void func(char* &tmp)
{
	char *p;
	p=(char*)malloc(64);
	memset(p, 0, 64);
	strcpy(p, "小花");
	tmp = p;//省了*
}
//主调函数
void test02()
{
	char* mp = NULL;
	func(mp);//省了&
	cout << mp << endl;
}

int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

