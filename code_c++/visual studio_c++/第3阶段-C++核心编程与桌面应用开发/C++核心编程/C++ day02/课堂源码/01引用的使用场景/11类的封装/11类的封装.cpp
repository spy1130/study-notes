#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//封装：1,把属性和方法放到类中,2.给这些数据赋予权限
class Maker
{
public://公有权限
	void set(string Name,int Id)
	{
		id = Id;
		name = Name;
	}
	void printMaker()
	{
		cout << "id=" << id << " name=" << name << endl;
	}
	void get()
	{
		cout << "Maker a=" << a << endl;
	}
private://私有
	int id;
	string name;

protected://保护
	int a;
};
//继承，公有继承
class Son :public Maker//子类 :继承方式 父类
{
public:
	void func()
	{
		//下面这个a是从父类复制过来的
		a = 20;//子类的类内可以方法父类的保护权限的成员
		
	}
	void getS()
	{
		cout << "Son a=" << a << endl;
	}

};

void test01()
{
	Maker m;
	Son s;
	s.func();
	m.get();
	s.getS();

}
//类外不能访问私有权限的成员
//类外可以访问公有权限的成员
//类外不能访问保护权限的成员
//子类的类内可以方法父类的保护权限的成员
//类内是没有权限之分

void test()
{
	Maker m;
	m.set("小花",1);
	m.printMaker();
	

}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}

