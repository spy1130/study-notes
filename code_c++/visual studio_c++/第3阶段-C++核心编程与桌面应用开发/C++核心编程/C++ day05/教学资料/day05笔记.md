## 01.数组类（了解）

1.目的：设计一个类，该类有数组的功能，可以存储数据，可以删除修改数据

2.设计核心数据

 1.属性：指针（指向堆区空间），数组实际存储的元素个数，数组容量

 2.方法：构造（开辟堆区空间），尾插，头插，指定位置插入，尾删，头删，获取指定位置的值，指定位置修改值，获取数组元素个数，获取数组容量，析构函数

3.代码实现（看代码）

## 02.运算符重载的概念（重点）

1.运算符重载，就是对已有的运算符重新进行定义，[赋予](http://baike.baidu.com/view/483609.htm)其另一种功能，以适应不同的数据类型。

2.**运算符重载的目的是让语法更加简洁**

3.**运算符重载不能改变本来寓意，不能改变基础类型寓意**

4.运算符重载的本质是另一种函数调用（是编译器去调用）

5.这个函数同一的名字叫operator

6.重载函数可以写成全局或成员函数

7.重载函数如果写成全局的，那么双目运算符左边的是第一个参数，右边是第二个参数

8.重载函数如果写成成员函数，那么双目运算符的左边是this,右边是第一个参数

9.不能改变运算符优先级，不能改变运算符的参数个数。

## 03.加号运算符重载（重点）

1.同类型的对象相加

```
class Maker
{
public:
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
	//写成成员函数，那么只需要一个参数，这个参数是加号的右边
	Maker operator+(Maker &m2)
	{
		Maker temp(this->id + m2.id, this->age + m2.age);

		return temp;
	}
public:
	int id;
	int age;
};

//全局方式 //3.编译器调用这个函数
//Maker operator+(Maker &p1,Maker &p2)//2.编译器检查参数是否对应，第一个参数是加的左边，第二参数是加号的右边
//{
//	Maker temp(p1.id + p2.id, p1.age + p2.age);
//
//	return temp;
//}

void test01()
{
	Maker m1(1, 20);
	Maker m2(2, 22);
	//+也叫双目运算符
	Maker m3=m1 + m2;//1.编译器看到两个对象相加，那么编译器会去找有没有叫operator+的函数

	cout << "id:" << m3.id << " age:" << m3.age << endl;

	//复数加
	Maker m4 = m1 + m2 + m3;
	cout << "id:" << m4.id << " age:" << m4.age << endl;
}
```

2.不同类型的对象相加

```
class Maker
{
public:
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
	
public:
	int id;
	int age;
};
class Student
{
public:
	Student()
	{
		mid = 0;
	}
	Student(int id)
	{
		mid = id;
	}
public:
	int mid;
};

Student operator+(Maker &m, Student &s)
{
	Student tmp(m.id + s.mid);

	return tmp;
	
}

Student operator+(Student &s, Maker &m)
{
	Student tmp(m.id + s.mid);

	return tmp;

}

void test()
{
	Maker m1(1, 18);
	Student s1(2);
	Student s2 = m1 + s1;

	s1 + m1;
}
```



## 04.减号运算符重载（重点）

```
class Maker
{
public:
	Maker(int id)
	{
		this->id = id;
	}
	Maker operator-(Maker &m2)
	{
		Maker tmp(this->id - m2.id);
		return tmp;
	}
public:
	int id;
};

int operator-(Maker &m,int b)
{
	return m.id-b;
}

void test()
{
	Maker m1(10);
	Maker m2(5);
	Maker m3 = m1 - m2;
	cout << m3.id << endl;

	int a = m3 - 5;
	cout << a << endl;
}
```



## 05.左移和右移运算符重载（重点难点）

1.左移运算符重载

​	1.cout是对象，<<是左移运算符

​	2.重载左移运算符是为了直接打印对象

​	3.形参和实参是一个对象

​	4.不能改变库类中的代码

​	5.ostream中把拷贝构造函数私有化了

​	4.如果要和endl一起使用，那么必须返回ostream的对象.

```
class Maker
{
	//如果要访问类的私有成员，那么把<<重载函数声明为友元
	friend ostream& operator<<(ostream &out, Maker &m);
public:
	Maker(int id,string name)
	{
		this->id = id;
		this->name = name;
	}

private:
	int id;
	string name;
};
//1.形参和实参是一个对象
//2.不能改变库类中的代码
//3.ostream中把拷贝构造函数私有化了
//4.如果要和endl一起使用，那么必须返回ostream的对象
ostream& operator<<(ostream &out, Maker &m)
{
	cout << m.id <<" "<<m.name<< endl;

	return out;
}

void test01()
{
	Maker m(10,"小花");
	cout << m << endl;
	cout << endl;
	/*
	endl是一个函数
	operator<<(endl）
	*/

	cout << 10;//内部重载了基础数据类型
}
```

2.右移运算符重载

```
class Maker
{
	friend istream & operator>>(istream &in, Maker &m);
public:
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	int getAge()
	{
		return age;
	}
private:
	string name;
	int age;
};

istream &operator>>(istream &in, Maker &m)
{
	in >> m.age;
	in >> m.name;

	return in;
}

void test02()
{
	Maker m("悟空", 15);
	Maker m2("悟空2", 25);

	cin >> m>>m2;

	cout << m.getAge() << endl;
	cout << m2.getAge() << endl;

}
```



## 06.赋值运算符重载（重点）

1.编译器默认给类提供了一个默认的赋值运算符重载函数

2.默认的赋值运算符重载函数进行了简单的赋值操作

```
class Maker
{
public:
	Maker()
	{
		id = 0;
		age = 0;
	}
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}
public:
	int id;
	int age;
};

void test()
{
	Maker m1(10, 20);
	Maker m2;

	m2 = m1;//赋值操作
	//默认的赋值运算符重载函数进行了简单的赋值操作
	cout << m2.id << " " << m2.age << endl;
}
```

3.当类有成员指针时，然后在构造函数中申请堆区空间，在析构函数中释放堆区空间，会出现同一块空间释放2次，然后内存泄漏，所以要重写赋值运算符重载函数

```
class Student
{
public:
	Student(const char *name)
	{
		pName = new char[strlen(name) + 1];
		strcpy(pName, name);
	}
	//防止浅拷贝
	Student(const Student &stu)
	{
		pName = new char[strlen(stu.pName) + 1];
		strcpy(pName, stu.pName);
	}
	//重写赋值运算符重载函数
	Student &operator=(const Student &stu)
	{
		//1.不能确定this->pName指向的空间是否能装下stu中的数据，所以先释放this->pName指向的空间
		if (this->pName != NULL)
		{
			delete[] this->pName;
			this->pName = NULL;
		}

		//2.申请堆区空间，大小由stu决定
		this->pName = new char[strlen(stu.pName) + 1];
		//3.拷贝数据
		strcpy(this->pName, stu.pName);

		//4.返回对象本身
		return *this;
	}	

	~Student()
	{
		if (pName != NULL)
		{
			delete[] pName;
			pName = NULL;
		}
	}

	void printStudent()
	{
		cout << "Name:" << pName << endl;
	}
public:
	char *pName;
};

void test02()
{
	Student s1("悟空");
	Student s2("小林");

	s1.printStudent();
	s2.printStudent();

	s1 = s2;//赋值操作

	s1.printStudent();
	s2.printStudent();
	
	//复数运算不会出错
	//s1 = s2 = s3;
}
```

4.赋值运算符重载函数中，为什么要返回引用

```
void test03()
{
	Student s1("a");
	Student s2("b");
	Student s3("c");

	s1 = s2 = s3;//s3赋值s2,s2赋值给s1

	cout << &(s2 = s3) << endl;
	cout << &s2 << endl;
	//如果返回的是值，s2=s3这个表达式会产生一个新的对象
	//s1=s2=s3,赋值运算符本来的寓意，是s3赋值s2,s2赋值给s1
	//也就是说s2=s3这个表达式要返回s2这个对象，所以要返回引用

}
```



## 07.关系运算符重载（了解）

```
class Maker
{
public:
	Maker()
	{
		id = 0;
		age = 0;
	}
	Maker(int id, int age)
	{
		this->id = id;
		this->age = age;
	}

	bool operator==(Maker &m)
	{
		if (this->id == m.id && this->age == m.age)
		{
			return true;
		}
		return false;
	}


	bool operator!=(Maker &m)
	{
		if (this->id != m.id || this->age != m.age)
		{
			return true;
		}
		return false;
	}
public:
	int id;
	int age;
};

void test()
{
	Maker p1(1, 20);
	Maker p2;

	if (p1 == p2)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}

	if (p1 != p2)
	{
		cout << "真" << endl;
	}
	else
	{
		cout << "假" << endl;
	}
}
```



## 08.前置加加和后置加加运算符重载（重点难点）

```
class Maker
{
	friend ostream &operator<<(ostream &out, Maker &m);
public:
	Maker(int a)
	{
		this->a = a;
	}
	//重载前置加加
	Maker &operator++()
	{
		++this->a;
		return *this;
	}

	//后置加加,
	Maker operator++(int)//占位参数，必须是int
	{
		//后置加加，先返回，后加加
		Maker tmp(*this);//1.*this里面的值a是等于2
		++this->a;//这个对象的a等3
		return tmp;
	}
private:
	int a;
};

ostream &operator<<(ostream &out, Maker &m)
{
	out << m.a << endl;
	return out;
}

void test02()
{
	Maker m1(1);
	cout << m1 << endl;//1
	cout << ++m1 << endl;//2
	//++(++m1);
	cout << m1++ << endl;//2  这里返回的拷贝的tmp对象
	cout << m1 << endl;//3 这里返回的是++this->a的对象

	//同等条件下，优先使用前置加加，不需要产生新的对象和调用拷贝构造

}
```



## 09.数组下标运算符重载（重点）

```
MyArray.h
class MyArray
{
public:
//重写赋值运算符重载函数
	MyArray&operator=(const MyArray &m);

	//要能当左右值
	int &operator[](int index);

};

MyArray.cpp
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

数组下标重载.cpp
void test02()
{
	MyArray arr;
	for (int i = 0; i < 20; i++)
	{
		arr[i] = i + 10;
	}

	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	MyArray arr2;
	arr2 = arr;
	for (int i = 0; i < 20; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	cout << arr2.Size() << endl;
}
```

