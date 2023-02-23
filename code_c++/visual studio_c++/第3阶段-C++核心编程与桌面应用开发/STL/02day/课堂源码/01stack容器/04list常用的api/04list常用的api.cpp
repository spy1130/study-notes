#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<list>
#include<vector>
#include<algorithm>

void printList(const list<int> &mylist)
{
	for (list<int>::const_iterator it = mylist.begin(); it != mylist.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
/*
构造
list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem);//构造函数将n个elem拷贝给本身。
list(const list &lst);//拷贝构造函数。

*/
void test01()
{
	list<int> mylist1(10, 6);
	list<int> mylist2(++mylist1.begin(), --mylist1.end());

	printList(mylist2);
}

/*
数据元素插入和删除操作
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。

*/

bool myfunc(int val)
{
	return val > 300;
}
void test02()
{
	list<int> mylist;
	mylist.push_back(10);
	mylist.push_back(20);
	mylist.push_back(30);
	mylist.push_back(40);
	mylist.push_back(50);
	mylist.push_front(100);
	mylist.push_front(200);
	mylist.push_front(300);
	mylist.push_front(400);

	vector<int> v;
	v.push_back(1000);
	v.push_back(2000);
	v.push_back(3000);

	mylist.insert(mylist.begin(), v.begin(), v.end());

	printList(mylist);

	mylist.remove(300);

	printList(mylist);

	//要删除大于300的数据
	mylist.remove_if(myfunc);
	printList(mylist);
}
/*
大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(num);//重新指定容器的长度为num，
若容器变长，则以默认值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem);//重新指定容器的长度为num，
若容器变长，则以elem值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。

*/
void test03()
{
	list<int> mylist;
	for (int i = 0; i < 5; i++)
	{
		mylist.push_back(i + 1);
	}

	cout << "size:" << mylist.size() << endl;

	cout << mylist.empty() << endl;
	if (mylist.empty())
	{
		cout << "空" << endl;
	}
	else
	{
		cout << "不为空" << endl;
	}

	mylist.resize(3);

	printList(mylist);

}
/*
赋值操作,数据的存取
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
list&operator=(const list &lst);//重载等号操作符
swap(lst);//将lst与本身的元素互换。

front();//返回第一个元素。
back();//返回最后一个元素。

*/
void test04()
{
	list<int> mylist;
	mylist.assign(10, 10);
	printList(mylist);

	cout << mylist.front() << endl;
	cout << mylist.back() << endl;

	list<int> mylist2;
	for (int i = 0; i < 5; i++)
	{
		mylist2.push_back(i);
	}

	mylist2.swap(mylist);
	printList(mylist2);
}
/*
反转 排序
reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
sort(); //list排序

*/

bool myfunc2(int v1, int v2)
{
	return v1 > v2;
}
void test05()
{
	list<int> mylist;
	for (int i = 0; i < 5; i++)
	{
		mylist.push_back(i + 10);
	}

	printList(mylist);

	mylist.reverse();

	printList(mylist);

	//注意：list容器不能使用sort算法
	//sort(mylist.begin(), mylist.end());
	mylist.sort();

	printList(mylist);

	mylist.sort(myfunc2);
	printList(mylist);
}

int main()
{
	test05();
	system("pause");
	return EXIT_SUCCESS;
}

