#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int a = 10;//常量区，一旦初始化，不能修改

void test()
{
	//a = 200;全局的const不能直接修改
	int *p = (int*)&a;
	//*p = 100;//全局的const不能间接修改
	printf("%d\n", a);

}
int main2()
{
	const int b = 20;//栈区
	//b = 200;局部的const修饰的变量不能直接修改
	int *p = (int*)&b;
	*p = 200;//可以间接修改
	printf("%d\n", b);

	//使用别的文件的全局const修饰的变量需要声明
	extern const int c;
	printf("c=%d\n", c);

	system("pause");
	return EXIT_SUCCESS;
}

