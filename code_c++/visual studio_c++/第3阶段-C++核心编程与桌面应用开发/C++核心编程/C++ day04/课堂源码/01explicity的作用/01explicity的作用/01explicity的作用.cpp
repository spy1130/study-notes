#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Maker
{
public:
	//explicit只能放在构造函数前面，构造函数只有一个参数或其他参数有默认值时
	explicit Maker(int n)//防止编译器优化Maker m=10;这种格式
	{

	}
};

int main()
{
	Maker m = 10;
	system("pause");
	return EXIT_SUCCESS;
}

