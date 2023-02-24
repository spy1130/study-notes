#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
	//写成成员函数，那么只需要一个参数，这个参数是加号的右边
	Maker operator+(Maker &m2)
	{
		Maker temp(this->id + m2.id, this->age + m2.age);

		return temp;
	}
public:
	int id;
	int age;
};

//全局方式 //2.编译器调用这个函数
//Maker operator+(Maker &p1,Maker &p2)//3.编译器检查参数是否对应，第一个参数是加的左边，第二参数是加号的右边
//{
//	Maker temp(p1.id + p2.id, p1.age + p2.age);
//
//	return temp;
//}

void test01()
{
	Maker m1(1, 20);
	Maker m2(2, 22);
	//+也叫双目运算符
	Maker m3=m1 + m2;//1.编译器看到两个对象相加，那么编译器会去找有没有叫operator+的函数

	cout << "id:" << m3.id << " age:" << m3.age << endl;

	//复数加
	Maker m4 = m1 + m2 + m3;
	cout << "id:" << m4.id << " age:" << m4.age << endl;
}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}

