## 01.引用的使用场景（重点）

1.引用作为函数参数

```
//1.引用作为函数参数
void func(int &a, int &b)
{
	int sum = a + b;
	cout << "sum=" << sum << endl;
}

void test01()
{
	int a = 10;
	int b = 20;
	func(a, b);
}
```

2.引用作为函数的返回值

```
//2.引用作为函数的返回值
int& func2()
{
	int b = 10;//注意1：不要返回局部变量的引用
	int &p = b;
	return p;
}
int &func3()
{
	static int b = 10;
	return b;
}
void test02()
{
	int &q = func2();
	q = 100;
	cout << q << endl;

	func2() = 200;
	cout << q << endl;
////---------上面的代码是错误，只是编译器没有检测出来
	cout << "func2="<<func2() << endl;

	func3() = 100;//注意2：如果要函数当左值，那么该函数必须返回引用
	cout << "func3()=" << func3() << endl;
}
```



## 02.常量引用（了解）

```
int &ref=10;//err
const int &ref2=10;//ok
原理是:int tmp=10;const int &ref=tmp;
```



## 03.内联函数（了解）

1.宏函数的缺陷

```
#define ADD(x,y) x+y
//在普通函数前面加上inline是向编译器申请成为内联函数
//注意：加inline可能成为内联函数，可能不成为内联函数
inline int Add(int x, int y)
{
	return x + y;
}

void test()
{
	//10+20*2
	int ref = ADD(10, 20) * 2;
	cout << "ref=" << ref << endl;

	int ref2 = Add(10, 20) * 2;
	cout << "ref2=" << ref2 << endl;
}

#define COMAPD(x,y) ((x)<(y)?(x):(y))
inline int func(int x, int y)
{
	return x < y ? x : y;
}
void test02()
{
	int a = 1;
	int b = 3;
	//                        ((++a)<(b)?(++a):(b))      
	//cout << "COMAPD(x,y)=" << COMAPD(++a, b) << endl;//3
	cout << "func=" << func(++a, b) << endl;//2
}

```

2.什么情况不会成为内联函数

​	1.存在过多的条件判断语句

​	2.函数体过大

​	3.对函数进行取址操作

​	4.存在任何形式的循环语句

3.内联函数的好处

​	1.有宏函数的效率，没有宏函数的缺点

​	2.类的成员函数默认加上inline

4.在普通函数前面加上inline是申请成为内联函数

## 04.函数的默认参数（重点）

1.函数的默认参数就是给函数的形参赋值

```
int myFunc(int a, int b = 0)//int b=0;这就是函数的默认参数，不一定是0
{
	return a + b;
}
void test01()
{
	//函数的默认参数的作用
	//当函数内常要用到形参的某个值，但偶尔要使用其他值
	//增加函数的灵活性
	cout << myFunc(10, 20) << endl;
	cout << myFunc(10)<< endl;
}
```

2.函数的默认参数的注意事项

```
//注意1：函数的默认参数后面的参数必须都是默认参数
int myFunc2(int a, int b = 0, int c=2,int d=3)
{
	return a + b + c + d;
}
//注意2：函数的声明和实现不能同时有函数的默认参数
void myFunc3(int a, int b);
void myFunc3(int a, int b = 0)
{

}
```

## 05.函数的占位参数（了解）

```
//函数的占位参数,占位参数在后面运算符重载时区分前加加或后加加
void func(int a,int=10)//占位参数也有默认值
{

}

void test02()
{
	func(10);
}
```

函数的默认参数和占位参数的混搭

```
//占位参数和默认参数混搭
void func2(int=10, int a=20)
{

}
void test03()
{
	func2();
	func2(10);
	func2(10,30);
}
```



## 06.函数重载（重点）

1.函数重载是：允许函数名相同，这种现象叫函数重载

2.函数重载的作用：是为了方便使用函数名

3.函数重载的条件：同一个作用域，参数的个数不同，参数的顺序不同，参数的类型不同

```
//参数的个数不同
void func()
{
	cout << "func()" << endl;
}

void func(int a)
{
	cout << "func(int a)" << endl;
}

//参数的类型不同
void func(char c)
{
	cout << "func(char c)" << endl;
}
//参数的顺序不同
void func(int a, double b)
{
	cout << "func(int a, double b)" << endl;
}
void func(double b, int a)
{
	cout << "func(double b, int a)" << endl;
}
```

4.调用重载函数的注意：

严格的类型匹配，如果类型不匹配，那么尝试转换，转换成功就掉用，失败就报错

```
void test01()
{
	int a = 10;
	double b = 3.14;

	func();
	//func(b);// err double转换不了成为int或char
	func(a, b);
	func(b, a);
	char c = 'c';
	func(c);//char转换int成功，调用int参数的函数
}
```

5.函数重载和函数的默认参数一起使用，需要注意二义性问题

```
//函数重载和函的默认参数一起使用
void myfunc(int a, int b = 0)
{
	cout << "myfunc(int a, int b = 0)" << endl;
}

void myfunc(int a)
{
	cout << "myfunc(int a)" << endl;
}

void test02()
{
	//myfunc(10); err,二义性问题，不知道调用哪个函数
}
```

6.函数的返回值不作为函数重载的条件

编译器是通过你调用函数时，传入的参数来判断调用重载的哪个函数，我们调研函数时不需要写返回值，所以返回值不能成为函数重载的条件

## 07.函数重载的原理（重点）

1.函数重载的原理是在汇编时，给各个函数取别名，C语言不能重载的原因是没有取别名

2.生成汇编文件:gcc -S test.c -o test.s         g++ -S test.cpp -o test2.s

3.查看内容:type 文件名

## 08.C++调用C语言的函数（重点）

1.C++的函数在汇编时，会给函数取别名，C语言的不会，这时，如果C++来调用C语言的函数，C++会去找取了别名的函数，但是C语言没有取别名，这时会出错

```
test.h文件中

//这是告诉C++编译器，找下面的函数，要以C语言的方式去寻找
#ifdef __cplusplus
extern "C"
{
#endif
	void func();//C语言的函数声明


#ifdef __cplusplus
}
#endif
```



## 09.类和对象的概念（重点）

1.类是自定义数据类型，是C语言的结构体进化而成的

2.对象是类实例化出的，用数据类型定义一个变量

```
class Maker//这个是类
{
public:
	int a;//成员属性（成员变量）
	void func()//成员方法（成员函数）
	{
		cout << "func" << endl;
	}
};

int main()
{
	Maker m;//m就是对象

	system("pause");
	return EXIT_SUCCESS;
}
```



## 10.类的封装（重点）

1.封装是把属性（变量）和方法（函数）封装到类内，然后给这些数据赋予权限

2.为什么要有封装

​	1.防止乱调用函数和变量，出现错误

​	2.维护代码更方便

3.权限

```
//封装：1,把属性和方法放到类中,2.给这些数据赋予权限
class Maker
{
public://公有权限
	void set(string Name,int Id)
	{
		id = Id;
		name = Name;
	}
	void printMaker()
	{
		cout << "id=" << id << " name=" << name << endl;
	}
private://私有
	int id;
	string name;

protected://保护
	int a;
};
//继承
class Son :public Maker
{
	void func()
	{
		a = 20;//子类的类内可以方法父类的保护权限的成员
		
	}
};
//类外不能访问私有权限的成员
//类外可以访问公有权限的成员
//类外不能访问保护权限的成员
//子类的类内可以方法父类的保护权限的成员
//类内是没有权限之分

void test()
{
	Maker m;
	m.set("小花",1);
	m.printMaker();
	

}
```

4.尽量把属性设置为私有权限

1.可以控制属性的读写权限

2.可赋予客户端访问数据的一致性

3.可以保护属性的合法性

## 11.类和结构体的区别（了解）

结构体的默认权限是公有的，类的默认权限是私有的

