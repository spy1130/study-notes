#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

class Building
{
	//声明这个全局函数为Building类的友元函数
	friend void GoodGay(Building &bd);
public:
	Building()
	{
		keting = "客厅";
		woshi = "卧室";
	}

public:
	string keting;
private:
	string woshi;
};

void GoodGay(Building &bd)
{
	cout << "好基友访问:" << bd.keting << endl;
	cout << "好基友访问:" << bd.woshi << endl;
}

void test01()
{
	Building my;

	GoodGay(my);
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}

