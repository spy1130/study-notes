## 1.立方体案例（了解）

1.抽象立方体:属性，长宽高，方法:设置和获取属性的方法，判断两个立方体是否相等的方法

2.一个对象必须要初始化成员变量

3.成员函数中隐藏了一个本类的对象

## 2.点和圆的案例（了解）

1.抽象点:属性有点的坐标，方法：设置和获取坐标的方法

2.抽象圆：属性有圆心和半径，方法：设置和获取圆心的方法，设置和获取半径的方法，判断圆和点的关系的方法

3.用圆心和点之间的距离的平方，和半径的平方比较来确定之间的关系

4.三角型中，两边的平方和等于斜边的平方

## 3.初始化和清理的概念（了解）

1.当对象产生时，必须初始化成员变量，当对象销毁前，必须清理对象

2.初始化用构造函数，清理用析构函数，这两个函数是编译器调用

## 4.构造函数和析构函数（重点）

1.初始化的作用和析构函数的作用

```
构造函数的作用
class Maker
{
public:
	//构造函数的作用是初始化成员变量，是编译器去调用的
	Maker()
	{
		a = 10;
		cout << "构造函数" << endl;
	}

	//析构函数，在对象销毁前，编译器调用析构函数
	~Maker()
	{
		cout << "析构函数" << endl;
	}
public:
	int a;
};

void test01()
{
	//实例化对象，内部做了两件事，1.分配空间，2.调用构造函数进行初始化
	Maker m;
	int b = m.a;
	cout << b << endl;

}

//析构函数的作用
class Maker2
{
public:
	//有参构造
	Maker2(const char *name,int age)
	{
		cout << "有参构造" << endl;
		//从堆区空间申请
		pName = (char*)malloc(strlen(name) + 1);
		strcpy(pName, name);
		mAge = age;
	}

	void printMaker2()
	{
		cout << "name:" << pName << " age:" << mAge << endl;
	}
	~Maker2()
	{
		cout << "析构函数" << endl;
		//释放堆区空间
		if (pName != NULL)
		{
			free(pName);
			pName = NULL;
		}
	}
private:
	char *pName;
	int mAge;
};

void test02()
{
	Maker2 m2("翠花",18);
	m2.printMaker2();

}
```

2.构造函数点和析构函数的注意

​	1.构造函数和析构函数的权限必须是公有的

​	2.构造函数可以重载

​	3.构造函数没有返回值，不能用void,构造函数可以有参数，析构函数没有返回值，不能用void,没有参数

​	4.有对象产生必然会调用构造函数，有对象销毁必然会调用析构函数。有多少个对象产生就会调用多少次构造函数，有多少个对象销毁就会调用多少次析构函数

3.默认的构造函数和默认的析构函数

```
class Maker
{
public:
	Maker()//默认的构造函数，函数体是空的
	{

	}
	~Maker()//默认的析构函数，函数体也是空
	{

	}
	//编译器默认提供默认的构造函数和析构函数
	void printfMaker()
	{
		a = 100;
		cout << "a=" << a << endl;
	}
private:
	int a;
};
```

4.拷贝构造函数

1.什么是拷贝构造

```
class Maker
{
public:
	Maker()
	{
		cout << "无参构造函数" << endl;
		a = 20;
	}
	//拷贝构造函数
	Maker(const Maker &m)
	{
		cout << "拷贝构造函数" << endl;
		a = m.a;
		
	}
	//打印函数
	void printMaker()
	{
		cout << "a=" << a << endl;
	}
private:
	int a;
};



void test01()
{
	Maker m1;
	m1.printMaker();

	//用一个已有的对象去初始化另一个对象
	Maker m2(m1);
	m2.printMaker();
}
```

2.编译器提供了默认的拷贝构造函数

```
class Maker2
{
public:
	Maker2()
	{
		cout << "无参构造函数" << endl;
		a = 20;
	}
	//编译器提供了默认的拷贝构造函数
	//Maker2(const Maker2 &m)
	//{
	//	//默认拷贝构造函数进行了成员变量的简单拷贝
	//	a = m.a;
	//}

	//打印函数
	void printMaker()
	{
		cout << "a=" << a << endl;
	}
private:
	int a;
};


void test02()
{
	Maker2 m1;
	m1.printMaker();

	
	Maker2 m2(m1);
	m2.printMaker();
}
```

3.拷贝构造函数中形参要用引用

```
class Maker3
{
public:
	Maker3(int Ma)
	{
		cout << "有参构造函数" << endl;
		ma = Ma;
	}
	Maker3(const Maker3 &m)
	{
		cout << "拷贝构造函数" << endl;
	}
private:
	int ma;
};

void test03()
{
	Maker3 m1(10);//调用有参构造

	Maker3 m2(m1);

	//如果拷贝构造函数中的形参不是引用
	/*
	Maker3(const Maker3 m)//const Maker3 m=m1;   const Maker3 m(m1);
	{
		cout << "拷贝构造函数" << endl;
	}

	1.Maker3 m2(m1);
	2.const Maker3 m=m1;
	3.const Maker3 m(m1);
	4.const Maker3 m=m1;
	5.进入死循环
	*/
}
```



## 5.构造函数的分类及调用（重点）

1.构造函数的分类：无参构造函数，有参构造函数，拷贝构造函数

2.类默认提供了哪些函数：默认的构造函数，默认的析构函数，默认的拷贝构造函数，默认的赋值函数

3.构造函数的调用

```
void test01()
{
	Maker m;//调用无参构造函数
	Maker m1(10);//调用有参构造
	Maker m2(m1);//调用拷贝构造

	//不常用
	Maker m4 = Maker(10);//调用的是有参构造函数
	Maker m3 = m2;//调用拷贝构造
	cout << "=====" << endl;
	Maker m5 = 10;//Maker m5=Maker(10);
	cout << "=======" << endl;

	Maker m6;
	m6 = m5;//赋值操作

}
```



## 6.匿名对象（了解）

1.匿名对象的生命周期在当前行

```
void test01()
{
	Maker();//匿名对象的生命周期在当前行
	Maker(10);
	

	//注意，如果匿名对象有名字来接，那么就不是匿名对象

	Maker m1 = Maker();

	cout << "test01()函数结束" << endl;
}
```



## 7.拷贝构造函数调用的时机（重点）

1.对象以值方式给函数参数

```
class Maker
{
public:
	Maker()
	{
		cout << "无参构造函数" << endl;
	}
	Maker(int a)
	{
		cout << "有参构造函数" << endl;
	}
	Maker(const Maker &maker)
	{
		cout << "拷贝构造函数" << endl;
	}
	~Maker()
	{
		cout << "析构函数" << endl;
	}
};
//1.对象以值方式给函数参数
void func(Maker m)//Maker m=m1;
{

}

void test01()
{
	Maker m1;
	func(m1);


```

2.用一个已有的对象去初始化另一个对象

```
void test02()
{
	Maker m1;
	Maker m2(m1);
}
```

3.函数的局部对象以值的方式从函数返回，vs Debug(调试)模式下，会调用拷贝构造，vs Release（发行）模式下不会调用拷贝构造，qt也不调用

```
Maker func2()
{
	//局部对象
	Maker m;
	cout << "局部对象的地址:" << &m << endl;

	return m;
}

void test03()
{
	
	Maker m1 = func2();

	cout << "m1对象的地址：" << &m1 << endl;
}
```



## 8.构造函数的调用规则（重点难点）

1.如果程序员提供了有参构造，那么编译器不会提供默认构造函数，但是会提供默认的拷贝构造

```
void test01()
{
	//Maker m;//err

	//Maker m(10);//调用有参构造
	//Maker m2(m);//调用默认的拷贝构造
}
```

2.如果程序员提供了拷贝构造函数，那么编译器不会提供默认的构造函数和默认的拷贝构造函数

```
void test02()
{
	//Maker m;
}
```



## 9.多个对象的构造和析构（重点难点）

1.如果类有成员对象，那么先调用成员对象的构造函数，再调用本身的构造函数，析构函数的调用顺序反之
2.成员对象的构造函数调用和定义顺序一样
3.注意，如果有成员对象，那么实例化对象时，必须保证成员对象的构造和析构能被调用

```
class BMW
{
public:
	BMW()
	{
		cout << "BMW构造" << endl;
	}

	~BMW()
	{
		cout << "BMW析构" << endl;
	}
};

class Buick
{
public:
	Buick()
	{
		cout << "Buick构造" << endl;
	}

	~Buick()
	{
		cout << "Buick析构" << endl;
	}
};

class Maker
{
public:
	Maker()
	{
		cout << "Maker构造" << endl;
	}

	~Maker()
	{
		cout << "Maker析构" << endl;
	}
private:
	
	Buick bui;//成员对象
	BMW bmw;//成员对象
};

void test01()
{
	Maker m;
}
```

2.初始化列表

1.初始化列表是干什么用的，指定调用成员对象的某个构造函数

2.初始化列表只能写在构造函数

3.如果使用了初始化列表，那么所有的构造函数都要写初始化列表

4.如果有多个对象需要指定调用某个构造函数，用逗号隔开

5.可以使用对象的构造函数传递数值给成员对象的变量

```
class BMW2
{
public:

	BMW2(int a)
	{
		cout << "BMW2有参构造" << a << endl;
	}

	~BMW2()
	{
		cout << "BMW2析构" << endl;
	}
};

class Buick2
{
public:
	Buick2(int b,int c)
	{
		cout << "Buick2构造" << endl;
	}

	~Buick2()
	{
		cout << "Buick2析构" << endl;
	}
};

class Maker2
{
public:
	//初始化列表
	//注意1：初始化列表只能写在构造函数
	/*Maker2() :bmw(10)
	{
		cout << "Maker2构造" << endl;
	}*/
	//如果有多个对象需要指定调用某个构造函数，用逗号隔开
	Maker2(int a,int b,int c) :bmw(a), bui(b,c)
	{
		cout << "Maker2构造" << endl;
	}
	//注意2:如果使用了初始化列表，那么所有的构造函数都要写初始化列表
	Maker2(const Maker &m2) :bmw(40), bui(10,20)
	{

	}
	/*void printMaker2() : bmw(10)
	{

	}*/

	~Maker2()
	{
		cout << "Maker2析构" << endl;
	}
private:

	Buick2 bui;//成员对象
	BMW2 bmw;//成员对象
};

//初始化列表是调用成员对象的指定构造函数
void test02()
{
	Maker2 m(30,10,20);
}
```



## 10.对象的深浅拷贝（重点难点）

1.默认的拷贝构造函数进行了简单的赋值操作（浅拷贝）

2.浅拷贝的问题

同一块空间被释放两次

```
class Student
{
public:
	Student(const char *name, int Age)
	{
		pName = (char*)malloc(strlen(name) + 1);
		strcpy(pName, name);
		age = Age;
	}

	~Student()
	{
		cout << "析构函数" <<endl;
		if (pName != NULL)
		{
			free(pName);
			pName = NULL;
		}
	}
public:
	char *pName;
	int age;
};

void test02()
{
	Student s1("小花", 18);
	Student s2(s1);

	cout << "s1 Name=" << s1.pName << " s1 age=" << s1.age << endl;
	cout << "s2 Name=" << s2.pName << " s2 age=" << s2.age << endl;
}
```

3.深拷贝解决浅拷贝问题

自己写拷贝构造函数

```
	//深拷贝
	Student(const Student &stu)
	{
		cout << "自己的拷贝构造函数" << endl;
		//1.申请空间
		pName = (char*)malloc(strlen(stu.pName) + 1);
		//2.拷贝数据
		strcpy(pName, stu.pName);
		age = stu.age;
	}
```

