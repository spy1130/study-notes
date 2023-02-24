#include "Circle.h"

void Circle::SetR(int r)
{
	mR = r;
}
void Circle::SetHear(Point &p)
{
	mHear.setX(p.getX());
	mHear.setY(p.getY());
}
void Circle::SetHear(int x, int y)
{
	mHear.setX(x);
	mHear.setY(y);
}

int Circle::getR()
{
	return mR;
}
Point Circle::getHear()
{
	return mHear;
}

//判断点和圆的关系
void Circle::isPointAndCircle(Point &p)
{
	//获取圆心和点之间距离的平方
	// distance =pow(x2-x1,2)+pow(y2-y1,2)
	double distance = pow((p.getX()-mHear.getX()), 2)+pow((p.getY()-mHear.getY()),2);

	//半径的平方
	double tmpR = pow(mR, 2);

	if (distance > tmpR)
	{
		cout << "点在圆外" << endl;
	}
	else if (distance == tmpR)
	{
		cout << "点在圆上" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}
