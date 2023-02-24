#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
template<class NameType, class AgeType>
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

//1.指定传入的数据类型
void func(Maker<string,int> &m)
{
	m.printMaker();
}

//2.参数模版化（常用）
template<class T1,class T2>
void func2(Maker<T1,T2> &m)
{
	m.printMaker();
}

//3.整个类 模版化
template<class T>
void func3(T &m)
{
	m.printMaker();
}

void test()
{
	Maker<string, int> m1("悟空", 18);
	func(m1);

	func2(m1);//调用时
	/*//第二次编译
	void func2(Maker<string,int> &m)
	{
		m.printMaker();
	}
	*/

	func3(m1);
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

