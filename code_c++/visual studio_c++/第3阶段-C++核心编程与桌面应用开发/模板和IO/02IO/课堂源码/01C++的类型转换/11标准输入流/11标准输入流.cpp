#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
/*
cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串
cin.getline()//取一行，换行符丢弃
cin.ignore()//忽略
cin.peek()//偷窥
cin.putback()//放回

*/
void test01()
{
	//如果输入的是as
	//char c = cin.get();//a
	//cout << c << endl;

	//c = cin.get();//s
	//cout << c << endl;

	//c = cin.get();//换行
	//cout << c << endl;

	//c = cin.get();//阻塞
	//cout << c << endl;

	//char c1 = '0';
	//cin.get(c1);

	//cout << c1 << endl;

	char ch1, ch2, ch3, ch4;
	cin.get(ch1).get(ch2).get(ch3).get(ch4);
	cout << ch1 << ch2 << ch3 << ch4 << endl;

}
void test02()
{
	char buf[1024] = { 0 };
	//cin.get(buf, 1024);//读取缓冲区时，换行不拿走
	//char c = cin.get();
	//if (c == '\n')
	//{
	//	cout << "换行还在缓冲区" << endl;
	//}
	//cout << buf << endl;

	cin.getline(buf, 1024);//读取缓冲的一行数据，换行符丢弃
	char c = cin.get();//阻塞
	if (c == '\n')
	{
		cout << "换行还在缓冲区" << endl;
	}
	cout << buf << endl;
}
//忽略，参数是N，表示忽略N个字符，如果没有参数，表示忽略一个字符
void test03()
{
	/*cin.ignore();
	char c = cin.get();
	cout << c << endl;*/

	cin.ignore(3);
	char c1 = cin.get();
	cout << c1 << endl;
}

void test04()
{
	char c = cin.peek();//偷窥第一个字符
	cout << c << endl;

	char c2 = cin.get();
	cout << c2 << endl;
}

void test05()
{
	char c = cin.get();
	cout << c << endl;
	cin.putback(c);//放回

	char buf[1024] = { 0 };
	cin.getline(buf, 1024);
	cout << buf << endl;
}

//判断用户输入的是字符串还是数字
void test06()
{
	cout << "请输入一个字符串或数字" << endl;

	char c=cin.peek();

	if (c >= '0'&&c <= '9')
	{
		int num;
		cin >> num;
		cout << "输入的数字是:" << num << endl;
	}
	else
	{
		char buf[1024] = { 0 };
		cin >> buf;
		cout << "输入的字符串是:" <<buf << endl;
	}
}

//输入一个0到10的数字，直到输入正确为止
void test07()
{
	int num;

	while (1)
	{
		cin >> num;
		if (num >= 0 && num <= 10)
		{
			cout << "输入正确" << endl;
			break;
		}
		cout << "重新输入：" << endl;
		//重置标志位
		cin.clear();
		//清空缓冲区
		//cin.sync();
		//2015
		char buf[1024] = { 0 };
		cin.getline(buf, 1024);

		//打印标志位
		cout << cin.fail() << endl;

	}
}

int main()
{
	test07();

	system("pause");
	return EXIT_SUCCESS;
}

