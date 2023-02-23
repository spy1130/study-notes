## 01.智能指针类（重点）

1.智能指针类是管理另一个类的对象的释放

```

class Maker
{
public:
	Maker()
	{
		cout << "无参构造" << endl;
	}
	void printMaker()
	{
		cout << "hello Maker" << endl;
	}
	~Maker()
	{
		cout << "析构函数" << endl;
	}
};

class SmartPoint
{
public:
	SmartPoint(Maker *m)
	{
		this->pMaker = m;
	}

	~SmartPoint()
	{
		if (this->pMaker != NULL)
		{
			cout << "SmartPoint 析构函数" << endl;
			delete this->pMaker;
			this->pMaker = NULL;
		}
	}
private:
	Maker *pMaker;
};
void test01()
{
	Maker *p = new Maker;

	SmartPoint sm(p);//栈区，会调用析构函数
	//当test01()函数结束时，会调用SmartPoint的析构函数，
	//在这析构函数中delete了Maker的对象，会调用Maker的析构函数

}

```

2.指针运算符重载

```
	//重载指针运算符
	Maker *operator->()
	{
		return this->pMaker;
	}
	
	
void test02()
{
	Maker *p = new Maker;

	SmartPoint sm(p);
	//sm-> ==> pMaker->
	sm->printMaker();


}
```

3.重载星花

```
//重载星花
	Maker &operator*()
	{
		return *pMaker;
	}
	
void test02()
{
	Maker *p = new Maker;

	SmartPoint sm(p);

	(*sm).printMaker();

}
```



## 02.重载函数调用符号（重点）

1.类里有重载函数调用符号的类实例化的对象也叫仿函数

2.仿函数的作用：1.方便代码维护 2.方便有权限的调用函数。3.作为算法的策略（后将）

```
//一个类如重载了函数调用符号，那么这个类实例化出的对象也叫仿函数
//仿函数的作用：1.方便代码维护 2.方便有权限的调用函数。3.作为算法的策略（后将）
class Maker
{
public:
	Maker()
	{
		name = "翠花";
	}
	void printMaker()
	{
		cout << name + "你好漂亮" << endl;
	}

	void operator()()
	{
		cout << "hello" << endl;
	}

	void operator()(int v1,int v2)
	{
		cout << v1+v2 << endl;
	}
public:
	string name;
};


void test()
{
	Maker func;

	func();//看起来像函数，其实func是对象

	func(10, 20);

	func.printMaker();
}
```



## 03.其他重载的重载（了解）

```
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Maker
{
public:
	Maker()
	{
		a = 0;
	}

	void SetA(int val)
	{
		a = val;
	}
	//没有返回值，也没有void
	operator bool()
	{
		if (a <= 0)
		{
			return false;
		}

		return true;
	}

	bool operator!()
	{
		if (a <= 0)
		{
			return true;
		}

		return false;
	}

	operator int()
	{
		return 10;
	}
public:
	int a;
};

void test()
{
	Maker m;
	m.SetA(10);
	if (m)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}

	if (!m)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}

	int b = (int)m;
	cout << b << endl;
}
int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}


```



## 04.字符串类（了解）

1.目的：设置一个类，类似于string的效果



## 05.继承的作用（重点）

1.代码复用，2.扩展类的功能

## 06.继承方式（重点）

1.继承方式，公有继承，私有继承，保护继承

2.子类对从父类继承过来的成员的权限

1.公有继承

​	1.父类的公有属性成员，到子类还是公有
​	2.父类的私有属性成员，到子类不能访问
​	3.父类的保护属性成员，到子类还是保护	

2.保护继承

​	1.父类的公有属性成员，到子类是保护
​	2.父类的私有属性成员，到子类不能访问
​	3.父类的保护属性成员，到子类还是保护	

3.私有继承

​	1.父类的公有属性成员，到子类还是私有
​	2.父类的私有属性成员，到子类不能访问
​	3.父类的保护属性成员，到子类还是私有	

## 07.继承中的对象模型工程（了解）

1.打开开发者命令程序

2.进入文件所在的目录 cd 目录所在

​	如果要跨盘符，还要再次输入  盘符名:

3.输入命令:cl /d1reportSingleClassLayout类名 文件名

## 08.继承中的构造和析构（重点）

1.继承中的构造和析构调用顺序

先调用父类的构造函数，再调用本身的构造函数，析构函数调用顺序反之

```
class Father
{
public:
	Father()
	{
		cout << "Father构造函数" << endl;
	}
	~Father()
	{
		cout << "Father析构函数" << endl;
	}
};

class Son :public Father
{
public:
	Son()
	{
		cout << "Son构造函数" << endl;
	}
	~Son()
	{
		cout << "Son析构函数" << endl;
	}
};
//先调用父类的构造函数，再调用本身的构造函数，析构函数调用顺序反之
void test01()
{
	Son s;
}
```

2.继承和组合混搭

先调用父类的构造，然后调用成员对象的构造，最后调用本身的构造，析构函数调用顺序反之

```
class A
{
public:
	A()
	{
		cout << "A 的构造" << endl;
	}
	~A()
	{
		cout << "A 的析构" << endl;
	}
public:

};

class B
{
public:
	B()
	{
		cout << "B 的构造" << endl;
	}
	~B()
	{
		cout << "B 的析构" << endl;
	}
};

class C
{
public:
	C()
	{
		cout << "C 的构造" << endl;
	}
	~C()
	{
		cout << "C 的析构" << endl;
	}
};

class D:public A
{
public:
	D()
	{
		cout << "D 的构造" << endl;
	}
	~D()
	{
		cout << "D 的析构" << endl;
	}
public:
	B b;
	C c;
};
void test02()
{
	D d;
}
```



## 09.继承中同名成员的处理方法（重点）

1.通过父类名加作用域来访问，当子类和父类有同名成员时，子类的同名成员会隐藏父类的同名成员

```
//当子类和父类有同名成员时，子类的同名成员会隐藏父类的同名成员
void test()
{
	Son s;
	cout << s.a << endl;
	cout << sizeof(Son) << endl;//8
	//通过父类名加作用域来访问
	cout<<s.Father::a << endl;
}
```

2.当子类有和父类同名函数时，父类的所有重载函数都会被隐藏

```
class Father
{
public:
	Father()
	{
		a = 10;
	}

	void func()
	{
		cout << "Father func" << endl;
	}
	void func(int a)
	{
		cout << "Father func(int a)" << endl;
	}

	void func(int a,int b)
	{
		cout << "Father func(int a,int b)" << endl;
	}


public:
	int a;
};
class Son :public Father
{
public:
	Son()
	{
		a = 20;
	}
	void func()
	{
		cout << "Son func" << endl;
	}
public:
	int a;
};

//当子类有和父类同名函数时，父类的所有函数重载都会被隐藏
void test02()
{
	Son s;
	s.func();
	//s.func(10);err
	//s.func(10, 20);err
}
```



## 10.继承中静态成员特性（了解）

1.静态成员可以被继承

2.继承中的静态成员变量一样会被同名的子类成员变量隐藏

3.继承中的静态成员函数中，当子类有和父类同名静态函数时，父类的所有重载静态函数都会被隐藏

4.改变从基类继承过来的静态函数的某个特征，返回值或者参数个数，将会隐藏基类重载的函数

5.静态成员函数不能是虚函数

6.从父类继承过来的静态成员变量是父类的静态成员变量

## 11.非自动继承的函数（了解）

1.构造，析构，赋值函数都不能被继承

## 12.多继承（了解）

1.多继承是一个类有两个以上的父类

2.多继承的问题是，当父类中有同名成员时，子类中会产生二义性问题

## 13.菱形继承（重点）

1.虚基类

被虚继承的基类叫虚基类

2.菱形继承的问题

两个父类中有祖类中的数据，然后子类会继承两个父类的数据，会产生二义性问题

3.虚继承

父类虚继承祖类，用virtual关键字

4.虚继承的原理

​	1.编译给类添加了一个指针，指针指向类似于表的组织，该表记录了该指针距离变量的偏移量

​	2.当子类多继承两个父类，那么只有一份成员变量，然后有两个指针，只有一份成员变量，所以不会产生二义性

## 14.动态联编和静态联编（重点难点）

1.静态联编

编译器会根据函数调用的对象类型,在编译阶段就确定函数的调用地址，这就是静态联编（早绑定）

2.虚函数

在普通成员函数前面加virtual，该函数变为虚函数，是告诉编译器这个函数要晚绑定

3.动态联编

在运行阶段才确定调用哪个函数（晚绑定），

4.动态编译的作用，可以晚绑定函数调用地址，这样可以扩展功能，不修改前面的代码的基础上进行项目的扩充

5.类型转换问题

​	1.子类转换成父类（向上转换）：编译器认为指针的寻址范围缩小了，所以是安全的

​	2.父类转换成子类（向下转换）；编译器认为指针的寻址范围扩大了，不安全