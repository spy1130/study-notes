#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>

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
private://私有
	int id;
	string name;

protected://保护
	int a;
};
//继承，公有继承
class Son :public Maker
{
public:
	void func()
	{   //下面这个a是从公有的复制出来的
		a = 20;//子类的类内可以方法父类的保护权限的成员
		
	}
};
//类外不能访问私有权限的成员
//类外可以访问公有权限的成员
//类外不能访问保护权限的成员
//子类的类内可以方法父类的保护权限的成员
//类内是没有权限之分

int main(){
    Maker s;
    s.set("spric",031130);
    s.printMaker();
    system("pause");
    return EXIT_SUCCESS;
}