## 01.explicit的作用(了解)

```
class Maker
{
public:
	//explicit只能放在构造函数前面，构造函数只有一个参数或其他参数有默认值时
	explicit Maker(int n)//防止编译器优化Maker m=10;这种格式
	{

	}
};

int main()
{
	//Maker m = 10;err
}
```



## 02.C++的堆区空间的申请和释放（重点）

##### 1.申请和释放变量空间

1.为什么要有新的方法申请和释放堆区空间

因为用C语言的方式不会调用构造和析构函数

2.C++中申请堆区空间和释放堆区空间用什么关键字

申请堆区空间用new,释放空间用delete

```
class Maker
{
public:
	Maker()
	{
		cout << "构造函数" << endl;
	}

	Maker(int a)
	{
		cout << "有参构造函数" << endl;
	}
	~Maker()
	{
		cout << "析构函数" << endl;
	}
};

void test02()
{
	//用new方式申请堆区空间，会调用类的构造函数
	Maker *m = new Maker;

	//释放堆区空间，会调用类的析构函数
	delete m;
	m = NULL;

	Maker *m2 = new Maker(10);

	delete m2;
	m2 = NULL;
}
```

##### 2.申请和释放数组空间

1.new创建基础类型的数组

```
void test01()
{
	//申请基础数据类型的数组
	int *pInt = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//不推荐
	for (int i = 0; i < 10; i++)
	{
		pInt[i] = i + 1;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << pInt[i] << " ";
	}

	cout << endl;

	char *pChar = new char[64];
	memset(pChar, 0, 64);
	strcpy(pChar, "小话");
	cout << pChar << endl;

	//注意：如果new时有中括号，那么delete时也要有中括号
	delete[] pInt;
	delete[] pChar;

}
```

2.new创建对象数组

```
class Maker
{
public:
	Maker()
	{
		cout << "构造函数" << endl;
	}

	Maker(int a)
	{
		cout << "有参构造函数" << endl;
	}
	~Maker()
	{
		cout << "析构函数" << endl;
	}
};

void test02()
{
	Maker *ms = new Maker[2];//调用无参构造

	delete[] ms;

	//大部分编译器不支持这种写法，(聚合初始化）
	//Maker *ms2 = new Maker[2]{Maker(10), Maker(20)};
}
```

3.delete void*可能出错,不会调用对象的析构函数

```
void test03()
{
	void *m = new Maker;

	//如果用void*来接new的对象，那么delete时不会调用析构函数
	delete m;
	//在编译阶段，那么编译器就确定好了函数的调用地址，
	//C++编译器不认识void*,不知道void*指向那个函数，所以不会调用析构函数
	//这种编译方式叫静态联编
}
```

4.C和C++的申请和释放堆区空间不要混用

##### 3.和C的共同和区别之处

共同：都是申请堆区空间和释放堆区空间

区别：C++的会调用构造和析构函数

## 03.静态成员（了解）

1.静态成员变量的生命周期是整个程序，作用域在类内

2.静态成员变量要在类内声明，类外初始化

3.静态成员变量属于类，不属于对象，是所有对象共享

4.静态成员变量可以用类访问，也可以用对象访问

```
class Maker
{
public:
	Maker()
	{
		
	}
public:
	//1.静态成员变量的生命周期是整个程序，作用域在类内
	static int a;
};
//2.静态成员变量要在类内声明，类外初始化
int Maker::a = 100;
void test01()
{
	//3.静态成员变量属于类，不属于对象，是所有对象共享
	cout << Maker::a << endl;
	Maker m;
	cout << m.a << endl;
	//4.静态成员变量可以用类访问，也可以用对象访问
}
```

5.静态成员函数只能访问静态成员变量

```
class Maker2
{
public:
	Maker2()
	{

	}
	//静态成员函数只能访问静态成员变量
	static void setA(int a)
	{
		a2 = a;
		cout << "a2=" << a2 << endl;
		//a1 = a;不能访问普通成员变量
	}
public:
	int a1;
	static int a2;
};
int Maker2::a2 = 200;
void test02()
{
	Maker2::setA(300);
}
```

6.静态成员也有权限，如果为私有，类外也不可以访问

```
class Maker3
{
private:
	static void func()
	{
		cout << "a3=" << a3 << endl;
	}
private:
	static int a3;
};
int Maker3::a3 = 300;
void test03()
{
	//Maker3::func();err
}
```

7.const修饰的静态成员变量，最好在类内初始化

```
//const修饰的静态成员变量最好在类内初始化
class Maker4
{
public:
	const static int a = 20;
	const static int b;
};
//类外也可以初始化
const int Maker4::b = 30;
```

8.普通成员函数可以访问静态成员变量

```
class Maker5
{
public:
	void func()
	{
		cout << "a=" << a << endl;
	}
public:
	static int a;
};

//类外也可以初始化
int Maker5::a = 30;

void test04()
{
	Maker5 m;
	m.func();
	
}
```



## 04.C++的对象模型（重点）

1.空类的大小是1.

2.类的成员函数不占用类的大小，静态成员变量不占用类的大小，静态成员函数不占用类的大小

3.普通成员变量占用类的大小

4.类的成员中，成员函数和成员变量是分开存储



## 05.this指针（重点难点）

1.每个对象都有一个隐藏的this指针，但不属于对象，是编译器添加的

2.编译器会把this指针传入成员函数内

3.this指针指向对象的存储空间

4.this的作用:

```
class Maker2
{
public:
	//1.当形参名和成员变量名相同时，用this指针区分
	Maker2(int id)
	{
		this->id = id;
	}
	//2.返回对象的本身
	Maker2 &getMaker2()
	{
		return *this;//运算符重载时有用
	}
public:
	int id;
};
```

5.拓展

1.this指针指向的空间有没有存储静态成员变量？

没有

2.this指针的指向可以改变吗？

this指针的指向不能改变，也就是说this是Maker *const this;

6.防止空指针调用成员函数

```
class Maker
{
public:
	Maker()
	{
		a = 20;
	}

	void printMaker()
	{
		if (this == NULL)
		{
			cout << "this==NULL" << endl;
			return;
		}
		
		cout << this->a << endl;
	}
private:
	int a;
};

void test()
{
	Maker *m = NULL;
	m->printMaker();
}
```



## 06.常函数和常对象（重点）

1.常函数

1.在函数的()后面加上const，这个函数就是常函数

2.常函数内不能修改普通成员变量

3.const修饰的是this指针指向的空间中的变量不能改变

4.mutable修饰的成员变量在常函数中可以修改

```
class Maker
{
public:
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
		score = 100;
	}
	//常函数,1.函数的()后面添加const,该函数是常函数
	void printMaker()const
	{
		//id = 100;err//2.常函数内不能修改普通成员变量
		//3.const修饰的是this指针指向的空间中的变量不能改变
		//Maker *const this;
		//const Maker*const this;这是常函数修饰的
		score = 200;//4.mutable修饰的成员变量在常函数中可以修改
		cout << "score=" << score << endl;
	}
public:
	int id;
	int age;
	mutable int score;//mutable修饰的成员变量

};
void test01()
{
	Maker m(1, 18);
	m.printMaker();
}
```

2.常对象

1.在数据类型前面加上const，让对象成为常对象

2.常对象可以调用常函数

3.常对象可以修改mutable修饰的成员变量

```
class Maker
{
public:
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
		score = 100;
	}
	//常函数,1.函数的()后面添加const,该函数是常函数
	void printMaker()const
	{
		//id = 100;err//2.常函数内不能修改普通成员变量
		//3.const修饰的是this指针指向的空间中的变量不能改变
		//Maker *const this;
		//const Maker*const this;这是常函数修饰的
		score = 200;//4.mutable修饰的成员变量在常函数中可以修改
		cout << "score=" << score << endl;
	}
	void func()
	{
		cout << "func" << endl;
	}
public:
	int id;
	int age;
	mutable int score;//mutable修饰的成员变量

};

void test()
{
	//1.在数据类型前面加上const，让对象成为常对象
	const Maker m(1, 18);//常对象

	//m.id = 100;//常对象不能改变普通成员变量的值
	//m.func();//常对象不能调用普通成员函数
	m.printMaker();//2.常对象可以调用常函数
	m.score = 500;//常对象可以修改mutable修饰的成员变量

	Maker m2(2, 20);
	m2.printMaker();//普通对象也可以调用常函数

}
```



## 07.友元（重点难点）

1.友元的概念

友元是赋予全局函数，类的成员函数，类，访问别的类的私有成员权限

注意：友元函数不是类的成员函数

1.全局友元函数

```
class Building
{
	//声明这个全局函数为Building类的友元函数
	friend void GoodGay(Building &bd);
public:
	Building()
	{
		keting = "客厅";
		woshi = "卧室";
	}

public:
	string keting;
private:
	string woshi;
};

void GoodGay(Building &bd)
{
	cout << "好基友访问:" << bd.keting << endl;
	cout << "好基友访问:" << bd.woshi << endl;
}

void test01()
{
	Building my;

	GoodGay(my);
}
```

2.友元类

```
class Building
{
	//声明GoodF类为Building类的友元类
	friend class GoodF;
	friend class GoodF2;
public:
	Building()
	{
		keting = "客厅";
		woshi = "卧室";
	}

public:
	string keting;
private:
	string woshi;
};

class GoodF
{
public:
	void func(Building &bd)
	{
		cout << "访问:" << bd.keting << endl;
		cout << "访问:" << bd.woshi << endl;//通过参数访问私有成员
	}
};
//1.通过传入参数来访问类的私有成员
void test01()
{
	Building bd;
	GoodF f;
	f.func(bd);
}

//2.通过类内指针来访问类的私有成员
class GoodF2
{
public:
	GoodF2()
	{
		cout << "无参构造" << endl;
		pbu = new Building;
	}
	void func()
	{
		cout << "访问:" << pbu->keting << endl;
		cout << "访问:" << pbu->woshi << endl;//通过成员指针访问私有成员
		
	}
	//拷贝构造
	GoodF2(const GoodF2 &f2)
	{
		cout << "拷贝构造" << endl;
		//1.申请空间
		pbu = new Building;//new已经调用了Building的构造函数,不用再复制对象属性

	}
	~GoodF2()
	{
		cout << "析构函数" << endl;
		if (pbu != NULL)
		{
			cout << "pbu" << endl;
			delete pbu;
		}
	}
public:
	Building *pbu;
};

void test02()
{
	GoodF2 f;
	f.func();

	GoodF2 f2 = f;

}
```

3.类的友元成员函数（难点）

```
//1.编译器知道类的声明，不知道类的结构
class Building;//声明类
class GoodGay
{
public:
	void func(Building &bud);
};
class Building
{
	//声明GoodGay类的成员函数func成为Building类的友元函数
	friend void GoodGay::func(Building &bud);
public:
	Building()
	{
		keting = "客厅";
		woshi = "卧室";
	}

public:
	string keting;
private:
	string woshi;
};


void GoodGay::func(Building &bud)
{
	cout << "访问:" << bud.keting << endl;
	cout << "访问:" << bud.woshi << endl;
}

void test()
{
	Building bud;
	GoodGay GF;
	GF.func(bud);
}
```

4.友元的注意：

1．友元关系不能被继承。

2．友元关系是单向的，类A是类B的朋友，但类B不一定是类A的朋友。

3.友元关系不具有传递性。类B是类A的朋友，类C是类B的朋友，但类C不一定是类A的朋友。

## 08.单例模式（重点难点）

1.单例模式是一个类只能实例化一个对象

2.实现单例模式的思路

​	1.把无参构造函数和拷贝构造函数私有化

​	2.定义一个类内的静态成员指针

​	3.在类外初始化时，new一个对象

​	4.把指针的权限设置为私有，然后提供一个静态成员函数让外面获取这个指针

```
//单例模式是一个类只能实例化一个对象
class Maker
{
	//1.把构造函数私有化
private:
	Maker()
	{
	}
	Maker(const Maker &m)
	{

	}
public:
	//静态成员函数，访问静态成员变量
	//4.把指针的权限设置为私有，然后提供一个静态成员函数让外面获取这个指针
	static Maker* getMaker()
	{
		return pMaker;
	}
private:
	//2.定义一个类内的静态成员指针
	static Maker *pMaker;
};
//3.在类外初始化时，new一个对象
Maker *Maker::pMaker = new Maker;//这里可以new是因为在Maker::作用域，编译器把它当成在类内

void test()
{
	//Maker m;
	Maker *m = Maker::getMaker();
	Maker *m2 = Maker::getMaker();
	cout << "m=" << m << endl;
	cout << "m2=" << m2 << endl;

	//Maker m3 = *m;//调用拷贝构造，这里会产生新对象，所以要把拷贝构造也私有化
	//cout << "m3=" << &m3 << endl;
}
```

3.单例模式案例（需求：获取打印机打印次数）

```
//需求，获取打印机使用的次数
class Printer
{
private:
	//1.把无参构造和拷贝构造私有化
	Printer()
	{
		mcount = 0;
	}
	Printer(const Printer &p)
	{

	}
public:
	static Printer *getPrinter()
	{
		return p;
	}

	void printPrinter(string name)
	{
		cout << name << ":打印" << endl;
		mcount++;
	}
	int getCount()
	{
		return mcount;
	}
private:
	int mcount;//记录打印打印的次数
	//2.定义静态成员指针
	static Printer *p;
};
//3.类外进行初始化，new对象
Printer *Printer::p = new Printer;

void test()
{
	//销售部
	Printer *p1 = Printer::getPrinter();
	p1->printPrinter("销售部");

	//技术部
	Printer *p2 = Printer::getPrinter();
	p2->printPrinter("技术部");

	//公关部
	Printer *p3 = Printer::getPrinter();
	p3->printPrinter("公关部");

	Printer *p4 = Printer::getPrinter();
	cout << "打印使用的次数:"<<p4->getCount() << endl;

}
```

