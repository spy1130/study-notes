#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>//算法头文件
#include<ctime>
using namespace std;
//目的：5个学生，10个评委，10个评委的分数去掉最高和最低分，取平均分就是学生的分数
//抽象学生
class Student
{
public:
	string name;
	int mScore;
};


//1.创建学生
void CreateStudent(vector<Student> &vstu)
{
	string setName = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		//创建学生
		Student stu;
		stu.name = "学生";
		stu.name += setName[i];
		stu.mScore = 0;
		vstu.push_back(stu);//把学生放入容器
	}
}
//2.评委给学生打分
void SetScore(vector<Student> &vstu)
{
	srand((unsigned int)time(NULL));
	//遍历学生
	for (vector<Student>::iterator it = vstu.begin(); it != vstu.end(); ++it)
	{
		//保存分数
		deque<int> dScore;
		//评委给学生打分
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 70 + 30;
			dScore.push_back(score);
		}
		//排序
		sort(dScore.begin(),dScore.end());
		//去掉最高分和最低分
		dScore.pop_back();
		dScore.pop_front();

		//求总分
		int tota = 0;
		for (deque<int>::iterator sit = dScore.begin(); sit != dScore.end(); ++sit)
		{
			tota += (*sit);
		}

		//求平均分
		int agescore = tota / dScore.size();

		//平均分存储到对象中
		it->mScore = agescore;

	}
}

bool mycomapre(Student &s1, Student &s2)
{
	return s1.mScore > s2.mScore;
}
//3.排名并打印
void ShowStudentScore(vector<Student> &vstu)
{
	
	sort(vstu.begin(), vstu.end(), mycomapre);

	for (vector<Student>::iterator it = vstu.begin(); it != vstu.end(); ++it)
	{
		cout << "Name:" << it->name << " Score:" << it->mScore << endl;
	}


}
void test()
{
	//存储学生的容器
	vector<Student> vstu;

	//1.创建学生
	CreateStudent(vstu);
	//2.评委给学生打分
	SetScore(vstu);
	//3.排名并打印
	ShowStudentScore(vstu);

}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}

