#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

class Maker
{
public:
	//写
	void setName(string Name)
	{
		name = Name;
	}
	//读
	string getName()
	{
		return name;
	}
	//写
	void setAge(int Age)
	{
		//可以保护属性的合法性
		if (Age > 0 && Age < 120)
		{
			age = Age;
		}
		
	}
	//读
	int getId()
	{
		return id;
	}
private:
	string name;
	int age;
	int id;

};






int main()
{
	Maker m;
	m.setAge(1000);
	system("pause");
	return EXIT_SUCCESS;
}

