#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1.new创建基础类型的数组
void test01()
{
	//申请基础数据类型的数组
	int *pInt = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//不推荐
	for (int i = 0; i < 10; i++)
	{
		pInt[i] = i + 1;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << pInt[i] << " ";
	}

	cout << endl;

	char *pChar = new char[64];
	memset(pChar, 0, 64);
	strcpy(pChar, "小话");
	cout << pChar << endl;

	//注意：如果new时有中括号，那么delete时也要有中括号
	delete[] pInt;
	delete[] pChar;

}

//2.new创建对象数组
class Maker
{
public:
	Maker()
	{
		cout << "构造函数" << endl;
	}

	Maker(int a)
	{
		cout << "有参构造函数" << endl;
	}
	~Maker()
	{
		cout << "析构函数" << endl;
	}
};

void test02()
{
	Maker *ms = new Maker[2];//调用无参构造

	delete[] ms;

	//大部分编译器不支持这种写法，(聚合初始化）
	//Maker *ms2 = new Maker[2]{Maker(10), Maker(20)};
}

//3.delete void*可能出错,不会调用对象的析构函数
void test03()
{
	void *m = new Maker;

	//如果用void*来接new的对象，那么delete时不会调用析构函数
	delete m;
	//在编译阶段，那么编译器就确定好了函数的调用地址，
	//C++编译器不认识void*,不知道void*指向那个函数，所以不会调用析构函数
	//这种编译方式叫静态联编
}
//4.C和C++的申请和释放堆区空间不要混用
void test04()
{
	Maker *m = new Maker;

	free(m);
}

int main()
{
	test04();
	system("pause");
	return EXIT_SUCCESS;
}

