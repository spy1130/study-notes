#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Father
{
public:
	int a;
private:
	int b;
protected:
	int c;
};

class Son :public Father
{
public:
	int s1;
	int s2;
};

int main()
{

	system("pause");
	return EXIT_SUCCESS;
}

