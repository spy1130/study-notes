#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>


class Student
{
public://公有
	//设置名字
	 void setName(string Name)//成员方法，成员函数
	{
		name = Name;
	}
	//设置ID
	void setId(int Id)
	{
		id = Id;
	}

	void myprint()
	{
		cout << "姓名:" << name << "\n学号:" << id << endl;
	}
private://私有权限
	string name;//成员属性
	int id;//成员属性

};

int main()
{
	Student s;
	s.setName("贝吉塔");
	s.setId(1);
	s.myprint();

	
	system("pause");
	return EXIT_SUCCESS;
}

