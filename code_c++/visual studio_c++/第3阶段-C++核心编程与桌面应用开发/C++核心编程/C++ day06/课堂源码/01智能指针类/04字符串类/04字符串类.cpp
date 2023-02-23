#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"MyString.h"

void test()
{
	MyString s1(10, 'a');
	cout << s1 << endl;

	MyString s2(3, 'b');
	cout << s2 << endl;

	MyString s3 = s1 + s2;
	cout << s3 << endl;
	MyString s4 = s3 + "hello";
	cout << s4 << endl;


	for (int i = 0; i < s4.Size(); i++)
	{
		cout << s4[i] << " ";
	}

	cout << endl;

	MyString s5(5, 'c');
	s4 += s5;
	cout << s4 << endl;

	s4 += "world";
	cout << s4 << endl;


	cin >> s4;
	cout << s4 << endl;
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

