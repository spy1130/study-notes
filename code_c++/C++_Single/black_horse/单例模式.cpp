#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//单例模式是一个类只能实例化一个对象
class Maker
{
	//1.把构造函数私有化
private:
	Maker()
	{
	}
	Maker(const Maker &m)
	{
		
	}
public:
	//静态成员函数，访问静态成员变量
	//4.把指针的权限设置为私有，然后提供一个静态成员函数让外面获取这个指针
	static Maker* getMaker()
	{
		return pMaker;
	}

private:
	//2.定义一个类内的静态成员指针
	static Maker *pMaker;
};
//3.在类外初始化时，new一个对象
Maker *Maker::pMaker = new Maker;//这里可以new是因为有Maker::作用域，编译器这时把它当成在类内

void test()
{
	//Maker m;
	Maker *m = Maker::getMaker();
	Maker *m2 = Maker::getMaker();
	cout << "m=" << m << endl;
	cout << "m2=" << m2 << endl;

	//Maker m3 = *m;//调用拷贝构造,这里会产生新对象，所以要把拷贝构造也私有化
	//cout << "m3=" << &m3 << endl;
	
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

