#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class rule
{
public:
	virtual double getNum(double a, double b) = 0;
};
//加
class rule_add :public rule
{
public:
	virtual double getNum(double a, double b)
	{
		return a + b;
	}
};
//减
class rule_minux :public rule
{
public:
	virtual double getNum(double a, double b)
	{
		return a - b;
	}
};

//乘
class rule_take :public rule
{
public:
	virtual double getNum(double a, double b)
	{
		return a * b;
	}
};

//除
class rule_division :public rule
{
public:
	virtual double getNum(double a, double b)
	{
		if (b == 0)
		{
			cout << "除数不能为0" << endl;
			return -1.0;
		}
		return a / b;
	}
};

void test()
{
	rule *r = NULL;
	r = new rule_add;
	cout << r->getNum(30,10) << endl;

	r = new rule_minux;
	cout << r->getNum(30, 10) << endl;

	r = new rule_take;
	cout << r->getNum(30, 10) << endl;

	r = new rule_division;
	cout << r->getNum(30, 10) << endl;
}
int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

