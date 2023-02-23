## 01.STL的介绍（重点）

1.STL(Standard TemplateLibrary,标准模板库)

2.STL提供了六大组件:容器，算法，迭代器，仿函数，适配器，空间配置器

​	容器：各种数据结构

​	算法：各种常用的算法（冒泡，排序）

​	迭代器：扮演了容器与算法之间的胶合剂（类似于指针等）

​	仿函数：行为类似函数，可作为算法的某种策略

​	适配器：一种用来修饰容器或者仿函数或迭代器接口的东西

​	空间配置器：负责空间的配置与管理

STL六大组件的交互关系，容器通过空间配置器取得数据存储空间，算法通过迭代器存储容器中的内容，仿函数可以协助算法完成不同的策略的变化，适配器可以修饰仿函数。

## 02.三大组件（重点）

容器：**序列式容器**和**关联式容器**

序列式容器：序列式容器就是容器元素在容器中的位置是由元素进入容器的时间和地点来决定

关联式容器：关联式容器是指容器已经有了一定的规则，容器元素在容器中的位置由容器的规则来决定

算法分为:**质变算法**和**非质变算法**

质变算法：：是指运算过程中会更改区间内的元素的内容

非质变算法：是指运算过程中不会更改区间内的元素内容

迭代器：重点学习双向迭代器和随机访问迭代器

双向迭代器：++,--可以访问下一个元素和上一个元素

随机访问迭代器：+2，可以跳2个元素访问元素

三大组件的关系：容器存储数据，并且提供迭代器，算法使用迭代器来操作容器中的元素

## 03.STL的工作机制（重点）

```
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//数组容器
template<class T>
class MyArray
{
public:

	//保护原生指针，给原生指针取别名
	typedef T* iterator;
	MyArray()
	{
		mCapacity = 10;
		mSize = 10;
		p = new T[mCapacity];
		for (int i = 0; i < mCapacity; i++)
		{
			p[i] = i + 1;
		}
	}

	//提供迭代器，开始位置的迭代器
	T* begin()
	{
		return p;
	}

	//返回结束位置的迭代器
	T* end()
	{
		return p + mSize;
	}


public:
	T* p;
	int mCapacity;
	int mSize;
};

//算法
template<class T>
void printArray(T begin,T end)
{
	for (; begin != end; ++begin)
	{
		cout << *begin << " ";
	}
	
}
void test01()
{
	MyArray<int> arr;

	//获取容器提供的开始位置迭代器
	MyArray<int>::iterator begin=arr.begin();
	//获取容器提供的结束位置迭代器
	MyArray<int>::iterator end = arr.end();

	printArray(begin, end);
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}


```

## 04.STL的hello world（了解）

```
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
//1.存储数据
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


```



## 05.string容器（重点）

1.数据结构：连续的存储空间，用一个char*指向这片空间

2.迭代器:随机访问迭代器

3.常用的api：

​	1.构造

​	2.基本赋值

​	3.存取字符

​	4.拼接

​	5.查找和替换

​	6.比较

​	7.子串

​	8.插入和删除

​	9.string和const char*转换

4.常用的api中的注意:

​	1.[]和at区别：[]如果越界，不抛异常，直接挂。at会抛异常

​	2.字符串内存重新分配，[]和at获取的字符引用，再次使用时，可以能会出错

​	3.string和char *的区别：string是一个类，char *是一个指针

​	

```
void test10()
{
	string s = "abcde";
	char &a = s[2];
	char &b = s[3];

	a = '1';
	b = '2';
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << s << endl;
	cout << "字符串的原空间地址:" << (int*)s.c_str() << endl;

	s = "fdasfdasfdsafdasherewrkewhsaferew";
	cout << "字符串的空间地址:" << (int*)s.c_str() << endl;

	//原空间被释放，但是a还是被释放的s[2]空间的别名，如果操作非法的空间，会出错
	//a = '3';


}
```



## 06.vector容器（重点，常用容器）

1.数据结构:连续存储空间

2.迭代器：随机迭代器

3.vector容器动态增长原理

​	1.当存储空不够时，会开辟另一块大的空间，然后把数据拷贝过去，最后在销毁原来的空间

​	2.申请的空间,会比用户需求大一点

​	3.重新分配空间，那么原来的迭代器就会失效

4.常用的api:

​	1.构造

​	2.赋值操作

​	3.大小操作

​	4.数据存取

​	5.插入和删除

5.常用的api中的注意:

​	1.resize开辟空间，并初始化。reserve开辟空间，但不初始化.没有初始化的空间不能访问

6.reserve作用：如果容器要存储大量数据时，要先开辟空间，避免多次申请空间

7.swap作用:缩小容器的容量

## 07.deque容器

1.数据结构:逻辑上是连续的存储空间，实际上的由很多块定量的块空间，通过中控制连接起来

2.迭代器:随机迭代器

3.常用的api：

​	1.构造

​	2.赋值

​	3.大小

​	4.双端插入和删除操作

​	5.插入和删除操作

## 08.打分案例

1.目的：5个学生，10个评委，10个评委的分数去掉最高和最低分，取平均分就是学生的分数

2.思路：

​	1.抽象学生

​	2.使用vector容器存储学生

​	3.把分数放入deque容器，然后对deque容器进行排序，之后删除首尾元素

3.流程：

​	1.创建学生

​	2.评委给学生打分

​	3.根据学生的分数排名并打印

```
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>//算法头文件
#include<ctime>
using namespace std;
//目的：5个学生，10个评委，10个评委的分数去掉最高和最低分，取平均分就是学生的分数
//抽象学生
class Student
{
public:
	string name;
	int mScore;
};

//1.创建学生
void CreateStudent(vector<Student> &vstu)
{
	string setName = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		//创建学生
		Student stu;
		stu.name = "学生";
		stu.name += setName[i];
		stu.mScore = 0;
		vstu.push_back(stu);//把学生放入容器
	}
}
//2.评委给学生打分
void SetScore(vector<Student> &vstu)
{
	srand((unsigned int)time(NULL));
	//遍历学生
	for (vector<Student>::iterator it = vstu.begin(); it != vstu.end(); ++it)
	{
		//保存分数
		deque<int> dScore;
		//评委给学生打分
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 70 + 30;
			dScore.push_back(score);
		}
		//排序
		sort(dScore.begin(),dScore.end());
		//去掉最高分和最低分
		dScore.pop_back();
		dScore.pop_front();

		//求总分
		int tota = 0;
		for (deque<int>::iterator sit = dScore.begin(); sit != dScore.end(); ++sit)
		{
			tota += (*sit);
		}

		//求平均分
		int agescore = tota / dScore.size();

		//平均分存储到对象中
		it->mScore = agescore;

	}
}
//谓词
bool mycomapre(Student &s1, Student &s2)
{
	return s1.mScore > s2.mScore;
}
//3.排名并打印
void ShowStudentScore(vector<Student> &vstu)
{
	//排序算法，mycomapre改变sort的默认规则
	sort(vstu.begin(), vstu.end(), mycomapre);
	for (vector<Student>::iterator it = vstu.begin(); it != vstu.end(); ++it)
	{
		cout << "Name:" << it->name << " Score:" << it->mScore << endl;
	}


}
void test()
{
	//存储学生的容器
	vector<Student> vstu;

	//1.创建学生
	CreateStudent(vstu);
	//2.评委给学生打分
	SetScore(vstu);
	//3.排名并打印
	ShowStudentScore(vstu);

}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}


```







