#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	Maker()
	{
		id = 0;
		age = 0;
	}
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}

	bool operator==(Maker &m)
	{
		if (this->id == m.id && this->age == m.age)
		{
			return true;
		}
		return false;
	}


	bool operator!=(Maker &m)
	{
		if (this->id != m.id || this->age != m.age)
		{
			return true;
		}
		return false;
	}
public:
	int id;
	int age;
};

void test()
{
	Maker p1(1, 20);
	Maker p2;

	if (p1 == p2)
	{
		cout << "Õæ" << endl;
	}
	else
	{
		cout << "¼Ù" << endl;
	}

	if (p1 != p2)
	{
		cout << "Õæ" << endl;
	}
	else
	{
		cout << "¼Ù" << endl;
	}
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

