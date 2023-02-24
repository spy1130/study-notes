#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"Circle.h"

//全局函数判断点和圆的关系
void G_isPointAndCircle(Circle &c, Point &p)
{
	//获取点和圆之间距离的平方
	double distance = pow((p.getX() - c.getHear().getX()), 2) + pow((p.getY() - c.getHear().getY()), 2);

	//半径的平方
	double tmpR = pow(c.getR(), 2);

	if (distance > tmpR)
	{
		cout << "全局 点在圆外" << endl;
	}
	else if (distance == tmpR)
	{
		cout << "全局 点在圆上" << endl;
	}
	else
	{
		cout << "全局 点在圆内" << endl;
	}
}

int main()
{
	//实例化点对象
	Point p;
	p.setX(10);
	p.setY(10);
	//实例化圆对象
	Circle c;
	c.SetHear(10, 20);
	c.SetR(5);

	c.isPointAndCircle(p);

	G_isPointAndCircle(c, p);

	system("pause");
	return EXIT_SUCCESS;
}

