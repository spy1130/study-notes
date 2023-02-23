#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Cube
{
public:
	//初始化变量
	void init()
	{
		mL = 0;
		mW = 0;
		mH = 0;
		//shift+alt
	}

	//set
	void setL(int l)
	{
		mL = l;

	}
	void setW(int w)
	{
		mW = w;

	}
	void setH(int h)
	{
		mH = h;

	}

	//get
	int getL()
	{
		return mL;
	}
	int getW()
	{
		return mW;
	}
	int getH()
	{
		return mH;
	}

	//求立方体的面积
	int caculateS()
	{
		return 2 * mL*mW + 2 * mL*mH + 2 * mW*mH;
	}
	//求立方体的体积
	int caculateV()
	{
		return mL*mH*mW;
	}
	//成员函数比较立方体
	bool CompareCube(Cube &cube)
	{
		if (getL() == cube.getL() && getW() == cube.getW() && getH() == cube.getH())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	int mL;
	int mW;
	int mH;
};

bool IsCompareCube(Cube &c1,Cube &c2)
{
	if (c1.getH() == c2.getH() && c1.getL() == c2.getL() && c1.getW() == c2.getW())
	{
		return true;
	}

	return false;
}

int main()
{
	Cube c1, c2;
	//初始化对象
	c1.init();
	c2.init();

	//设置立方体的长宽高
	c1.setL(10);
	c1.setW(20);
	c1.setH(30);

	c2.setL(10);
	c2.setW(30);
	c2.setH(30);

	if (c1.CompareCube(c2))
	{
		cout << "两个立方体相等" << endl;
	}
	else
	{
		cout << "两个立方体不相等" << endl;
	}

	if (IsCompareCube(c1, c2))
	{
		cout << "全局 两个立方体相等" << endl;
	}
	else
	{
		cout << "全局 两个立方体不相等" << endl;
	}


	system("pause");
	return EXIT_SUCCESS;
}

