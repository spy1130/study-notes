#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"MyArray.hpp"
#include<string>
class Maker
{
public:
	Maker(){}
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};

void printMaker(MyArray<Maker> &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "ÐÕÃû:" << arr[i].name << " ÄêÁä:" << arr[i].age << endl;
	}
}
void test()
{
	MyArray<Maker> myarr(4);
	Maker m1("Îò¿Õ", 18);
	Maker m2("±´¼ªËþ", 30);
	Maker m3("¶ÌµÑ", 200);
	Maker m4("Ð¡ÁÖ", 19);
	myarr.Push_Back(m1);
	myarr.Push_Back(m2);
	myarr.Push_Back(m3);
	myarr.Push_Back(m4);

	printMaker(myarr);

	MyArray<int> myint(10);
	for (int i = 0; i < 10; i++)
	{
		myint.Push_Back(i + 1);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << myint[i] <<" ";
	}
	cout << endl;
}

int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}

