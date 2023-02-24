#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Maker
{
public:
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
	
public:
	int id;
	int age;
};
class Student
{
public:
	Student()
	{
		mid = 0;
	}
	Student(int id)
	{
		mid = id;
	}
public:
	int mid;
};

Student operator+(Maker &m, Student &s)
{
	Student tmp(m.id + s.mid);

	return tmp;
	
}

Student operator+(Student &s, Maker &m)
{
	Student tmp(m.id + s.mid);

	return tmp;

}

void test()
{
	Maker m1(1, 18);
	Student s1(2);
	Student s2 = m1 + s1;

	s1 + m1;
}

int main()
{
	int a = 0;
	int b = 20;

	if (a&&b)
	{

	}
	if (a || b)
	{

	}

	system("pause");
	return EXIT_SUCCESS;
}

