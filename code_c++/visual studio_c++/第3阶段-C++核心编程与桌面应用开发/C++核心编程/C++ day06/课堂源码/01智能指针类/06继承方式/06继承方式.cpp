#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Father
{
public:
	int a;
private:
	int b;
protected:
	int c;
};

class Son1 :public Father
{
public:
	void func()
	{
		a;
		//b;err
		c;
	}
	/*
	公有继承：
	1.父类的公有属性成员，到子类还是公有
	2.父类的私有属性成员，到子类不能访问
	3.父类的保护属性成员，到子类还是保护
	*/
};
void test01()
{
	Son1 s1;
	s1.a;
	//s1.b;err
	//s1.c;err
}
//保护继承
class Son2 :protected Father
{
public:
	void func()
	{
		a;
		//b;err
		c;
		/*
		保护继承
		1.父类的公有属性成员，到子类是保护
		2.父类的私有属性成员，到子类不能访问
		3.父类的保护属性成员，到子类还是保护
		*/
	}
};

void test02()
{
	Son2 s2;
	//s2.a;err
	//s2.b;err
	//s2.c;
}

class Son3 :private Father
{
public:
	void func()
	{
		a;
		//b;err
		c;
		/*
		私有继承
		1.父类的公有属性成员，到子类是私有
		2.父类的私有属性成员，到子类不能访问
		3.父类的保护属性成员，到子类还是私有
		*/
	}
};
class Son33 :public Son3
{
public:
	void func()
	{
		//a;err
		//c;err
	}
};
void test03()
{
	Son3 s3;
	//s3.a;err
	//s3.b;err
	//s3.c;err
}
int main()
{

	system("pause");
	return EXIT_SUCCESS;
}

