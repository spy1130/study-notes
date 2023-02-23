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
		score = 100;
	}
	//常函数,1.函数的()后面添加const,该函数是常函数
	void printMaker()const
	{
		//id = 100;err//2.常函数内不能修改普通成员变量
		//3.const修饰的是this指针指向的空间中的变量不能改变
		//Maker *const this;
		//const Maker*const this;这是常函数修饰的
		score = 200;//4.mutable修饰的成员变量在常函数中可以修改
		cout << "score=" << score << endl;
	}
public:
	int id;
	int age;
	mutable int score;//mutable修饰的成员变量

};
void test01()
{
	Maker m(1, 18);
	m.printMaker();
}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}

