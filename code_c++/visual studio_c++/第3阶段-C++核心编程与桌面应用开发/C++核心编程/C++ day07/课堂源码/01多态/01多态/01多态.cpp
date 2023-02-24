#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class People
{
public:
	//虚函数
	virtual void Mypro()
	{

	}
};
//1.有继承
class xishi :public People
{
public:
	//2.重写父类的虚函数
	virtual void Mypro()
	{
		cout << "约西施" << endl;
	}
};

class wangzhaojun :public People
{
public:
	
	//重写父类的虚函数
	virtual void Mypro()
	{
		cout << "约王昭君" << endl;
	}
	
};



class diaochan :public People
{
public:
	//重写父类的虚函数
	virtual void Mypro()
	{
		cout << "约貂蝉" << endl;
	}
};

class yangguifei :public People
{
public:
	//重写父类的虚函数
	virtual void Mypro()
	{
		cout << "约杨贵妃" << endl;
	}
};


//同一个操作
void doLogin(People *pro)
{
	pro->Mypro();//产生不同的效果
}

void test()
{
	People *pro = NULL;
	//3.父类指针指向子类对象
	pro = new xishi;
	doLogin(pro);//不同的对象
	delete pro;

	pro = new wangzhaojun;
	doLogin(pro);//不同的对象
	delete pro;

	pro = new diaochan;
	doLogin(pro);//不同的对象
	delete pro;

	pro = new yangguifei;
	doLogin(pro);//不同的对象
	delete pro;
	pro = NULL;

	
	
}

int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}

