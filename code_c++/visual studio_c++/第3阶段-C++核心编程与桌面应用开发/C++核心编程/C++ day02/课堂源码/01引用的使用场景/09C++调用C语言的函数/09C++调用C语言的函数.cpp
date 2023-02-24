#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"test.h"

int main()
{
	func();//C++找func函数时，是去找_Z4funcv这个取了别名的函数
	system("pause");
	return EXIT_SUCCESS;
}

