#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#pragma pack(show) //查看对齐模数
//#pragma pack(1) //默认对齐模数为 8  对齐模数可以改为 2的n次方


//对于自定义数据类型  内存对齐规则 如下：
//1、从第一个属性开始  偏移为0 
//2、第二个属性开始，地址要放在  该类型整数倍   与 对齐模数比  取小的值 的整数倍上
//3、所有的属性都计算结束后，整体再做二次对齐，整体需要放在属性中最大类型 与 对齐模数比 取小的值的整数倍上
typedef struct _STUDENT{
	//       对齐模数8      对齐模数1
	int a;   // 0 ~ 3        0  ~ 3
	char b;  // 4 ~ 7        4 
	double c;// 8  ~ 15      5  ~ 12
	float d; // 16 ~ 19      13 ~ 16
}Student;


void test01()
{

	printf("size of =  %d\n", sizeof(Student));

}


//当结构体嵌套结构体时候，只需要看子结构体中最大数据类型就可以了
typedef struct _STUDENT2{
	char a; //  0 ~  7
	Student b;  // 8 ~ 31
	double c;   // 32 ~ 39
}Student2;


void test02()
{
	printf("size of =  %d\n", sizeof(Student2));

}


int main(){

	//test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}