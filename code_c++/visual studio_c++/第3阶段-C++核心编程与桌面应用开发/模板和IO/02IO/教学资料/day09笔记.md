## 01.C++类型转换(了解)

**静态转换**：

用于[类层次结构](http://baike.baidu.com/view/2405425.htm)中基类（父类）和[派生类](http://baike.baidu.com/view/535532.htm)（子类）之间指针或引用的转换

用于基本数据类型之间的转换，如把int转换成char，把char转换成int。这种转换的安全性也要开发人员来保证

**动态转换：**

l  ynamic_cast主要用于类层次间的上行转换和下行转换；

l  在类层次间进行上行转换时，dynamic_cast和static_cast的效果是一样的；

l  在进行下行转换时，dynamic_cast具有类型检查的功能，比static_cast更安全；

**常量转换**

l  常量指针被转化成非常量指针，并且仍然指向原来的对象；

l  常量引用被转换成非常量引用，并且仍然指向原来的对象；

**重新解释转换**

这是最不安全的一种转换机制，最有可能出问题。

主要用于将一种数据类型从一种类型转换为另一种类型。它可以将一个指针转换成一个整数，也可以将一个整数转换成一个指针.

## 02.异常基本概念（了解）

**异常处理就是处理程序中的错误。所谓错误是指在程序运行的过程中发生的一些异常事件**

## 03.异常的作用（了解）

//C语言处理异常的方法的缺陷：
//1.返回值意思不明确
//2.返回值只能返回一条信息
//3.返回值可以忽略

C++的异常可以解决上面的问题

## 04.异常的基本语法（重点）

```
int func(int a, int b)
{
	if (b == 0)
	{
		//2.抛出异常
		throw 10;//抛出一个int类型的异常，
	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;
	//1.把有可能出现异常的代码块放到try中
	try
	{
		func(a, b);
	}
	catch (int)//3.接收一个int类型的异常
	{
		cout << "接收一个int类型的异常" << endl;
	}

}
```



## 05.异常代码的执行流程（了解）

```
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int func(int a, int b)
{
	if (b == 0)
	{
		//第二步：
		throw 10;//抛出一个int类型的异常，
		cout << "throw后的代码" << endl;
	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;
	
	try
	{
		func(a, b);//第一步：
		cout << "func后的代码" << endl;
	}
	catch (int)//第三步：
	{
		cout << "接收一个int类型的异常" << endl;
	}

}
int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}


```



## 06.异常的优势（重点）

1.用户不知道返回值是什么意思，异常可以抛出对象，对象中可以包含很多成员函数，可以有很信息

```
class Maker
{
public:
	void printMaker()
	{
		cout << "除数不能为0" << endl;
	}
};

int func(int a, int b)
{
	if (b == 0)
	{
		Maker m;
		throw m;
		
	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;

	try
	{
		func(a, b);
		
	}
	catch (int)
	{
		cout << "接收一个int类型的异常" << endl;
	}
	catch (Maker maker)
	{
		cout << "接收一个Maker类型的异常" << endl;
		maker.printMaker();
	}

}
```

2.返回值用户可以忽略，但异常不能忽略，如果忽略给你报错

3.返回值只能返回一条信息，但是对象有成员函数，可以包含多个信息

4.逐层依赖处理异常

```
int func(int a, int b)
{
	if (b == 0)
	{
		//Maker m;
		//throw m;//抛出一个Maker类型的异常
		throw 20.22;//抛出一个double类型的异常
		
	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;

	try
	{
		func(a, b);
		
	}
	catch (int)
	{
		cout << "接收一个int类型的异常" << endl;
	}
	catch (Maker maker)
	{
		cout << "接收一个Maker类型的异常" << endl;
		maker.printMaker();
	}
	catch (double s)
	{
		//不想处理异常，可以往上抛出，抛给调用本函数的函数
		throw;
	}


}

int main()
{
	try
	{
		test();
	}
	catch (double d)
	{
		cout << "接收一个double类型的异常" << endl;
	}




	system("pause");
	return EXIT_SUCCESS;
}

```



## 07.异常的严格类型匹配（重点）

```
int func(int a, int b)
{
	if (b == 0)
	{
		//Maker m;
		//throw m;//抛出一个Maker类型的异常
		//throw 20.22;//抛出一个double类型的异常
		//throw 'c';
		throw 20.0f;

	}

	return a / b;
}
void test()
{
	int a = 10;
	int b = 0;

	try
	{
		func(a, b);

	}
	catch (int)
	{
		cout << "接收一个int类型的异常" << endl;
	}
	catch (double s)
	{
		cout << "接收一个double类型的异常" << endl;
	}
	catch (char)
	{
		cout << "接收一个char类型的异常" << endl;
	}
	catch (...)//接收其他类型的异常
	{
		cout << "接收一个其他类型的异常" << endl;
	}


}
```



## 08.异常的接口声明（了解）

```
void func() throw(int,char) //只允许抛出 int 或者 char异常
{
    throw 10; //抛出一个double类型的异常，QT上程序会档
}
int main()
{
        try
        {
            func();
        }
        catch(int)
        {

            cout << "int";
        }
        catch(...)
        {
            cout << ".....";
        }
    return 0;
}
```



## 09.栈解旋(重点)

1在抛出异常的函数中，如果抛出异常之后，但函数没有结束，这时，栈上申请的对象都会被释放这就叫栈解旋

```
class Maker
{
public:
	Maker()
	{
		cout << "Maker的构造" << endl;
	}
	Maker(const Maker &m)
	{
		cout << "Maker的拷贝构造" << endl;
	}
	~Maker()
	{
		cout << "Maker的析构" << endl;
	}
};

void func()
{
	//在抛出异常的函数中，如果抛出异常之后，但函数没有结束，这时，栈上申请的对象都会被释放
	//这就叫栈解旋
	Maker m;
	throw m;//这个m是Maker m拷贝一份的

	cout << "func函数结束" << endl;
}

void test()
{
	try
	{
		func();
		cout << "func()代码后" << endl;
	}
	catch (Maker)
	{
		cout << "接收一个Maker类型的异常" << endl;
	}


}
```



## 10.异常变量的生命周期（重点难点）

1.产生三个对象

```
class Maker
{
public:
	Maker()
	{
		cout << "Maker的构造" << endl;
	}
	Maker(const Maker &m)
	{
		cout << "Maker的拷贝构造" << endl;
	}
	~Maker()
	{
		cout << "Maker的析构" << endl;
	}
};
//产生三个对象
void func1()
{
	Maker m;//第一个对象，在异常接收前被释放
	throw m;//第二个对象，是第一个对象拷贝过来的
}

void test01()
{
	try
	{
		func1();
	}
	catch (Maker m1)//第三个对象，是第二个对象拷贝过来的
	{
		cout << "接收一个Maker类型的异常" << endl;
		//第二个和第三个对象在catch结束时释放

	}
}
```

2.产生二个对象

```
void func2()
{
	//第一个对象
	throw Maker();//匿名对象
}

void test02()
{
	try
	{
		func2();
	}
	catch (Maker m1)//第二个对象
	{
		cout << "接收一个Maker类型的异常" << endl;
		//第一个和第二个对象在catch结束时释放

	}
}
```

3.产生一个对象（常用这个）

```
void func3()
{
	throw Maker();//匿名对象

}

void test03()
{
	try
	{
		func3();
	}
	catch (Maker &m1)
	{
		cout << "接收一个Maker类型的异常" << endl;


	}

}
```

4.注意：

```
void func4()
{
	//编译器不允许对栈中的匿名对象取地址操作
	//throw Maker();//匿名对象
	//编译器允许对堆区中的匿名对象取地址操作
	throw new Maker();
}

void test04()
{
	try
	{
		func4();
	}
	catch (Maker *m1)
	{
		cout << "接收一个Maker类型的异常" << endl;

		delete m1;
	}
}
```



## 11.异常的多态（重点）

```
//异常的基类
class Father
{
public:
	virtual void printM()
	{

	}
};
//1.有继承
class SonNULL :public Father
{
public:
	virtual void printM()//2.重写父类的虚函数
	{
		cout << "空指针异常" << endl;
	}
};

class SonOut :public Father
{
public:
	virtual void printM()
	{
		cout << "越位溢出" << endl;
	}
};

void func(int a,int b)
{
	if (a == 0)
	{
		throw SonNULL();
	}
	
	if (b == 0)
	{
		throw SonOut();
	}
	
}

void test()
{
	int a = 0;
	int b = 10;
	try
	{
		func(a,b);
	}
	catch (Father &f)//3.父类引用指向子类对象
	{
		f.printM();
	}
}
```



## 12.系统提供的标准异常（重点）

1.系统的标准异常类

```
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<stdexcept>//2013Vs可以不用
#include<string>

class Maker
{
public:
	Maker(int age)
	{
		if (age<0 || age>150)
		{
			throw out_of_range("年龄不在范围内");
			
		}
		else
		{
			this->age = age;
		}
	}
public:
	int age;
};

void test()
{
	try
	{
		Maker m(200);
	}
	catch (out_of_range &ex)
	{
		cout << ex.what() << endl;
	}

}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}


```

2.自己编写的异常类

```
class MyOut_of :public exception
{
public:
	MyOut_of(const char *errorinfo)
	{
		//const char*转换string
		this->m_Info = string(errorinfo);
	}
	MyOut_of(const string errorinfo)
	{
		this->m_Info = errorinfo;
	}
	const char *  what() const
	{
		//把string转换const char*
		return this->m_Info.c_str();
	}
public:
	string m_Info;
};

class Maker
{
public:
	Maker(int age)
	{
		if (age<0 || age>150)
		{
			
			throw MyOut_of("自己的异常类，年龄不在范围内");
		}
		else
		{
			this->age = age;
		}
	}
public:
	int age;
};

void test()
{
	try
	{
		Maker m(200);
	}
	catch (MyOut_of &ex)
	{
		cout << ex.what() << endl;
	}
}
```



## 13.系统标准的输入流（重点）

1.流的概念和流类库的结构（了解）

标准IO:对系统的标准输入输出设备进行读写

文件IO：对磁盘进行输入输出读写

串IO:对内存进行读写

2.成员函数

cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串
cin.getline()//取一行，换行符丢弃
cin.ignore()//忽略
cin.peek()//偷窥
cin.putback()//放回

3.案例

```
//判断用户输入的是字符串还是数字
void test06()
{
	cout << "请输入一个字符串或数字" << endl;

	char c=cin.peek();

	if (c >= '0'&&c <= '9')
	{
		int num;
		cin >> num;
		cout << "输入的数字是:" << num << endl;
	}
	else
	{
		char buf[1024] = { 0 };
		cin >> buf;
		cout << "输入的字符串是:" <<buf << endl;
	}
}

//输入一个0到10的数字，直到输入正确为止
void test07()
{
	int num;

	while (1)
	{
		cin >> num;
		if (num >= 0 && num <= 10)
		{
			cout << "输入正确" << endl;
			break;
		}
		cout << "重新输入：" << endl;
		//重置标志位
		cin.clear();
		//清空缓冲区
		//cin.sync();
		//2015
		char buf[1024] = { 0 };
		cin.getline(buf, 1024);

		//打印标志位
		cout << cin.fail() << endl;

	}
}

```



## 14.系统标准的输出流（重点）

1.通过成员函数格式化输出

```
//通过流成员函数实现格式化的输出
void test03()
{
	int num = 99;
	cout.width(20);//设置宽度
	cout.fill('*');//填充
	cout.setf(ios::left);//让数据在左边
	cout.unsetf(ios::dec);//卸载十进制
	cout.setf(ios::hex);//安装十六进制
	cout.setf(ios::showbase);//显示基数
	cout.unsetf(ios::hex);//卸载十六进制
	cout.setf(ios::oct);//安装八进制
	cout << num << endl;
}
```

2.通过控制符格式化输出

```
//通过控制符来格式化输出，引入头文件iomanip
void test04()
{
	int num = 99;
	cout << setw(20);//设置宽度
	cout << setfill('~');//填充
	cout << setiosflags(ios::showbase);//显示基数
	cout << setiosflags(ios::left);//让数据在左边
	cout << hex;//六十进制
	cout << oct;//八进制
	cout << dec;//十进制
	cout << num << endl;
}
```

3.打印浮点数后面的小数点

```
void test05()
{
	double d = 20.22;
	cout << setiosflags(ios::fixed);//设置显示浮点数
	cout << setprecision(10);//显示小数点后10位
	cout << d << endl;
}
```



## 15.文件读写操作（重点）

1.回顾C语言的文件读写

```
1.按照字符读写文件fgetc、fputc
int fputc(int ch, FILE * stream);//写
int fgetc(FILE * stream);//读

2.按照行读写文件fgets、fputs
int fputs(const char * str, FILE * stream);//写
char * fgets(char * str, int size, FILE * stream);//读

3.按照格式化文件fprintf、fscanf
int fprintf(FILE * stream, const char * format, ...);//写
int fscanf(FILE * stream, const char * format, ...);//读

4.按照块读写文件fread、fwrite
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);//写
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);//读
```

2.C++的文件读写

```
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//1.引入头文件
#include<fstream>
//把程序中的信息输出到缓冲区，然后写到文件（写文件）
void test01()
{
	//2.定义流对象
	ofstream ofs;
	//3.打开文件,以写的方式打开，如果没有文件，就创建
	ofs.open("test.txt", ios::out | ios::trunc);
	//4.判断是否打开成功
	if (!ofs.is_open())
	{
		cout << "打开失败" << endl;
	}

	//5.写信息
	ofs << "姓名:悟空" << endl;
	ofs << "年龄:18" << endl;
	ofs << "身高:180cm" << endl;

	//6.关闭文件
	ofs.close();//关闭文件，并刷新缓冲区

}

//把磁盘信息输入到缓冲区，然后读到程序中（读文件）
void test02()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (ifs.is_open() == false)
	{
		cout << "打开失败" << endl;
	}
	//第一种方式读取文件
	//一行一行读取
	/*char buf[1024] = { 0 };
	while (ifs>>buf)
	{
		cout << buf << endl;
	}*/
	//第二种方式读文件
	//char buf[1024] = { 0 };
	//while (!ifs.eof())//判断是否读到文件尾部
	//{
	//	ifs.getline(buf, sizeof(buf));
	//	cout << buf << endl;

	//}
	//第三种方式读取文件
	//单个字符读取
	char c;
	while ((c=ifs.get())!=EOF)
	{
		cout << c;
	}

	//关闭文件
	ifs.close();
}
int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}


```



## 16.二进制文件读写（重点难点）

1.二进制读写

```
class Maker
{
public:
	Maker(){}
	Maker(const char*name,int age)
	{
		this->age = age;
		strcpy(this->name, name);
	}
public:
	char name[64];
	int age;
};

//写文件
void test01()
{
	Maker m1("悟空",18);
	Maker m2("贝吉塔", 22);

	ofstream ofs;
	ofs.open("test.txt", ios::out | ios::trunc | ios::binary);
	if (!ofs.is_open())
	{
		cout << "打开失败" << endl;
	}
	//写
	ofs.write((const char *)&m1, sizeof(Maker));
	ofs.write((const char *)&m2, sizeof(Maker));

	ofs.close();
}
//读文件
void test02()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "打开失败" << endl;
	}

	//读
	Maker m1;
	Maker m2;

	ifs.read((char*)&m1, sizeof(Maker));
	ifs.read((char*)&m2, sizeof(Maker));

	cout << "Name:" << m1.name << " Age:" << m1.age << endl;
	cout << "Name:" << m2.name << " Age:" << m2.age << endl;

	ifs.close();
}
```

2.文件读写中类有成员变量是string时的问题

注意：当文件读写时，类中的成员变量不要有string类型

```
class Maker
{
public:
	Maker(){}
	/*Maker(const char*name,int age)
	{
		this->age = age;
		strcpy(this->name, name);
	}*/
	Maker(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
public:
	string name;
	//string类中有一个成员指针char*,该指针指向存储字符串的空间
	//当我们把string类的数据存储到文件中，再读出来时，不能保证指针有效

	//string 开辟的空间如果大于16个字节就在堆区，小于就在栈区
	int age;
};
```

