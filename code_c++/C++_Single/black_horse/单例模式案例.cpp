#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>

//需求，获取打印机使用的次数
class Printer
{
private:
	//1.把无参构造和拷贝构造私有化
	Printer()
	{
		mcount = 0;
	}
	Printer(const Printer &p)
	{

	}
public:
	static Printer *getPrinter()
	{
		return p;
	}

	void printPrinter(string name)
	{
		cout << name << ":打印" << endl;
		mcount++;
	}
	int getCount()
	{
		return mcount;
	}
private:
	int mcount;//记录打印打印的次数
	//2.定义静态成员指针
	static Printer *p;
};
//3.类外进行初始化，new对象
Printer *Printer::p = new Printer;

void test()
{
	//销售部
	Printer *p1 = Printer::getPrinter();
	p1->printPrinter("销售部");

	//技术部
	Printer *p2 = Printer::getPrinter();
	p2->printPrinter("技术部");

	//公关部
	Printer *p3 = Printer::getPrinter();
	p3->printPrinter("公关部");

	Printer *p4 = Printer::getPrinter();
	cout << "打印使用的次数:"<<p4->getCount() << endl;

}

int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}

