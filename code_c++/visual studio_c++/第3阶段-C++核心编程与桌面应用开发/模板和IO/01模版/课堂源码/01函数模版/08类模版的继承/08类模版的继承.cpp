#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//普通类继承类模版
template<class T>
class Father
{
public:
	Father()
	{
		m = 20;
	}
public:
	T m;
};

//普通类 继承 类模版
class Son :public Father<int>//要告诉编译器父类的泛型数据类型具体是什么类型
{
public:

};
//类模版 继承 类模版
template<class T1,class T2>
class Son2 :public Father<T2>//要告诉编译器父类的泛型数据类型具体是什么类型
{

};

void test()
{
	Son2<int,int> s;
	cout << s.m << endl;
}

int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}

