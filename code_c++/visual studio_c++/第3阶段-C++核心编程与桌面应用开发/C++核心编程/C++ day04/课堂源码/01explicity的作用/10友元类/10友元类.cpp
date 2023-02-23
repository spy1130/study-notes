#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class Building
{
	//声明GoodF类为Building类的友元类
	friend class GoodF;
	friend class GoodF2;
public:
	Building()
	{
		keting = "客厅";
		woshi = "卧室";
	}

public:
	string keting;
private:
	string woshi;
};

class GoodF
{
public:
	void func(Building &bd)
	{
		cout << "访问:" << bd.keting << endl;
		cout << "访问:" << bd.woshi << endl;//通过参数访问私有成员
	}
};
//1.通过传入参数来访问类的私有成员
void test01()
{
	Building bd;
	GoodF f;
	f.func(bd);
}

//2.通过类内指针来访问类的私有成员
class GoodF2
{
public:
	GoodF2()
	{
		cout << "无参构造" << endl;
		pbu = new Building;
	}
	void func()
	{
		cout << "访问:" << pbu->keting << endl;
		cout << "访问:" << pbu->woshi << endl;//通过成员指针访问私有成员
		
	}
	//拷贝构造
	GoodF2(const GoodF2 &f2)
	{
		cout << "拷贝构造" << endl;
		//1.申请空间
		pbu = new Building;//new已经调用了Building的构造函数,不用再复制对象属性
		
		

	}
	~GoodF2()
	{
		cout << "析构函数" << endl;
		if (pbu != NULL)
		{
			cout << "pbu" << endl;
			delete pbu;
		}
	}
public:
	Building *pbu;
};

void test02()
{
	GoodF2 f;
	f.func();

	GoodF2 f2 = f;

}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

