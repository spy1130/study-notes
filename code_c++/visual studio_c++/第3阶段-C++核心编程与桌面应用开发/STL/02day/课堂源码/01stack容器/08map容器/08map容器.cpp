#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<map>
#include<string>

void test()
{
	map<int, string>::iterator it;
	it--;
	it++;
	//it + 2;双向迭代器
}
/*
插入数据元素操作
map.insert(...); //往容器插入元素，返回pair<iterator,bool>
map<int, string> mapStu;
// 第一种 通过pair的方式插入对象
mapStu.insert(pair<int, string>(3, "小张"));
// 第二种 通过pair的方式插入对象
mapStu.inset(make_pair(-1, "校长"));
// 第三种 通过value_type的方式插入对象
mapStu.insert(map<int, string>::value_type(1, "小李"));
// 第四种 通过数组的方式插入值
mapStu[3] = "小刘";
mapStu[5] = "小王";

*/

template<class T>
void printMap(T &m)
{
	for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}

void test01()
{
	map<int, string> mymap;

	//1.
	mymap.insert(pair<int, string>(3, "aaa"));
	//2.
	mymap.insert(make_pair(6, "bbb"));
	//3.
	mymap.insert(map<int, string>::value_type(2, "ccc"));
	//4.
	mymap[4] = "ddd";

	printMap(mymap);

}
//改变规则
struct mapfunc
{
	bool operator()(int key1,int key2)
	{
		return key1 > key2;
	}
};
void test02()
{
	map<int, string, mapfunc> mymap;

	//1.
	mymap.insert(pair<int, string>(3, "aaa"));
	//2.
	mymap.insert(make_pair(6, "bbb"));
	//3.
	mymap.insert(map<int, string>::value_type(2, "ccc"));
	//4.
	mymap[4] = "ddd";

	printMap(mymap);

}

//注意：[]方式插入数据,如果没有实值，那么键值也是存在的
void test03()
{
	map<int, string> mymap;

	//1.
	mymap.insert(pair<int, string>(3, "aaa"));
	//2.
	mymap.insert(make_pair(6, "bbb"));
	//3.
	mymap.insert(map<int, string>::value_type(2, "ccc"));
	//4.
	mymap[4] = "ddd";

	printMap(mymap);

	cout << "size:" << mymap.size() << endl;

	cout << mymap[100] << endl;//插入键值，返回的是实值
	cout << "size:" << mymap.size() << endl;
}
/*
查找
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

*/
void test04()
{
	map<int, string> mymap;
	mymap[1] = "aaa";
	mymap[2] = "bbb";
	mymap[3] = "ccc";
	mymap[4] = "ddd";
	mymap[5] = "eee";

	map<int, string>::iterator it = mymap.find(30);
	if (it == mymap.end())
	{
		cout << "查找失败" << endl;
	}
	else
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
	//查找大于等于3的最小的数
	it = mymap.lower_bound(3);
	if (it == mymap.end())
	{
		cout << "查找失败" << endl;
	}
	else
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
	//查找大于3的最小的数
	it = mymap.upper_bound(3);
	if (it == mymap.end())
	{
		cout << "查找失败" << endl;
	}
	else
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
	cout << "--------------" << endl;
	//返回大于等于2的两个最小的数，如果有2那么就返回2和大于2的最小数
	pair<map<int,string>::iterator,map<int,string>::iterator> ret=mymap.equal_range(3);

	if (ret.first != mymap.end())
	{
		cout << "key:" << ret.first->first << " Value:" << ret.first->second << endl;
	}

	if (ret.second != mymap.end())
	{
		cout << "key:" << ret.second->first << " Value:" << ret.second->second << endl;

	}
}
int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}

