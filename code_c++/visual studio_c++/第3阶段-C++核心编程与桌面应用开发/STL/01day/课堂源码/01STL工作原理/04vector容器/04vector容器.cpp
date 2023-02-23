#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<vector>

void printVector(const vector<int> &vec)
{
	for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void printRvector(vector<int> &vec)
{
	for (vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
/*
构造
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。

*/
void test01()
{
	int arr[] = { 2, 3, 1, 9, 8 };
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
	printVector(v);

	printRvector(v);

	vector<int> v2(10, 6);
	printVector(v2);
}
/*
常用赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector&operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。

*/
void test02()
{ 
	vector<int> v;
	v.assign(10, 6);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);

	printVector(v);
	printVector(v2);

	cout << "===================" << endl;

	v.swap(v2);

	printVector(v);
	printVector(v2);

}
/*
大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。

*/

void test03()
{
	//1.resize开辟空间，并初始化
	//2.reserve开辟空间，但不初始化

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);

	cout << "size：" << v2.size() << endl;
	v2.resize(5);
	cout << "size：" << v2.size() << endl;
	printVector(v2);

	v2.reserve(20);
	v2.push_back(20);
	printVector(v2);
	cout << "size：" << v2.size() << endl;
	cout << "capacity:" << v2.capacity() << endl;

	//cout << v2[10] << endl;//err,不能访问未初始化的空间


}

//reserve的作用，预开辟空间
void test04()
{
	vector<int> v;

	v.reserve(10001000);

	int *p = NULL;
	int num = 0;

	for (int i = 0; i < 10001000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}

	cout << "num=" << num << endl;

}

//swap的使用,缩小容量
void test05()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}

	cout << "容量:" << v.capacity() << endl;
	cout << "大小：" << v.size() << endl;

	cout << "----------------" << endl;

	v.resize(10);
	cout << "容量:" << v.capacity() << endl;
	cout << "大小：" << v.size() << endl;

	cout << "----------------" << endl;

	vector<int> v2(v);//调用拷贝构造，容量缩小
	cout << "容量:" << v2.capacity() << endl;
	cout << "大小：" << v2.size() << endl;
	cout << "-------------------" << endl;
	vector<int>(v).swap(v);//匿名对象和v对象交换
	cout << "容量:" << v.capacity() << endl;
	cout << "大小：" << v.size() << endl;
}

/*
数据存取操作
at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[];//返回索引idx所指的数据，越界时，运行直接报错
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素

*/
void test06()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);


	cout << v.front() << endl;
	cout << v.back() << endl;

	v.front() = 100;
	v.back() = 300;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

}

/*
插入和删除操作
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
push_back(ele); //尾部插入元素ele
pop_back();//删除最后一个元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器指向的元素
clear();//删除容器中所有元素

*/

void test07()
{
	vector<int> v;
	for (int i = 0; i < 5; i++)
	{
		v.push_back(i + 1);
	}

	printVector(v);

	v.insert(v.begin() + 1,2, 100);
	printVector(v);

	v.pop_back();
	printVector(v);
	cout << "-------------" << endl;
	v.erase(v.begin());
	printVector(v);

	v.erase(v.begin() + 1, v.end() - 1);
	printVector(v);

	v.clear();
	printVector(v);


}
int main()
{
	test07();
	system("pause");
	return EXIT_SUCCESS;
}

