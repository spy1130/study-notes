## 01.模版的概念（了解）

1.函数或类是通用，但是里面的数据类型的多种状态

2.模版有：函数和类

## 02.函数模版（重点）

1.什么是函数模版

函数模板，**实际上是建立一个通用函数，其函数类型和形参类型不具体制定，用一个虚拟的类型来代表。这个通用函数就成为函数模板**

2.怎么编写函数模版

```
//T代表泛型的数据类型，不是只能写T，
template<class T>//让编译器看到这句话后面紧跟着的函数里有T不要报错
void mySwap(T &a,T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}


//可以这样定义函数模版
template<typename T>
void func2(T a,T b)
{

}
```

3.怎么使用函数模版

```
//T代表泛型的数据类型，不是只能写T，
template<class T>//让编译器看到这句话后面紧跟着的函数里有T不要报错
void mySwap(T &a,T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
void mySwap2()
{

}

//使用函数模版
void test02()
{
	int a = 10;
	int b = 20;

	//1.编译器会根据实参来自动推导数据类型
	mySwap(a,b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	char c = 'c';
	//mySwap(a, c);err,数据类型要一致

	//2.显示的指定类型
	mySwap<int>(a, b);//<>用参数列表告诉编译器我只传int类
	//mySwap<double>(a, b);//注意：指定类型，传入时不能不一致

	mySwap<>(a,b);
	//mySwap2<>();//err 调用时，必须让编译器知道泛型T具体是什么类型
}
```

4.编译器会对函数模版和类模版进行二次编译

```
//T代表泛型的数据类型，不是只能写T，
template<class T>//让编译器看到这句话后面紧跟着的函数里有T不要报错
void mySwap(T &a,T &b)//第一次编译
{
	T tmp = a;
	a= b;
	b = tmp;
}

//使用函数模版
void test02()
{
	int a = 10;
	int b = 20;

	//1.编译器会根据实参来自动推导数据类型
	mySwap(a,b);//编译器在函数模版被调用时，进行第二次编译
	/*
	void mySwap(int &a,int &b)
	{
		int tmp = a;
		a= b;
		b = tmp;
	}
	*/
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}
```

5.隐式转换

```
template<class T>
T func(T a, T b)
{
	return a + b;
}
void test03()
{
	int a = 10;
	double b = 20.2;
	//如果使用参数列表指定数据类型，那么实参中可以隐式转换，
	//如果转换成功，就调用，转换不成功就报错
	cout << func<int>(10,20.2) << endl;
}
```



## 03.普通函数与函数模板区别（重点）

1.普通函数可以进行隐式转换,函数模版不能直接的进行隐式转换

```
//普通函数
int myPlus(int a, int b)
{
	return a + b;
}

template<class T>
int myPlus2(T a, T b)
{
	return a + b;
}

void test()
{
	int a = 10;
	int b = 20;
	char c = 'a';
	//普通函数可以进行隐式转换
	myPlus(a, c);
	//函数模版不能直接的进行隐式转换
	//myPlus2(a, c);
	myPlus2<int>(a, c);//如果要进行隐性转换，必须加上参数列表
}
```



## 04.普通函数与函数模板的调用规则（重点）

```
//普通函数
void myPlus(int a, int b)
{
	cout << "普通函数" << endl;
}

template<class T>
void myPlus(T a, T b)
{
	cout << "函数模版" << endl;
}

template<class T>
void myPlus(T a, T b, T c)
{
	cout << "函数模版 T c" << endl;

}
//1.函数模版和普通函数可以重载
void test()
{
	int a = 10;
	int b = 20;
	//2.如果普通函数和函数模版都可以实现的功能，普通函数优先调用
	myPlus(a, b);

	//3.可以使用<>空参数列表强制调用函数模版
	myPlus<>(a, b);

	//4.函数模版之间也可以进行重载


	//5.如果函数模版可以产生更好的匹配，那么优先使用函数模版
	char c1 = 'a';
	char c2 = 'b';
	myPlus(c1, c2);
}
```



## 05.模版实现机制（了解）

l  **编译器并不是把函数模板处理成能够处理任何类型的函数**

l  **函数模板通过具体类型产生不同的函数**

l  **编译器会对函数模板进行两次编译，在声明的地方对模板代码本身进行编译，在调用的地方对参数替换后的代码进行编译。**

## 06.模版的局限性及解决方法（了解）

1.模版的局限性

```
template<class T>
void func(T a, T b)
{
	if (a > b)
	{
		cout << "a>b" << endl;
	}
	else
	{
		cout << "a<=b" << endl;
	}
}
void test()
{
//如果传入的是数组名，那么函数模版中比较函数名的大小就没有意义
	int arr[20];
	int arr2[10];

	func(arr, arr2);
}
```

2.解决方法，使用函数模版具体化

```
//不建议具体化函数模版，因为没有通用性
class Maker
{
public:
	Maker(string name,int age)
	{
		this->age = age;
		this->name = name;
	}
public:
	string name;
	int age;
};
template<class T>
void myfunc(T &a, T &b)
{
	if (a > b)
	{
		cout << "a>b" << endl;
	}
	else
	{
		cout << "a<=b" << endl;
	}
}
//不建议具体化函数模版，因为没有通用性
//具体化函数模版，注意上面的函数模版要有，才能具体化
template<>void myfunc<Maker>(Maker &a, Maker &b)
{
	cout << "函数模版的具体化" << endl;
	if (a.age > b.age)
	{
		cout << "a>b" << endl;
	}
	else
	{
		cout << "a<=b" << endl;
	}
}

void test02()
{
	Maker m1("aaa", 10);
	Maker m2("bbb", 20);

	myfunc(m1, m2);
}
```



## 07.类模版（重点）

1.类模版是把类中的数据类型参数化

```
template<class NameType,class AgeType>
class Maekr
{
public:
	Maekr(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}
public:
	NameType name;
	AgeType age;
};
```

2.类模版的使用

```
void test()
{
	//1.类模版不会自动推导数据类型，要显示的告诉编译器是什么类型
	Maker<string,int> m("悟空",18);
	m.printMaker();

	//2.注意传入的参数,传入参数类型要程序员自己把握
	Maker<int, int> m2(18, 20);
	m2.printMaker();

	//Maker<> m3("aaa",18);err,必须通过参数列表告诉编译器是什么类型

}
```

3.类模版和函数模版的区别

类模版不会自动推导数据类型，要显示的告诉编译器是什么类型

函数模版可以根据实参来推导数据类型

4.类模版的默认参数(了解)

```
//类模版的默认类型
template<class NameType, class AgeType=int>
class Maker2
{
public:
	Maker2(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void printMaker()
	{
		cout << "Name:" << this->name << " Age:" << this->age << endl;
	}
public:
	NameType name;
	AgeType age;
};

void test02()
{
	//如果有默认类型，那么<>里可以少写类型
	Maker2<string> m("贝吉塔", 20);

	m.printMaker();
	//以传入的类型为准
	Maker2<string, double> m2("wukong", 20.22);
	m2.printMaker();
}
```

5.类模版的默认参数注意

```
//默认类型后面的泛型类型都必须有默认类型
template<class NameType, class AgeType = int,class T=int>
class Maker3
{
public:
	Maker3(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void printMaker()
	{
		cout << "Name:" << this->name << " Age:" << this->age << endl;
	}
public:
	NameType name;
	AgeType age;
};
```



## 08.复数的模板类（了解）

1.目的：对象c1(3,4) ，对象c2(5,-10) ，对象c3=c1.Maker_add(c2) ，c3里的两个成员变量会等于a=3+5,b=4+(-10)并且数据类型可以不同

2.通过成员函数实现

```
template<class T>
class Maker
{
public:
	Maker()
	{
		a = 0;
		b = 0;

	}
	Maker(T r,T i)
	{
		a = r;
		b = i;
	}
	Maker Maker_add(Maker &c2)
	{
		Maker<T> c;
		c.a = this->a + c2.a;
		c.b = this->b + c2.b;
		return c;
	}

	void printMaker()
	{
		cout << "(" << a << "," << b << ")" << endl;
	}
private:
	T a;
	T b;
};

void test()
{
	Maker<int> c1(3, 4);
	Maker<int> c2(5, -10);
	Maker<int> c3;
	c3 = c1.Maker_add(c2);

	cout << "c1+c2=";
	c3.printMaker();

	Maker<double> d1(3.3, 4.4);
	Maker<double> d2(5.5, -10.1);
	Maker<double> d3;
	d3 = d1.Maker_add(d2);

	cout << "d1+d2=";
	d3.printMaker();
}
```

3.通过重载运算符实现

```
	Maker operator+(Maker &c2)
	{
		Maker tmp(this->a + c2.a, this->b + c2.b);
		return tmp;
	}

void test02()
{
	Maker<int> c1(3, 4);
	Maker<int> c2(5, -10);
	Maker<int> c3;
	c3 = c1 + c2;

	cout << "c1+c2=";
	c3.printMaker();
}
```



## 09.类模版做函数参数（重点）

1.指定传入类型

```
//1.指定传入的数据类型
void func(Maker<string,int> &m)
{
	m.printMaker();
}
```

2.参数模板化

```
//2.参数模版化（常用）
template<class T1,class T2>
void func2(Maker<T1,T2> &m)
{
	m.printMaker();
}
```

3.整个类 模板化

```
//3.整个类 模版化
template<class T>
void func3(T &m)
{
	m.printMaker();
}
```



## 10.类模版的继承（重点）

1.普通类继承类模版

```
//普通类继承类模版
template<class T>
class Father
{
public:
	Father()
	{
		m = 20;
	}
public:
	T m;
};

//普通类 继承 类模版
class Son :public Father<int>//要告诉编译器父类的泛型数据类型具体是什么类型
{
public:
	
};
```

2.类模版 继承 类模版

```
//类模版 继承 类模版
template<class T1,class T2>
class Son2 :public Father<T2>//要告诉编译器父类的泛型数据类型具体是什么类型
{

};
```

3.必须告诉编译器父类的泛型类型是什么数据类型

## 11.类模版的成员函数类内类外实现（重点）

1.类内实现

```
template<class NameType, class AgeType>
class Maker
{
public:
	Maker(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void printMaker()
	{
		cout << "Name:" << this->name << " Age:" << this->age << endl;
	}
public:
	NameType name;
	AgeType age;
};
```

2.类外实现，成员函数必须写成函数模版，并且写上参数列表

```
template<class NameType, class AgeType>
class Maker
{
public:
	Maker(NameType name, AgeType age);


	void printMaker();
	
public:
	NameType name;
	AgeType age;
};

//类模版的成员函数类外实现
//要写成函数模版
template<class NameType, class AgeType>
Maker<NameType, AgeType>::Maker(NameType name, AgeType age)
{

	cout << "构造函数" << endl;
	this->name = name;
	this->age = age;
}


template<class NameType, class AgeType>
void Maker<NameType, AgeType>::printMaker()
{
	cout << "Name:" << this->name << " Age:" << this->age << endl;
}
```



## 12.类模版分文件编写问题及解决方法（重点难点）

1.调用类模版时，要进行第二次编译，要把泛型的数据类型替换为具体的类型，这时需要知道函数体，但是函数的实现在.cpp中，那么调用类模版的.cpp没有引入实现.cpp，只引入.h，所以报错

2.解决方法：把成员函数放到.h中，然后把.h改为.hpp,然后在调用成员函数的地方，引入.hpp

3.为什么.hpp中有成员的实现，然后在调用类模版的地方引入.hpp，不会报重定义

类的成员函数默认申请为内联函数，在链接时，链接器会对重复的成员函数进行处理，只保留一份成员函数，所以不会进行报错

## 13.类模版碰到友元（重点难点）

1.友元类内实现

```
template<class NameType, class AgeType>
class Maker
{
	friend void printMaker(Maker<NameType, AgeType> &p)
	{
		cout << "类内实现" << p.name << " " << p.age << endl;
	}
public:
	Maker(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	
private:
	NameType name;
	AgeType age;
};

void test01()
{
	Maker<string, int> m("悟空", 18);

	printMaker(m);
}
```

2.友元类外实现

```
//1.声类模版
template<class NameType, class AgeType>
class Maker2;
//2.声明函数模版
//告诉编译器下面有printMaker2的实现
template<class NameType, class AgeType>
void printMaker2(Maker2<NameType, AgeType> &p);

template<class NameType, class AgeType>
class Maker2
{
	//3.在函数名和()之间加上<>。
	friend void printMaker2<>(Maker2<NameType, AgeType> &p);
	//编译器不知道printMaker2下面有没有实现，需要知道函数的结构
public:
	Maker2(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}


private:
	NameType name;
	AgeType age;
};

//4.友元在类外实现要写成函数模版
template<class NameType, class AgeType>
void printMaker2(Maker2<NameType, AgeType> &p)
{
	cout << "类外实现的友元函数 " << p.name << " " << p.age << endl;
}

void test02()
{
	Maker2<string, int> m("贝吉塔", 18);

	printMaker2(m);
}
```



## 14.类模版实现数组

```
MyArray.hpp
#pragma once

template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		this->mCapacity = capacity;
		this->mSize = 0;
		//T如果是Maker,这里要调用什么构造函数，要调用无参构造
		p = new T[this->mCapacity];

	}

	//拷贝构造
	MyArray(const MyArray &arr)
	{
		this->mCapacity = arr.mCapacity;
		this->mSize = arr.mSize;
		p = new T[arr.mCapacity];

		for (int i = 0; i < this->mSize; i++)
		{
			p[i] = arr.p[i];
		}
	}
	//赋值函数
	MyArray &operator=(const MyArray &arr)
	{
		if (this->p != NULL)
		{
			delete[] this->p;
			this->p = NULL;
		}

		p = new T[arr.mCapacity];
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		for (int i = 0; i < this->mSize; i++)
		{
			p[i] = arr.p[i];

		}

		return *this;
	}

	//重载[]
	T &operator[](int index)
	{
		return this->p[index];
	}
	//尾插
	void Push_Back(const T &val)
	{
		if (this->mSize == this->mCapacity)
		{
			return;
		}

		this->p[this->mSize] = val;
		this->mSize++;
	}

	//尾删
	void Pop_Back()
	{
		if (this->mSize == 0)
		{
			return;
		}

		this->mSize--;
	}

	~MyArray()
	{
		if (this->p != NULL)
		{
			delete[] p;
			p = NULL;
		}
	}

	int getSize()
	{
		return this->mSize;
	}
private:
	T *p;
	int mCapacity;
	int mSize;
};

//类模版实现数组.cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"MyArray.hpp"
#include<string>
class Maker
{
public:
	Maker(){}
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	int age;
};

void printMaker(MyArray<Maker> &arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "姓名:" << arr[i].name << " 年龄:" << arr[i].age << endl;
	}
}
void test()
{
	MyArray<Maker> myarr(4);
	Maker m1("悟空", 18);
	Maker m2("贝吉塔", 30);
	Maker m3("短笛", 200);
	Maker m4("小林", 19);
	myarr.Push_Back(m1);
	myarr.Push_Back(m2);
	myarr.Push_Back(m3);
	myarr.Push_Back(m4);

	printMaker(myarr);

	MyArray<int> myint(10);
	for (int i = 0; i < 10; i++)
	{
		myint.Push_Back(i + 1);
	}

	for (int i = 0; i < 10; i++)
	{
		cout << myint[i] <<" ";
	}
	cout << endl;
}

int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}


```

