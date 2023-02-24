#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//爷爷
//被虚继承的基类叫虚基类
class Animal
{
public:
	Animal()
	{
		
	}
public:
	
};
//用虚继承的方法解决菱形继承中的二义性问题
//虚继承
class Sheep : virtual public Animal
{

};
//虚继承
class Camel :virtual public Animal
{
	/*
	class Camel     size(8):
	+---
	0      | {vbptr}
	+---
	+--- (virtual base Animal)
	4      | mA
	+---

	Camel::$vbtable@:
	0      | 0
	1      | 4 (Cameld(Camel+0)Animal)
	*/
};

class SheepCamel :public Sheep, public Camel
{
public:
	
};

void test()
{
	Camel c;
	cout << sizeof(c) << endl;
	

}

void test02()
{
	Sheep s;
	

	//1.&s;
	//2.(int*)&s;强转为int*类型
	//3.*(int*)&s;//获取指针中的地址
	//4.(int *)*(int*)&s;//指向表的首地址
	//5.(int *)*(int*)&s+1;//指向了表存储偏移量的地址
	//6.*((int *)*(int*)&s+1)//这就是偏移量
	cout << *((int *)*(int*)&s + 1) << endl;

	//1.&s
	//2.(char*)&s;
	//3.(char*)&s+*((int *)*(int*)&s + 1)
	//4.把类型转换为Animal指针类型
	//cout << ((Animal*)((char*)&s + *((int *)*(int*)&s + 1)))->mA << endl;


}
class A
{
public:
	int a;
};
class B :public A
{
public:

};
class C :public B
{

};
void test03()
{
	C c;
	c.a;
}
int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

