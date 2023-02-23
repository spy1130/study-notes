## 01.C++概述（了解）

c++语言在c语言的基础上添加了**面向对象编程**和**泛型编程**的支持。

## 02.第一个程序helloworld（掌握）

```
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;//标准命名空间


int main()
{
	//cout是标准的输出流对象，打印字符串，
	//endl是刷新缓冲区，并换行
	cout << "hello world!" << endl;
	system("pause");
	return EXIT_SUCCESS;
}
```



## 03.面向对象的三大特征（了解）

封装，继承，多态

## 04.命名空间（重点）

1.为什么有命名空间，是因为解决多人合作时取标识符是重命名的问题

2.什么是命名空间

```
//命名空间
namespace A{//A是空间的名字，
	int a;
	void func()
	{

	}
}
```

3.命名空间的注意

```
注意1：命名空间只能写在全局
注意2：命名空间可以嵌套命名空间
//命名空间可以嵌套命名空间
namespace Maker
{
	int a;
	namespace B
	{
		int b;
	}
}
注意3：命名空间是开放，随时可以加入新成员，但是新成员只能在加入后使用
namespace Maker
{
	int a;
	namespace B
	{
		int b;
	}
}
namespace Maker
{
	int c;
}
注意4：匿名命名空间
//类似于static int d=50;
namespace
{
	int d = 50;
}
注意5：命名空间可以取别名
void test01()
{
	//			新名字    旧名字
	namespace nameMaker = Maker;
	cout << nameMaker::a << endl;
}
注意6：分文件编写代码时，如果.h中有两个命名空间，但是里面的成员函数或成员变量同名时，在.cpp中实现函数时，需要加上命名空间
test.h文件
#pragma once
#include<iostream>
using namespace std;

namespace myMaker1
{
	void func();
}

namespace myMaker2
{
	void func();
}

test.cpp文件
#include "test.h"
void myMaker1::func()//需要在函数名前面加入确定命名空间名字
{
	cout << "func" << endl;
}
```

4.作用域运算符

用来访问某个作用域里面的成员

## 05.using声明和编译指令（重点）

using声明是让命名空间中某个标识符可以直接使用

```
namespace A
{
	int a = 10;
	int b = 20;
	int c = 30;
}

void test01()
{
	//using声明是让命名空间中某个标识符可以直接使用
	using A::a;
	cout <<a << endl;
	//int a = 50;//注意:using声明了某个变量，在该作用域内不能定义同名的变量
}
```
using编译指令，让某个命名空间中的标识符都可以直接使用
```
namespace A
{
	int a = 10;
	int b = 20;
	int c = 30;
}
void test02()
{
	//using编译指令，让某个命名空间中的标识符都可以直接使用
	using namespace A;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	int a = 100;//为什么不会冲突
	//类似于命名空中的a是全局变量，这里的a的局部变量
	cout << "a=" << a << endl;

}
```



## 06.struct类型加强（重点）

加强一：定义变量时不需要使用struct

加强二：结构体内可以写函数

## 07.更严格的类型转换（了解）

不能隐性的转换，必须显示的转换

## 08.三目运算符（了解）

c语言的三目运算符返回的是右值

C++语言的三目运算符返回的是左值，是空间

放在赋值操作符左边的是左值，放在右边的是右值

## 09.C/C++的const（重点）

1.C语言的const修饰的变量都有空间

2.C语言的const修饰的全局变量具有外部链接属性

3.C++语言的const修饰的变量有时有空间，有时没有空间（发生常量折叠，且没有对变量进行取址操作）

```
const int aa = 10;//没有内存

void test01()
{
	//发生了常量折叠
	cout << "aa=" << aa << endl;//在编译阶段，编译器：cout<<"aa="<<10<<endl;

	//禁止优化volatile
	//volatile const int bb = 20;//栈区
	 const int bb = 20;
	int *p = (int*)&bb;//进行了取址操作，所以有空间
	*p = 200;
	cout << "bb=" << bb << endl;//cout << "bb=" << 20 << endl;
	cout << "*p=" << *p << endl;

	cout << "a的地址=" << (int)&bb << endl;
	cout << "p指向的地址" << (int)p << endl;


}
```

4.C++语言中const修饰的全局变量具有内部链接属性

extern const int c = 300;//加上extern就变为外部链接属性

5.C++编译器不能优化的情况

​	1.不能优化自定义数据类型

​	2.如果用变量给const修饰的局部变量赋值，那么编译器就不能优化

​	3.编译器是在编译阶段来优化数据

6.尽量用const替代define

​	1.define没有数据类型，const修饰的变量有数据类型，可以进行数据类型检查

```
#define MA 128
const short ma = 128;
void func(short a)
{
	cout << "func(short a)" << endl;
}

void func(int a)
{
	cout << "func(int a)" << endl;
}
int main()
{
	func(ma);
	system("pause");
	return EXIT_SUCCESS;
}
```

​	2.const修饰的变量有作用域，define不重视作用域，不能限定常量的使用范围

## 10.引用（重点难点）

1.引用是做什么：和C语言的指针一样的功能，并且使语法更加简洁

2.引用是什么：引用是给空间取别名

3.引用的语法

```
void func(int &a)//int &a=a;
{
	a = 200;
}

void test02()
{
	int a = 10;
	func(a);
	cout << "a=" << a << endl;
}
```

4.引用的注意

```
注意1：int &b = a;这里&不是取地址操作符，是引用的标记作用
注意2：引用创建时，必须初始化。//int &pRef;err
注意3：引用一旦初始化不能改变它的指向
注意4：引用必须引用一块合法的内存空间
```

5.数组的引用

```
int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	//第一种方法（常用）
	//1.定义数组类型
	typedef int(MY_ARR)[5];//数组类型
	//2.建立引用
	MY_ARR &arref = arr;//建立引用，int &b=a;

	//第二种方法（常用）
	//直接定义引用
	int(&arref2)[5] = arr;// int &b=a

	//第三种方法
	typedef int(&MY_ARR3)[5];//建立引用数组类型
	MY_ARR3 arref3 = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << arref[i] << endl;
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		arref2[i] = 100 + i;
		cout << arref2[i] << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}
```

6.引用的本质（了解）

引用的本质是编译器在内部使用常指针来实现

```
//发现是引用，转换为 int* const ref = &a;
void testFunc(int& ref){
	ref = 100; // ref是引用，转换为*ref = 100
}
int main(){
	int a = 10;
	int& aRef = a; //自动转换为int* const aRef = &a;这也能说明引用为什么必须初始化
	aRef = 20; //内部发现aRef是引用，自动帮我们转换为: *aRef = 20;
	cout << "a:" << a << endl;
	cout << "aRef:" << aRef << endl;
	testFunc(a);
	return EXIT_SUCCESS;
}

```



## 11.指针的引用（重点难点）

1.指针的引用是给指针变量这块空间取别名

```
void test01()
{
	char* p = "翠花";
	char* &p1 = p;
	cout << p1 << endl;
}

//被调函数
void func(char* &tmp)//char* &tmp=mp;
{
	char *p;
	p=(char*)malloc(64);
	memset(p, 0, 64);
	strcpy(p, "小花");
	tmp = p;//省了*
}
//主调函数
void test02()
{
	char* mp = NULL;
	func(mp);//省了&
	cout << mp << endl;
}
```



## 12.C和C++的区别(了解)

1.C语言的结构体不能写函数，C++可以

2.结构体定义变量时，C++不需要加struct关键字

3.更加严格的类型检查

4.const修饰的变量，C++有时没有内存，C语言的都有内存

5.三目运算符返回的值不一样

6.引用和C语言的指针功能一样