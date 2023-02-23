#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Father1
{
public:
	int bmw;
};

class Father2
{
public:
	//int bmw;
};

class Son :public Father1, public Father2
{

};

void test()
{
	Son s;
	s.bmw;
	//s.bmw;有二义性问题，
	
}
int main()
{

	system("pause");
	return EXIT_SUCCESS;
}

