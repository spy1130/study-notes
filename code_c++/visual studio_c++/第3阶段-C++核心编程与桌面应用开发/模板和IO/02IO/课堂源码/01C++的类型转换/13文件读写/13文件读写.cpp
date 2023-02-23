#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//1.引入头文件
#include<fstream>
//把程序中的信息输出到缓冲区，然后写到文件（写文件）
void test01()
{
	//2.定义流对象
	ofstream ofs;
	//3.打开文件,以写的方式打开，如果没有文件，就创建
	ofs.open("test.txt", ios::out | ios::trunc);
	//4.判断是否打开成功
	if (!ofs.is_open())
	{
		cout << "打开失败" << endl;
	}

	//5.写信息
	ofs << "姓名:悟空" << endl;
	ofs << "年龄:18" << endl;
	ofs << "身高:180cm" << endl;

	//6.关闭文件
	ofs.close();//关闭文件，并刷新缓冲区

}

//把磁盘信息输入到缓冲区，然后读到程序中（读文件）
void test02()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (ifs.is_open() == false)
	{
		cout << "打开失败" << endl;
	}
	//第一种方式读取文件
	//一行一行读取
	/*char buf[1024] = { 0 };
	while (ifs>>buf)
	{
		cout << buf << endl;
	}*/
	//第二种方式读文件
	//char buf[1024] = { 0 };
	//while (!ifs.eof())//判断是否读到文件尾部
	//{
	//	ifs.getline(buf, sizeof(buf));
	//	cout << buf << endl;

	//}
	//第三种方式读取文件
	//单个字符读取
	char c;
	while ((c=ifs.get())!=EOF)
	{
		cout << c;
	}

	//关闭文件
	ifs.close();
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

