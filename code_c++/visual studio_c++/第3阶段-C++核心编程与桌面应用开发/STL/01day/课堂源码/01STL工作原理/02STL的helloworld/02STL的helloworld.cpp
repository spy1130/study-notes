#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>//容器
#include<algorithm>//算法的头文件
#include<string>
using namespace std;

//加入算法的回调函数
void MyPrint(int val)
{
	cout << val << " ";
}
//1.存储基础数据类型
void test01()
{
	//容器
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//获取开始位置的迭代器
	vector<int>::iterator begin = v.begin();
	//获取结束位置的迭代器
	vector<int>::iterator end = v.end();
	/*
	void _For_each(_InIt _First, _InIt _Last, _Fn1& _Func)
	{	
		for (; _First != _Last; ++_First)
			_Func(*_First);
	}
	*/
	//遍历算法
	for_each(begin, end, MyPrint);
	cout << endl;

}

//2.容器存储对象
class Maker
{
public:
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};
ostream &operator<<(ostream &out, Maker &m)
{
	out << "Name:" << m.name << " Age:" << m.age << endl;
	return out;
}

void test02()
{
	vector<Maker> v;
	//往容器中存储对象
	v.push_back(Maker("悟空", 18));
	v.push_back(Maker("小林", 19));
	v.push_back(Maker("贝吉塔", 25));
	v.push_back(Maker("龟仙人", 200));
	v.push_back(Maker("短笛", 180));

	//获取开始和结束位置的迭代器
	vector<Maker>::iterator begin = v.begin();
	vector<Maker>::iterator end = v.end();

	while (begin!=end)
	{
		cout << (*begin);
		begin++;

	}
}
//3.存储对象的指针
void test03()
{
	vector<Maker*> v;
	//创建数据
	Maker *m1 = new Maker("悟空", 18);
	Maker *m2 = new Maker("小林", 19);
	Maker *m3 = new Maker("贝吉塔",200 );
	Maker *m4 = new Maker("龟仙人",180 );
	Maker *m5 = new Maker("短笛", 18);

	v.push_back(m1);
	v.push_back(m2);
	v.push_back(m3);
	v.push_back(m4);
	v.push_back(m5);

	vector<Maker*>::iterator begin = v.begin();
	vector<Maker*>::iterator end = v.end();

	while (begin!=end)
	{
		cout << (*begin)->name << " " << (*begin)->age << endl;
		++begin;

	}

	delete m1;
	delete m2;
	delete m3;
	delete m4;
	delete m5;
}

//4.容器嵌套容器
void test04()
{
	vector<vector<int>> vs;

	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	vector<int> v5;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i + 10);
		v2.push_back(i + 10);
		v3.push_back(i + 10);
		v4.push_back(i + 10);
		v5.push_back(i + 10);
	}

	vs.push_back(v1);
	vs.push_back(v2);
	vs.push_back(v3);
	vs.push_back(v4);
	vs.push_back(v5);

	vector<vector<int>>::iterator begin = vs.begin();
	vector<vector<int>>::iterator end = vs.end();

	while (begin!=end)
	{
		vector<int>::iterator sbegin = (*begin).begin();
		vector<int>::iterator send = (*begin).end();

		while (sbegin!=send)
		{
			cout << *sbegin << " ";
			++sbegin;
		}

		cout << endl;
		++begin;
	}
}

int main()
{
	test04();
	system("pause");
	return EXIT_SUCCESS;
}

