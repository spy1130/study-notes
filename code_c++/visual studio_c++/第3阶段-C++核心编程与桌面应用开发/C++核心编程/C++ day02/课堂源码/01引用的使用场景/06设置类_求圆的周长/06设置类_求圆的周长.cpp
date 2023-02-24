#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//自定义的数据类型
//设置圆的类
class Circle
{
public:
	//设置半径的长度
	void setR(double r)
	{
		mR = r;
	}
	//计算圆的周长
	double getL()
	{
		return 2 * 3.14*mR;
	}
public://公有权限
	double mR;//成员变量，成员属性


};

void test()
{
	//数据类型定义变量
	//类实例化对象
	Circle c;
	c.setR(100);
	cout << "圆的周长=" << c.getL() << endl;;
}

void test02()
{
	char *p = "hello";
	char buf[100] = "hello";
	cout << buf << endl;

	string str = "world";
	cout << str << endl;
}

int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

