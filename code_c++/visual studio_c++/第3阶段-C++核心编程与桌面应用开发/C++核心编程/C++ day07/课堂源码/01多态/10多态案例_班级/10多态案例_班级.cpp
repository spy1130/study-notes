#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Manito
{
public:
	virtual void show() = 0;
};

class Maker :public Manito
{
public:
	Maker(string name, int age, string sex, string Skill)
	{
		this->name = name;
		this->age = age;
		this->sex = sex;
		this->Skill = Skill;
	}
	virtual void show()
	{
		cout << name << "展现" << Skill << endl;
	}

private:
	string name;
	int age;
	string sex;
	string Skill;

};

class Maker2 :public Manito
{
public:
	Maker2(string name, int age, string sex, string Skill)
	{
		this->name = name;
		this->age = age;
		this->sex = sex;
		this->Skill = Skill;
	}
	virtual void show()
	{
		cout << name << "展现" << Skill << endl;
	}

private:
	string name;
	int age;
	string sex;
	string Skill;

};

//班级
class MyClass
{
public:
	MyClass()
	{
		mCapacity = 50;
		mSize = 0;
	
		this->p = new Manito*[mCapacity];
	}

	//增加人员
	void AddManito(Manito* ma)
	{
		if (mSize == mCapacity)
		{
			return;
		}

		this->p[mSize] = ma;
		mSize++;
	}

	//秀技能
	void StartShow()
	{
		for (int i = 0; i < mSize; i++)
		{
			p[i]->show();
		}
	}


	~MyClass()
	{
		for (int i = 0; i < mSize; i++)
		{
			if (p[i] != NULL)
			{
				delete p[i];
				p[i] = NULL;
			}

		}
		
		delete[] p;
		p = NULL;
	}



private:
	Manito* *p;
	int mCapacity;
	int mSize;
};

void test()
{
	MyClass *my = new MyClass;

	my->AddManito(new Maker("Maker", 18, "男", "跳舞"));
	my->AddManito(new Maker2("Maker2", 16, "女", "唱歌"));
	my->StartShow();

	delete my;

	
}
int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

