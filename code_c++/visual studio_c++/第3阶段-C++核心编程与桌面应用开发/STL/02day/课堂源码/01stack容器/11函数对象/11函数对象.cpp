#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<functional>
#include<algorithm>
#include<vector>

void test()
{
	vector<int> v;
	v.push_back(8);
	v.push_back(1);
	v.push_back(6);
	v.push_back(3);
	v.push_back(7);


	sort(v.begin(), v.end(), greater<int>());

	for_each(v.begin(), v.end(), [](int val){cout << val << " "; });
	//[](int val){cout << val << " "; }//匿名函数


}

void func()
{

}

struct Myfunc//函数对象有类型
{
public:
	Myfunc()
	{
		n = 0;
	}
	void operator()()//函数对象有自己的状态
	{
		cout << "hello" << endl;
	}
public:
	int n;

};

void test01()
{
	plus<int> myplus;
	cout << myplus(10, 20) << endl;


}

int main()
{
	

	system("pause");
	return EXIT_SUCCESS;
}

