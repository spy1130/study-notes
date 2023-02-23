#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	Maker()
	{
		id = 0;
		age = 0;
	}
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
public:
	int id;
	int age;
};

void test()
{
	Maker m1(10, 20);
	Maker m2;

	m2 = m1;//赋值操作
	//默认的赋值运算符重载函数进行了简单的赋值操作
	cout << m2.id << " " << m2.age << endl;
}

class Student
{
public:
	Student(const char *name)
	{
		pName = new char[strlen(name) + 1];
		strcpy(pName, name);
	}
	//防止浅拷贝
	Student(const Student &stu)
	{
		cout << "拷贝构造" << endl;
		pName = new char[strlen(stu.pName) + 1];
		strcpy(pName, stu.pName);
	}
	//重写赋值运算符重载函数
	Student &operator=(const Student &stu)
	{
		//1.不能确定this->pName指向的空间是否能装下stu中的数据，所以先释放this->pName指向的空间
		if (this->pName != NULL)
		{
			delete[] this->pName;
			this->pName = NULL;
		}

		//2.申请堆区空间，大小由stu决定
		this->pName = new char[strlen(stu.pName) + 1];
		//3.拷贝数据
		strcpy(this->pName, stu.pName);

		//4.返回对象本身
		return *this;
	}	

	~Student()
	{
		if (pName != NULL)
		{
			delete[] pName;
			pName = NULL;
		}
	}

	void printStudent()
	{
		cout << "Name:" << pName << endl;
	}
public:
	char *pName;
};

void test02()
{
	Student s1("悟空");
	Student s2("小林");

	s1.printStudent();
	s2.printStudent();

	s1 = s2;//赋值操作

	s1.printStudent();
	s2.printStudent();
	
	//复数运算不会出错
	//s1 = s2 = s3;
}
//赋值运算符重载中为什么要返回引用
void test03()
{
	Student s1("a");
	Student s2("b");
	Student s3("c");

	s1 = s2 = s3;//s3赋值s2,s2赋值给s1

	cout << &(s2 = s3) << endl;
	cout << &s2 << endl;
	//如果返回的是值，s2=s3这个表达式会产生一个新的对象
	//s1=s2=s3,赋值运算符本来的寓意，是s3赋值s2,s2赋值给s1
	//也就是说s2=s3这个表达式要返回s2这个对象，所以要返回引用

}

int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

