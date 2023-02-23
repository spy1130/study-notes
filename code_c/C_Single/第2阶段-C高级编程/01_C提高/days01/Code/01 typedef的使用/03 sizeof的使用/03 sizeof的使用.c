#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、sizeof本质， 是不是一个函数？？？ 不是函数，只是一个操作符，类似+-*/
void test01()
{
	//对于数据类型 ，sizeof必须用()去使用，但是对于变量，可以不加()
	printf("size of int = %d\n", sizeof(int));

	double d = 3.14;

	printf("size of d = %d\n", sizeof d );

}

//2、sizeof的返回值类型是什么 ？  unsigned int 无符号整型
void test02()
{
	//unsigned int a = 10;
	//if (a - 20 > 0) //当unsigned int和int类型数据做运算，编译器会将数据类型都转为unsigned int
	//{
	//	printf("大于 0 \n");
	//}
	//else
	//{
	//	printf("小于 0 \n");
	//}


	if ( sizeof(int) - 5 > 0 )
	{
		printf("大于 0 %u \n", sizeof(int)-5);
	}
	else
	{
		printf("小于 0 \n");
	}

}


//3、sizeof可以统计数组长度
//当数组名作为函数参数时候，会退化为指针，指向数组中第一个元素
void calculateArray( int arr[] )
{
	printf("arr的数组长度： %d\n", sizeof(arr));
}

void test03()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	//printf("arr的数组长度： %d\n", sizeof(arr));

	calculateArray(arr);
}

int main(){
	//test01();
	//test02();
	test03();


	system("pause");
	return EXIT_SUCCESS;
}