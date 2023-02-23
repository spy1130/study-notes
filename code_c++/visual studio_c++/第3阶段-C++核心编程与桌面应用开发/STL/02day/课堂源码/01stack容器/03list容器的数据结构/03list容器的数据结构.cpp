#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<list>

void test()
{
	/*list<int>::iterator it;
	it--;
	it++;*/
	//it + 2;err
	//双向迭代器

	list<int> mylist;
	for (int i = 0; i < 10; i++)
	{
		mylist.push_back(i);
	}

	//2015和2017vs :_Myhead==>_Myhead(),_Mysize==>_Mysize()
	list<int>::_Nodeptr node = mylist._Myhead->_Next;//头节点的下一个节点

	for (int i = 0; i < mylist._Mysize * 2; i++)
	{
		cout << "Node:" << node->_Myval << endl;//获取节点数据
		node = node->_Next;
		if (node == mylist._Myhead)
		{
			node = node->_Next;
		}
	}

}

int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}

