#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

class Maker
{
public:
	Maker(int age)
	{
		this->age = age;
	}
	Maker(const Maker&m)
	{
		cout << "拷贝构造" << endl;
	}
public:
	int age;
};

void test()
{
	vector<Maker> v;
	Maker m(10);
	//1.拷贝构造要能被调用
	//2.注意要浅拷贝问题
	v.push_back(m);
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

