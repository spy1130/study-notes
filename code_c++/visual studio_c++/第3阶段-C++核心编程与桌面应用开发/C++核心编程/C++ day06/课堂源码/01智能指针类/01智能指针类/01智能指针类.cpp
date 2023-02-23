#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	Maker()
	{
		cout << "无参构造" << endl;
	}
	void printMaker()
	{
		cout << "hello Maker" << endl;
	}
	~Maker()
	{
		cout << "析构函数" << endl;
	}
};

class SmartPoint
{
public:
	SmartPoint(Maker *m)
	{
		this->pMaker = m;
	}
	//重载指针运算符
	Maker *operator->()
	{
		return this->pMaker;
	}
	//重载星花
	Maker &operator*()
	{
		return *pMaker;
	}

	~SmartPoint()
	{
		if (this->pMaker != NULL)
		{
			cout << "SmartPoint 析构函数" << endl;
			delete this->pMaker;
			this->pMaker = NULL;
		}
	}
private:
	Maker *pMaker;
};
void test01()
{
	Maker *p = new Maker;
	
	SmartPoint sm(p);//栈区，会调用析构函数
	//当test01()函数结束时，会调用SmartPoint的析构函数，
	//在这析构函数中delete了Maker的对象，会调用Maker的析构函数

}
void test02()
{
	Maker *p = new Maker;

	SmartPoint sm(p);
	//sm-> ==> pMaker->
	sm->printMaker();

	(*sm).printMaker();

}

int main()
{
	test02();

	system("pause");
	return EXIT_SUCCESS;
}

