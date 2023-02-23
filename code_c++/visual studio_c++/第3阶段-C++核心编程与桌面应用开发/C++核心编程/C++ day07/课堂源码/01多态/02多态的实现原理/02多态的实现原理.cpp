#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "Anima speak()" << endl;
	}
	
};
class Dog :public Animal
{
public:
	virtual void speak()
	{
		cout << "Dog speak()" << endl;
	}
};

void test()
{
	cout << sizeof(Animal) << endl;

	Animal *animal = new Dog;
	animal->speak();
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

