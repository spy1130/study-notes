#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>


template<class NameType, class AgeType>
class Maker
{
	friend void printMaker(Maker<NameType, AgeType> &p)
	{
		cout << "类内实现" << p.name << " " << p.age << endl;
	}
public:
	Maker(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	
private:
	NameType name;
	AgeType age;
};

void test01()
{
	Maker<string, int> m("悟空", 18);

	printMaker(m);
}

template<class NameType, class AgeType>
class Maker2;

//告诉编译器下面有printMaker2的实现
template<class NameType, class AgeType>
void printMaker2(Maker2<NameType, AgeType> &p);

template<class NameType, class AgeType>
class Maker2
{
	//1.在函数名和()之间加上<>。
	friend void printMaker2<>(Maker2<NameType, AgeType> &p);
	//2.编译器不知道printMaker2下面有没有实现，需要知道函数的结构
public:
	Maker2(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}


private:
	NameType name;
	AgeType age;
};

//友元在类外实现要写成函数模版
template<class NameType, class AgeType>
void printMaker2(Maker2<NameType, AgeType> &p)
{
	cout << "类外实现的友元函数 " << p.name << " " << p.age << endl;
}

void test02()
{
	Maker2<string, int> m("贝吉塔", 18);

	printMaker2(m);
}

int main()
{
	
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

