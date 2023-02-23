#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
using namespace std;

void test()
{
	deque<int>::iterator it;
	it++;
	it--;
	it + 2;
}
void printDeque(const deque<int> &deq)
{
	for (deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
/*
构造
deque<T> deqT;//默认构造形式
deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem);//构造函数将n个elem拷贝给本身。
deque(const deque &deq);//拷贝构造函数。

*/
void test01()
{
	int arr[] = { 1, 3, 8, 9, 2 };
	deque<int> d1(arr, arr + sizeof(arr) / sizeof(int));
	printDeque(d1);

	deque<int> d2(10, 6);
	printDeque(d2);
}
/*
赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
deque&operator=(const deque &deq); //重载等号操作符
swap(deq);// 将deq与本身的元素互换

*/
void test02()
{
	int arr[] = { 1, 3, 8, 9, 2 };
	deque<int> d1(arr, arr + sizeof(arr) / sizeof(int));
	printDeque(d1);

	deque<int> d2;
	d2.assign(d1.begin(), d1.end());
	d2.push_back(100);
	printDeque(d2);

	cout << "------------" << endl;
	d1.swap(d2);
	printDeque(d1);
	printDeque(d2);
}
/*
大小操作
deque.size();//返回容器中元素的个数
deque.empty();//判断容器是否为空
deque.resize(num);//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。

*/

void test03()
{
	deque<int> d;
	cout << d.size() << endl;

	if (d.empty())
	{
		cout << "空" << endl;
	}

	d.resize(10, 7);
	printDeque(d);

}
/*
双端插入和删除操作
push_back(elem);//在容器尾部添加一个数据
push_front(elem);//在容器头部插入一个数据
pop_back();//删除容器最后一个数据
pop_front();//删除容器第一个数据

at(idx);//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
operator[];//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
front();//返回第一个数据。
back();//返回最后一个数据

*/

void test04()
{
	deque<int> d;
	d.push_back(10);
	d.push_front(20);
	printDeque(d);

	d[0] = 200;
	printDeque(d);
	//d.at(8) = 800;err
	d.at(1) = 100;
	printDeque(d);

	d.pop_back();
	d.pop_front();
	printDeque(d);
}

/*
插入操作
insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。

*/
void test05()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);
	d.push_back(50);

	d.insert(d.begin() + 1, 100);
	d.insert(d.begin() + 2, 2, 0);
	printDeque(d);

	deque<int> d2;
	d2.push_back(1000);
	d2.push_back(2000);
	d2.push_back(3000);

	d2.insert(d2.begin() + 1, d.begin(), d.end());
	printDeque(d2);
}
/*
删除操作
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。

*/
void test06()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_back(40);
	d.push_back(50);
	deque<int>::iterator it=d.erase(d.begin() + 1, d.end() - 1);
	cout << *it << endl;
	printDeque(d);
	d.clear();
	printDeque(d);
}
int main()
{
	test06();

	system("pause");
	return EXIT_SUCCESS;
}

