#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Animal
{
public:
	virtual void speak()
	{
		cout << "Animal speak()" << endl;
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
	Animal &animal = Dog();//Õ»Çø
	animal.speak();

	Animal* dog = new Dog();
	Animal* &an = dog;
	an->speak();
	delete dog;
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

