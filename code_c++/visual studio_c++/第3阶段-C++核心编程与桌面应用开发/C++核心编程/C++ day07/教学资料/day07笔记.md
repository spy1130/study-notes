## 01.多态（重点难点）

##### 1.什么是多态：

同一个操作作用于不同的对象，可以有不同的解释，会产生不同的效果，这就是多态

```
class People
{
public:
	//虚函数
	virtual void Mypro()
	{

	}
};

class xishi :public People
{
public:
	//重写父类的虚函数
	virtual void Mypro()
	{
		cout << "约西施" << endl;
	}
};

class wangzhaojun :public People
{
public:
	//重写父类的虚函数
	virtual void Mypro()
	{
		cout << "约王昭君" << endl;
	}
};



class diaochan :public People
{
public:
	//重写父类的虚函数
	virtual void Mypro()
	{
		cout << "约貂蝉" << endl;
	}
};

class yangguifei :public People
{
public:
	//重写父类的虚函数
	virtual void Mypro()
	{
		cout << "约杨贵妃" << endl;
	}
};


//同一个操作
void doLogin(People *pro)
{
	pro->Mypro();//产生不同的效果
}

void test()
{
	People *pro = NULL;
	pro = new xishi;
	doLogin(pro);//不同的对象
	delete pro;

	pro = new wangzhaojun;
	doLogin(pro);//不同的对象
	delete pro;

	pro = new diaochan;
	doLogin(pro);//不同的对象
	delete pro;

	pro = new yangguifei;
	doLogin(pro);//不同的对象
	delete pro;
}
```



##### 2.多态有什么用

1.可以解决项目中的紧耦合问题,提供程序的可扩展性

2.应用程序不必为每一个子类的功能调用编写代码，只需要对抽象的父类进行处理

##### 3.多态发生的三个条件

1.有继承。2.重写父类的虚函数。3.父类指针指向子类对象

## 02.多态的实现原理（重点难点）

```
class Animal
{
public:
	virtual void speak()
	{
		cout << "Anima speak()" << endl;
	}
	
};
class Dog :public Animal
{
public:
	virtual void speak()
	{
		cout << "Dog speak()" << endl;
	}
};

void test()
{
	cout << sizeof(Animal) << endl;

	Animal *animal = new Dog;
	animal->speak();
}
```



## 03.纯虚函数和抽象类(重点)

1.依赖倒转

业务层依赖抽象层，实现层依赖抽象层

```
//抽象层
class rule
{
public:
	virtual int getnum(int a,int b)
	{
		return 0;
	}
};

//实现层
class plus_rule :public rule
{
public:
	virtual int getnum(int a, int b)//重写父类的虚函数，依赖抽象层
	{
		return a+b;
	}
};




//业务层
int doLogin(rule *cal)
{
	
	int a = 10;
	int b = 20;
	

	int ret=cal->getnum(a, b);//依赖抽象层

	return ret;

}

void test()
{
	rule *r = NULL;
	r = new plus_rule;
	cout << doLogin(r) << endl;
	delete r;

}
```

2.开闭原则

对修改源代码关闭，对扩展新功能开发

```
//抽象层
class rule
{
public:
	virtual int getnum(int a,int b)
	{
		return 0;
	}
};

//实现层
class plus_rule :public rule
{
public:
	virtual int getnum(int a, int b)//重写父类的虚函数，依赖抽象层
	{
		return a+b;
	}
};
//扩展新功能
class miux_rule :public rule
{
public:
	virtual int getnum(int a, int b)
	{
		return a - b;
	}
};


//业务层
int doLogin(rule *cal)
{
	
	int a = 10;
	int b = 20;
	

	int ret=cal->getnum(a, b);//依赖抽象层

	return ret;

}

void test()
{
	rule *r = NULL;
	r = new plus_rule;
	cout << doLogin(r) << endl;
	delete r;
	//增加的代码
	r = new miux_rule;
	cout << doLogin(r) << endl;
	delete r;

}
```

3.纯虚函数

```
class rule
{
public:
	//纯虚函数
	virtual int getnum(int a, int b) = 0;
};
```

4.抽象类

1.有纯虚函数的类叫抽象类，不能实例化对象

```
//有纯虚函数的类叫抽象类，不能实例化对象
class rule
{
public:
	//纯虚函数
	virtual int getnum(int a, int b) = 0;
};

void test02()
{
	//抽象类不能实例化对象
	//rule r;
}
```

2.如果子类继承抽象类，子类必须实现抽象类的所有纯虚函数，不然子类也变为抽象类

```
class Maker
{
public:
	virtual void func1() = 0;
	virtual void func2() = 0;
};

class Son :public Maker
{
public:
	virtual void func1()
	{

	}
	virtual void func2()
	{

	}
};

void test03()
{
	Son s;
}
```



## 04.接口的定义（了解）

1.所谓的接口，即将内部实现细节封装起来，外部用户用过预留的接口可以使用接口的功能而不需要知晓内部具体细节。C++中，通过类实现面向对象的编程，而在基类中只给出纯虚函数的声明，然后在派生类中实现纯虚函数的具体定义的方式实现接口，不同派生类实现接口的方式也不尽相同

```
//抽象类
class Father
{
public:
	virtual void func1() = 0;//接口的声明
	virtual void func2(int a) = 0;
	virtual void func3(int a,int b) = 0;
};

class Son :public Father
{
public:
	virtual void func1()//接口的实现
	{

	}
	virtual void func2(int a)
	{

	}
	virtual void func3(int a, int b)
	{

	}
};
```



## 05.模版方法模式（重点）

1.在抽象类中确定好函数的调用顺序

```
class Drink
{
public:
	//煮水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//导入杯中
	virtual void PourInCup() = 0;
	//加点辅料
	virtual void addSonm() = 0;

	//模版方法,把调用函数的顺序确定下来
	void func()
	{
		Boil();
		Brew();
		PourInCup();
		addSonm();
	}
};
```



## 06.虚析构函数和纯虚析构函数（重点）

1.虚析构函数是为了解决基类指针指向派生类对象，并用基类指针释放派生类对象

```
class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造" << endl;
	}

	//虚析构函数会调用子类的析构函数
	virtual ~Animal()
	{
		cout << "Animal的析构" << endl;
	}
};

class Son :public Animal
{
public:
	Son()
	{
		cout << "Son的构造" << endl;
		pName = new char[64];
		memset(pName, 0, 64);
		strcpy(pName, "如花");
	}

	~Son()
	{
		cout << "Son的析构" << endl;
		if (pName != NULL)
		{
			delete[] pName;
			pName = NULL;
		}
	}

public:
	char *pName;
};

void test()
{
	Animal *animal = new Son;
	delete animal;
}
```

2.纯虚析构函数，有纯虚析构函数的类是抽象类，不能实例化对象

注意：纯虚析构函数需要在类外实现

```
class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造" << endl;
	}

	//虚析构函数会调用子类的析构函数
	/*virtual ~Animal()
	{
		cout << "Animal的析构" << endl;
	}*/

	//纯虚析构函数，纯虚析构函数需要在类外实现
	virtual ~Animal() = 0;
};

//在类外实现纯虚析构函数
Animal::~Animal()
{
	cout << "Animal的纯虚析构" << endl;
}
```

3.虚析构函数和纯虚析构函数的区别：

1.有纯虚析构函数的类是抽象类，不能实例化对象，而且要在类外实现

2.虚析构函数不需要在类外实现

## 07.多态案例_动物园（重点）

1.创建动物基类

```
class Animal
{
public:
	virtual void speak() = 0;
};
```

2.创建动物

```
class Dog :public Animal
{
public:
	Dog(string name)
	{
		this->name = name;
	}
	virtual void speak()
	{
		cout << "小狗" << name << "汪汪汪" << endl;
	}
private:
	string name;
};

class Dark :public Animal
{
public:
	Dark(string name,string type)
	{
		this->name = name;
		this->type = type;
	}
	virtual void speak()
	{
		cout <<type<<"品牌的"<< "小鸭" << name << "嘎嘎嘎" << endl;
	}
private:
	string name;
	string type;
};

class Tiger :public Animal
{
public:
	Tiger(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
	virtual void speak()
	{
		cout << age << "岁" << "老虎" << name << "嗷嗷嗷" << endl;
	}
private:
	string name;
	int age;

};
```

3.创建动物园

```
class Zoo
{
public:
	Zoo()
	{
		mCapacity = 1024;
		mSize = 0;
		//申请空间，存储Animal*的空间，指针数组
		this->p = new Animal*[mCapacity];
	}

	//增加动物
	int AddAnimal(Animal* animal)
	{
		if (mCapacity == mSize)
		{
			return -1;
		}
		//把指针存储到指针数组
		this->p[mSize] = animal;
		mSize++;

		return 0;
	}

	void StartSpeak()
	{
		for (int i = 0; i < mSize; i++)
		{
			p[i]->speak();
		}
	}

	//析构函数
	~Zoo()
	{
		//先释放指针数组中指针指向的堆区空间
		for (int i = 0; i < mSize; i++)
		{
			if (p[i] != NULL)
			{
				delete p[i];
				p[i] = NULL;
			}
		}

		//释放指针数组
		delete[] p;
		p = NULL;
	}


private:
	Animal* *p;
	int mCapacity;//容量
	int mSize;

};

```

4.使用

```
void test()
{
	//创建动物园
	Zoo *zoo = new Zoo;

	//添加动物
	zoo->AddAnimal(new Dog("晋三"));
	zoo->AddAnimal(new Dark("黑鸭", "周黑鸭"));
	zoo->AddAnimal(new Tiger("三胖", 35));

	zoo->StartSpeak();

	//烧了动物园
	delete zoo;
}
```

## 08.父类引用子类对象

```
class Animal
{
public:
	virtual void speak()
	{
		cout << "Animal speak()" << endl;
	}
};

class Dog :public Animal
{
public:
	virtual void speak()
	{
		cout << "Dog speak()" << endl;
	}
};

void test()
{
	Animal &animal = Dog();
	animal.speak();

	Animal* dog = new Dog();
	Animal* &an = dog;
	an->speak();
	delete dog;
}
```



## 09.重写，重载，重定义（隐藏）

1.重载，同一作用域的同名函数

2.重写（覆盖）:

​	1. 有继承

​	2.子类（派生类）重写父类（基类）的virtual函数

​	3.函数返回值，函数名字，函数参数，必须和基类中的虚函数一致

3.重定义（隐藏）

​	1. 有继承

​	2.子类（派生类）重新定义父类（基类）的同名成员（非virtual函数）

