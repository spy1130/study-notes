#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	Maker(int id)
	{
		this->id = id;
	}
	Maker operator-(Maker &m2)
	{
		Maker tmp(this->id - m2.id);
		return tmp;
	}
public:
	int id;
};

int operator-(Maker &m,int b)
{
	return m.id-b;
}

void test()
{
	Maker m1(10);
	Maker m2(5);
	Maker m3 = m1 - m2;
	cout << m3.id << endl;

	int a = m3 - 5;
	cout << a << endl;
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

