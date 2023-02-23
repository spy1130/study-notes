#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template<class T>
class Maker
{
public:
	Maker()
	{
		a = 0;
		b = 0;

	}
	Maker(T r,T i)
	{
		a = r;
		b = i;
	}
	Maker Maker_add(Maker &c2)
	{
		Maker<T> c;
		c.a = this->a + c2.a;
		c.b = this->b + c2.b;
		return c;
	}

	Maker operator+(Maker &c2)
	{
		Maker tmp(this->a + c2.a, this->b + c2.b);
		return tmp;
	}

	void printMaker()
	{
		cout << "(" << a << "," << b << ")" << endl;
	}
private:
	T a;
	T b;
};

void test()
{
	Maker<int> c1(3, 4);
	Maker<int> c2(5, -10);
	Maker<int> c3;
	c3 = c1.Maker_add(c2);

	cout << "c1+c2=";
	c3.printMaker();

	Maker<double> d1(3.3, 4.4);
	Maker<double> d2(5.5, -10.1);
	Maker<double> d3;
	d3 = d1.Maker_add(d2);

	cout << "d1+d2=";
	d3.printMaker();
}

void test02()
{
	Maker<int> c1(3, 4);
	Maker<int> c2(5, -10);
	Maker<int> c3;
	c3 = c1 + c2;

	cout << "c1+c2=";
	c3.printMaker();
}

int main()
{
	
	system("pause");
	return EXIT_SUCCESS;
}

