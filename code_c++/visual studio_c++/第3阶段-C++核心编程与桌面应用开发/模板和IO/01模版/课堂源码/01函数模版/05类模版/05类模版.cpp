#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
template<class NameType,class AgeType>
class Maker
{
public:
	Maker(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void printMaker()
	{
		cout << "Name:" << this->name << " Age:" << this->age << endl;
	}
public:
	NameType name;
	AgeType age;
};

void test()
{
	//1.类模版不会自动推导数据类型，要显示的告诉编译器是什么类型
	Maker<string,int> m("悟空",18);
	m.printMaker();

	//2.注意传入的参数,传入参数类型要程序员自己把握
	Maker<int, int> m2(18, 20);
	m2.printMaker();

	//Maker<> m3("aaa",18);err,必须通过参数列表告诉编译器是什么类型

}

//类模版的默认类型

template<class NameType, class AgeType=int>
class Maker2
{
public:
	Maker2(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void printMaker()
	{
		cout << "Name:" << this->name << " Age:" << this->age << endl;
	}
public:
	NameType name;
	AgeType age;
};

void test02()
{
	//如果有默认类型，那么<>里可以少写类型
	Maker2<string> m("aaa", 20);

	m.printMaker();
	//以传入的类型为准
	Maker2<string, double> m2("wukong", 20.22);
	m2.printMaker();
}
//默认类型后面的泛型类型都必须有默认类型
template<class NameType, class AgeType = int,class T=int>
class Maker3
{
public:
	Maker3(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void printMaker()
	{
		cout << "Name:" << this->name << " Age:" << this->age << endl;
	}
public:
	NameType name;
	AgeType age;
};
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

