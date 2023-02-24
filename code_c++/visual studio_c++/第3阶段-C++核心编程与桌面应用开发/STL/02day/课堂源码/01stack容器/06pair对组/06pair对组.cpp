#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>


int main()
{
	pair<string, int> myp("aaa", 10);

	cout << myp.first << " " << myp.second << endl;

	pair<int, string> myp2(1,"ЮђПе");
	cout << myp2.first << " " << myp2.second << endl;

	//key -->value



	system("pause");
	return EXIT_SUCCESS;
}

