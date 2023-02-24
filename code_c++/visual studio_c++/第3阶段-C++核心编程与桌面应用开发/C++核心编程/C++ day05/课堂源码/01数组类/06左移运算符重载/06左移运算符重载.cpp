#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

class Maker
{
	friend ostream& operator<<(ostream &out, Maker &m);
public:
	Maker(int id,string name)
	{
		this->id = id;
		this->name = name;
	}

public:
	int id;
	string name;
};
//1.形参和实参是一个对象
//2.不能改变库类中的代码
//3.ostream中把拷贝构造函数私有化了
//4.如果要和endl一起使用，那么必须返回ostream的对象
ostream& operator<<(ostream &out, Maker &m)
{
	cout << m.id <<" "<<m.name<< endl;

	return out;
}

void test01()
{
	Maker m(10,"小花");
	cout << m << endl;
	cout << endl;
	/*
	endl是一个函数
	operator<<(endl）,ostream重载了
	*/

	cout << 10;//内部重载了基础数据类型
}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}

