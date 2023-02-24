#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	//构造函数的作用是初始化成员变量，是编译器去调用的
	Maker()
	{
		a = 10;
		cout << "构造函数" << endl;
	}

	//析构函数，在对象销毁前，编译器调用析构函数
	~Maker()
	{
		cout << "析构函数" << endl;
	}
public:
	int a;
};

void test01()
{
	//实例化对象，内部做了两件事，1.分配空间，2.调用构造函数进行初始化
	Maker m;
	int b = m.a;
	cout << b << endl;

}
//析构函数的作用
class Maker2
{
public:
	//有参构造
	Maker2(const char *name,int age)
	{
		cout << "有参构造" << endl;
		//从堆区空间申请
		pName = (char*)malloc(strlen(name) + 1);
		strcpy(pName, name);
		mAge = age;
	}

	void printMaker2()
	{
		cout << "name:" << pName << " age:" << mAge << endl;
	}
	~Maker2()
	{
		cout << "析构函数" << endl;
		//释放堆区空间
		if (pName != NULL)
		{
			free(pName);
			pName = NULL;
		}
	}
private:
	char *pName;
	int mAge;
};

class Maker3
{
public://注意2：构造函数和析构函数必须是公有权限
	//注意1：构造函数可以重载
	Maker3()//无参构造函数
	{
		cout << "Maker3的无参构造" << endl;
	}
	Maker3(int a)//有参构造函数
	{
		cout << "Maker3的有参构造" << endl;
	}
	
	~Maker3()
	{
		cout << "析构函数" << endl;
	}

};

void test02()
{
	Maker2 m2("翠花",18);
	m2.printMaker2();

}

void test03()
{
	Maker3 m;//当构造函数私有时，实例化不了对象


	//有对象产生必然会调用构造函数，有对象销毁必然会调用析构函数
	//有多少个对象产生就会调用多少次构造函数，有多少个对象销毁就会调用多少次析构函数

	Maker3 m2(10);
}

int main()
{
	test03();

	system("pause");
	return EXIT_SUCCESS;
}

