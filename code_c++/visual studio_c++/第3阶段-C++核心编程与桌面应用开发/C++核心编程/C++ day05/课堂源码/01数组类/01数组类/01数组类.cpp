#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"MyArray.h"

void printMyArray(MyArray &arr)
{
	for (int i = 0; i < arr.Size(); i++)
	{
		cout << arr.Get(i) << " ";
	}
	cout << endl;
}

void test01()
{
	MyArray arr(20, 1);
	printMyArray(arr);
	//修改数组中的值
	for (int i = 0; i < arr.Size(); i++)
	{
		arr.Get(i) = i + 100;
	}
	printMyArray(arr);

	//指定位置修改值
	arr.Set(2, 0);
	printMyArray(arr);

	//测试是否发生浅拷贝
	MyArray arr2 = arr;
	printMyArray(arr2);
}

void test02()
{
	MyArray arr;

	//添加元素
	for (int i = 0; i < 10; i++)
	{
		//尾插
		arr.PushBack(i + 10);
	}
	for (int i = 0; i < 9; i++)
	{
		//头插
		arr.PushFront(i + 20);
	}

	//指定位置插入
	arr.Insert(10, 100);

	printMyArray(arr);

	arr.PopBack();
	arr.PopFront();
	printMyArray(arr);

}


int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

