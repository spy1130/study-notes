#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//静态转换
//1.基础类型转
void test01()
{
	char a = 'a';
	//char->double;
	//static_cast<要转到的类型>（将谁转换）
	double d = static_cast<double>(a);

	//double d1 = (double)a;
}
//2.有层次关系类的指针或引用转换
class Father
{

};
class Son :public Father
{

};

class Other
{

};
void test02()
{
	Father *f = NULL;
	Son *s = NULL;

	//向下转，不安全
	Son* s1=static_cast<Son*>(f);
	//向上转换，安全
	Father* f1 = static_cast<Father*>(s);
	//没有继承关系的类之间的指针不能转换
	//Other *o = static_cast<Other*>(s);
}
//引用转换
void test03()
{
	Father f;
	Son s;

	Father &ref_f = f;
	Son &ref_s = s;
	//向上，安全
	static_cast<Father&>(ref_s);
	//向下，不安全
	static_cast<Son&>(ref_f);
}

//动态转换
void test04()
{
	//char a = 'a';
	//dynamic_cast<double>(a);基础类型不能使用动态转换

	Father *f = NULL;
	Son *s = NULL;
	//向上，安全
	Father *f1 = dynamic_cast<Father*>(s);
	//向下，不安全，会检查
	//Son *s1 = dynamic_cast<Son*>(f);
}
//发生多态时，向下转换，动态转换就可以
class Father2
{
public:
	virtual void func(){};
};
class Son2 :public Father2
{
public:
	virtual void func(){};
};
void test05()
{
	Father2* f = new Son2;

	dynamic_cast<Son2*>(f);
}

//常量转换
void test06()
{
	const int *p = NULL;
	//const-->不带const
	int *newP = const_cast<int*>(p);

	int *pp = NULL;
	const int* newPP = const_cast<const int*>(pp);
}
//重新解释转换
void test07()
{
	int a = 10;
	int *p = reinterpret_cast<int *>(a);

	Father *f = NULL;
	Other *o = reinterpret_cast<Other*>(f);
}

int main()
{
	test05();
	system("pause");
	return EXIT_SUCCESS;
}

