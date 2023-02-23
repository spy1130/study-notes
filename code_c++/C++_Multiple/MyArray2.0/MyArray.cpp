#include "MyArray.h"


MyArray::MyArray()
{
	this->mCapacity = 20;
	this->mSize = 0;

	this->pArray = new int[this->mCapacity];
	for (int i = 0; i < this->mCapacity; i++)
	{
		this->pArray[i] = 0;
	}
}


MyArray::~MyArray()
{
	if (this->pArray != NULL)
	{
		delete[] this->pArray;
		this->pArray = NULL;
	}
}

MyArray::MyArray(const MyArray &arr)
{
	this->mCapacity = arr.mCapacity;
	this->mSize = arr.mSize;
	//1.申请空间
	this->pArray = new int[arr.mCapacity];
	//2.拷贝数据
	for (int i = 0; i < this->mSize; i++)
	{
		this->pArray[i] = arr.pArray[i];
	}
}
MyArray::MyArray(int capacity, int val)
{
	this->mCapacity = capacity;
	this->mSize = capacity;
	this->pArray = new int[capacity];
	for (int i = 0; i < this->mSize; i++)
	{
		this->pArray[i] = val;
	}
}

//头插
void MyArray::PushFront(int val)
{
	//判断容量是否满
	if (this->mSize == this->mCapacity)
	{
		return;
	}

	for (int i = this->mSize - 1; i >= 0; i--)
	{
		this->pArray[i + 1] = this->pArray[i];
	}
	//空出了0的位置
	this->pArray[0] = val;

	//维护元素个数
	this->mSize++;
}
//尾插
void MyArray::PushBack(int val)
{
	//判断容量是否满
	if (this->mSize == this->mCapacity)
	{
		return;
	}

	this->pArray[this->mSize] = val;
	this->mSize++;
}
//头删
void MyArray::PopFront()
{
	//判断是否有元素
	if (this->mSize == 0)
	{
		return;
	}
	//后面的数往前面移动来覆盖第一个元素
	for (int i = 0; i < this->mSize - 1; i++)
	{
		this->pArray[i] = this->pArray[i + 1];
	}

	this->mSize--;
}
//尾删
void MyArray::PopBack()
{

	//判断是否有元素
	if (this->mSize == 0)
	{
		return;
	}

	this->mSize--;

}
//获取数组元素个数
int MyArray::Size()
{
	return this->mSize;
}
//获取数组容量
int MyArray::Capacity()
{
	return this->mCapacity;
}
//指定位置插入元素 
void MyArray::Insert(int pos, int val)
{
	//判断容量是否满
	if (this->mSize == this->mCapacity)
	{
		return;
	}

	//如果位置不对，就插入到尾部
	if (pos<0 || pos>this->mSize - 1)
	{
		pos = this->mSize;
	}

	for (int i = this->mSize - 1; i >= pos; i--)
	{
		this->pArray[i + 1] = this->pArray[i];
	}
	//pos是位置空出了
	this->pArray[pos] = val;

	this->mSize++;
}
//获取指定位置的值
int &MyArray::Get(int pos)
{
	return this->pArray[pos];
}
//在指定位置修改值
void MyArray::Set(int pos, int val)
{
	if (pos<0 || pos>this->mCapacity - 1)
	{
		return;
	}

	this->pArray[pos] = val;
}


//重写赋值运算符重载函数
MyArray&MyArray::operator=(const MyArray &m)
{
	cout << "赋值函数" << endl;
	//1.释放原来的空间
	if (this->pArray != NULL)
	{
		delete[] this->pArray;
		this->pArray = NULL;
	}
	this->mCapacity = m.mCapacity;
	this->mSize = m.mSize;
	//2.申请空间，大小由m决定
	this->pArray = new int[m.mCapacity];
	//3.拷贝数据
	cout << "this->mSize:"<<this->mSize << endl;
	for (int i = 0; i < this->mCapacity; i++)
	{
		this->pArray[i] = m.pArray[i];
	}

	return *this;
}

//要能当左右值
int &MyArray::operator[](int index)
{
	/*
	for (int i = 0; i < 20; i++)
	{
		arr[i] = i + 10;
	}

	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	*/
	//赋值时，加加
	
	
	if (this->mSize <=index)
	{
		this->mSize++;
	}
	
	return this->pArray[index];
}