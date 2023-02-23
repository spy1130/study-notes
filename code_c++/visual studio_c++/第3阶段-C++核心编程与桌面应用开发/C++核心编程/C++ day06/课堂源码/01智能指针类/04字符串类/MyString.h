#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class MyString
{
	friend ostream &operator<<(ostream &out, MyString &str); // 左移
	friend istream &operator>>(istream &in, MyString &str);	 // 右移
public:
	MyString();								  // 无参构造
	MyString(int n, char c);				  // 用户可以设定初始化字符串，n个c组成的字符串
	MyString(const MyString &str);			  // 拷贝构造
	MyString &operator=(const MyString &str); // 赋值重载
	~MyString();							  // 析构

	MyString operator+(const MyString &str);
	MyString operator+(const char *s); //+“hello”

	MyString &operator+=(const MyString &str);
	MyString &operator+=(const char *s);

	int Size(); // 多少个字符

	char &operator[](int index);

private:
	char *pM; // 指向堆区空间
	int mSize;
	/*
	MyString s1;
	MyString s2;
	MyString s3=s1+s2;
	MyString s4=s3+"hello";

	s4+=s3;
	s4+="hello";

	cout<<s4<<endl;
	cin>>s4;


	*/
};
