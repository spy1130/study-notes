#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//自定义数据类型
class Maker
{
public:
	void Init()//初始化函数
	{
		name = "翠花";
		age = 18;
	}
	//set get方法
	void setN(string mName)
	{
		name = mName;
	}
	string getN()
	{
		return name;
	}
	void setA(int mAge)
	{
		if (mAge >= 0 && mAge <= 100)
		{
			age = mAge;
		}
	}
	int getA()
	{
		return age;
	}

	//打印方法
	void printMaker()
	{
		cout << "name:" << name << " age:" << age << endl;
	}
private:
	string name;
	int age;
};

int main()
{
	//Maker是类，m的对象
	Maker m;

	m.Init();
	m.printMaker();
	m.setN("美丽");
	m.setA(30);
	m.printMaker();
	cout << "name:" << m.getN() << " age:" << m.getA() << endl;;
	

	system("pause");
	return EXIT_SUCCESS;
}

