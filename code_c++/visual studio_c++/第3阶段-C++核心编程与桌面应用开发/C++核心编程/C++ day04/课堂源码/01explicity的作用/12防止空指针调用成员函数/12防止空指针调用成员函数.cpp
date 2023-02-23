#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Maker
{
public:
	Maker()
	{
		a = 20;
	}

	void printMaker()
	{
		if (this == NULL)
		{
			cout << "this==NULL" << endl;
			return;
		}
		
		cout << this->a << endl;
	}
private:
	int a;
};

void test()
{
	Maker *m = NULL;
	m->printMaker();
}
int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}

