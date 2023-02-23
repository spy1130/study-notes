#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main(){

	typedef char * PCHAR;
	PCHAR p1, p2;

	printf("p1 的类型为 %s \n", typeid(p1).name());

	printf("p2 的类型为 %s \n", typeid(p2).name());

	system("pause");
	return EXIT_SUCCESS;
}