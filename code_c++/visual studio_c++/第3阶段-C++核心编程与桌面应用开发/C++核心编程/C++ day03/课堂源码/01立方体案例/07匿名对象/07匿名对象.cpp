#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	Maker()
	{
		cout << "无参构造函数" << endl;
	}
	Maker(int a)
	{
		cout << "有参构造函数" << endl;
	}
	Maker(const Maker &maker)
	{
		cout << "拷贝构造函数" << endl;
	}
	~Maker()
	{
		cout << "析构函数" << endl;
	}
};
void test01()
{
	Maker();//匿名对象的生命周期在当前行
	Maker(10);
	

	//注意，如果匿名对象有名字来接，那么就不是匿名对象

	Maker m1 = Maker();

	cout << "test01()函数结束" << endl;
}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}

