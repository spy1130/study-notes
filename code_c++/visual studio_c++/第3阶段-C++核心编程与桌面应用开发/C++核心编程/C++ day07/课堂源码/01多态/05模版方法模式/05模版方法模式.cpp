#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Drink
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//导入杯中
	virtual void PourInCup() = 0;
	//加点辅料
	virtual void addSonm() = 0;

	//模版方法,把调用函数的顺序确定下来
	void func()
	{
		Boil();
		Brew();
		PourInCup();
		addSonm();
	}
};

class Coffee :public Drink
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮点露水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "拿铁" << endl;
	}
	//导入杯中
	virtual void PourInCup()
	{
		cout << "导入盆中" << endl;
	}
	//加点辅料
	virtual void addSonm()
	{
		cout << "加点大蒜" << endl;
	}
};

class Tea :public Drink
{
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮点自来水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "铁观音" << endl;
	}
	//导入杯中
	virtual void PourInCup()
	{
		cout << "倒入碗中" << endl;
	}
	//加点辅料
	virtual void addSonm()
	{
		cout << "加点酱油" << endl;
	}
};



void test()
{
	Drink *dr = NULL;
	dr = new Coffee;
	dr->func();
	delete dr;

	dr = new Tea;
	dr->func();
	delete dr;
	dr = NULL;
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

