#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <cstring>
class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造" << endl;
	}

	//虚析构函数会调用子类的析构函数
	/*virtual ~Animal()
	{
		cout << "Animal的析构" << endl;
	}*/

	//纯虚析构函数，纯虚析构函数需要在类外实现
	virtual ~Animal() = 0;
};

//在类外实现纯虚析构函数
Animal::~Animal()
{
	cout << "Animal的纯虚析构" << endl;
}

class Son :public Animal
{
public:
	Son()
	{
		cout << "Son的构造" << endl;
		pName = new char[64];
		memset(pName, 0, 64);
		strcpy(pName, "如花");
	}

	~Son()
	{
		
		if (pName != NULL)
		{
			delete[] pName;
			pName = NULL;
		}
		cout << "Son的析构" << endl;
	}

public:
	char *pName;
};

void test()
{
	Animal *animal = new Son;
	delete animal;
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

