#pragma once
#include"Point.h"
#include<cmath>//数据公式的库
#include<iostream>
using namespace std;
class Circle
{
public:
	void SetR(int r);
	void SetHear(Point &p);
	void SetHear(int x, int y);

	int getR();
	Point getHear();

	//判断点和圆的关系
	void isPointAndCircle(Point &p);
	
private:
	int mR;//半径
	Point mHear;//圆心
};

