#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

void test()
{
	int a;
	cin >> a;
	cout << a << endl;
}

class Maker
{
	friend istream & operator>>(istream &in, Maker &m);
public:
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	int getAge()
	{
		return age;
	}
private:
	string name;
	int age;
};

istream &operator>>(istream &in, Maker &m)
{
	in >> m.age;
	in >> m.name;

	return in;
}

void test02()
{
	Maker m("ЮђПе", 15);
	Maker m2("ЮђПе2", 25);

	cin >> m>>m2;

	cout << m.getAge() << endl;
	cout << m2.getAge() << endl;

}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

