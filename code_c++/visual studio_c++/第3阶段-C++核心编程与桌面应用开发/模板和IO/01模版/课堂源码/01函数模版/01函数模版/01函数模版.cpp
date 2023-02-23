#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

void mySwapint(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void mySwapdouble(double &a, double &b)
{
	double tmp = a;
	a = b;
	b = tmp;
}

void test01()
{
	int a = 10;
	int b = 20;
	//mySwap(a, b);
}
//T代表泛型的数据类型，不是只能写T，
template<class T>//让编译器看到这句话后面紧跟着的函数里有T不要报错
void mySwap(T &a,T &b)//第一次编译
{
	T tmp = a;
	a= b;
	b = tmp;
}
//可以这样定义函数模版
template<typename T>
void func2(T a,T b)
{

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
	char c = 'c';
	//mySwap(a, c);err,数据类型要一致

	//2.显示的指定类型
	mySwap<int>(a, b);//<>用参数列表告诉编译器我只传int类
	//mySwap<double>(a, b);//注意：指定类型，传入时不能不一致

	mySwap<>(a,b);
	//mySwap2<>();//调用时，必须让编译器知道泛型T具体是什么类型

	/*
	template<class T>//让编译器看到这句话后面紧跟着的函数里有T不要报错
	void mySwap(T &a,T &b)//第一次编译
	{
		T tmp = a;
		a= b;
		b = tmp;
	}
	*/
	int a1 = 10;
	double b1 = 20;
	//mySwap<int>(a1, b1);err
}

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
	cout << func<int>(a,b) << endl;
}

//排序
template<class T>//让编译器看到这句话后面紧跟着的函数里有T不要报错
void mySwap3(T &a, T &b)//第一次编译
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<class T>
void mySort(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}

		if (max != i)
		{
			//进行交换
			mySwap3(arr[max], arr[i]);
		}
	}
}

template<class T>
void myPrint(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test04()
{
	char arrchar[] = "hello world";
	int len = sizeof(arrchar) / sizeof(char);
	mySort(arrchar, len);
	myPrint(arrchar, len);

	int arrInt[] = { 3, 8, 4, 2, 1, 9 };
	len = sizeof(arrInt) / sizeof(int);
	mySort(arrInt, len);
	myPrint(arrInt, len);
}
int main()
{
	test04();
	system("pause");
	return EXIT_SUCCESS;
}

