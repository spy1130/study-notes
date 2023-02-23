#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Animal
{
public:
	//虚函数
	
	virtual void speak()
	{
		cout << "Animal speak " << endl;
	}
};

class Dog :public Animal
{
public:
	 void speak()
	{
		cout << "Dog speak " << endl;
	}
};

class Dog1 :public Animal
{
public:
	void speak()
	{
		cout << "Dog1 speak " << endl;
	}
};

class Dog2 :public Animal
{
public:
	void speak()
	{
		cout << "增加技能 " << endl;
	}
};

//业务层
void doLogin(Animal *animal)//Animal *animal=dog;
{
	animal->speak();
}
void test01()
{
	Animal an;
	an.speak();//在编译阶段就确定了调用speak这个函数
}
void test02()
{
	Dog *dog = new Dog;
	doLogin(dog);

	Dog1 *dog1 = new Dog1;
	doLogin(dog1);

	Dog2 *dog2 = new Dog2;
	doLogin(dog2);
}

int main()
{
	test02();
	system("pause");
	return EXIT_SUCCESS;
}

