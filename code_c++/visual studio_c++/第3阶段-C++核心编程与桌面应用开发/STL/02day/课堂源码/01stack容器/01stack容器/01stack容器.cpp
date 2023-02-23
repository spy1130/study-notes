#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stack>
#include<string>

//栈容器，先进后出
//存储基础数据类型
void test01()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	//输出栈中元素
	while (!s.empty())
	{
		//输出栈顶元素
		cout << s.top() << " ";
		//弹出栈顶元素
		s.pop();
	}
	cout << "size:" << s.size() << endl;
}

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
//存储对象
void test02()
{
	stack<Maker> s;
	s.push(Maker("aaa", 18));
	s.push(Maker("bbb", 19));
	s.push(Maker("ccc", 20));

	while (!s.empty())
	{
		cout << "Name:" << s.top().name << " Age:" << s.top().age << endl;
		s.pop();
	}
	
}

int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

