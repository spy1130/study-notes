#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

void test()
{
	string::iterator it;

	it++;
	it--;
	it + 2;
}

/*
构造函数
string();//创建一个空的字符串 例如: string str;
string(const string& str);//使用一个string对象初始化另一个string对象
string(const char* s);//使用字符串s初始化
string(int n, char c);//使用n个字符c初始化

*/
void test01()
{
	string s1;
	string s2(10, 'a');
	string s3(s2);
	string s4("hello");

}
/*
基本赋值操作
string&operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string&operator=(const string&s);//把字符串s赋给当前的字符串
string&operator=(char c);//字符赋值给当前的字符串
string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string&s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string&s, int start, int n);//将s从start开始n个字符赋值给字符串,如s=hello,那么n=3,start=1，那么是hel中从e开始赋值3-1个字符

*/

void test02()
{
	string s1;
	s1 = "hello";
	cout << s1 << endl;

	string s2;
	//s2.assign(s1);
	s2.assign("world");
	cout << s2 << endl;
}

/*
存取字符操作
char&operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符

*/

void test03()
{
	string s = "hello world";
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < s.size(); i++)
	{
		cout << s.at(i) << " ";
	}
	cout << endl;

	//[]和at的区别：[]访问元素时，越界不抛异常，直接挂，at越界，会抛异常
	try
	{
		//cout << s[100] << endl;
		cout << s.at(100) << endl;
	}
	catch (out_of_range &ex)
	{
		cout << ex.what() << endl;
		cout << "at越界" << endl;
	}
}
/*
拼接操作
string&operator+=(const string& str);//重载+=操作符
string&operator+=(const char* str);//重载+=操作符
string&operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string&s);//同operator+=()
string& append(const string&s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c

*/
void test04()
{
	string s1 = "aaa";
	s1 += "bbb";
	s1 += 'c';
	cout << s1 << endl;

	s1.append("dddddd", 3);
	cout << s1 << endl;
}

/*
查找和替换
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(constchar* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(constchar* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(constchar c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(conststring& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(constchar* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(constchar* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(constchar c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s

*/
void test05()
{
	string s = "abcdefgd";
	cout << s.find('d') << endl;//3

	cout << s.rfind('d') <<  endl;//7

	cout << s.find("kkk") << endl;

	s.replace(2, 4, "AAA");
	cout << s << endl;
}
/*
比较操作

compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。

int compare(const string&s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较

*/
void test06()
{
	string s1 = "hello";
	string s2 = "hello";
	const char* str = "world";

	if (s1.compare(s2)==0)
	{
		cout << "s1==s2" << endl;
	}
	if (s2.compare(str) == 0)
	{
		cout << "s2==str" << endl;
	}
	else
	{
		cout << "s2!=str" << endl;
	}
}
/*
子串
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串

*/
void test07()
{
	string email = "hello world@itcast.com";
	int pos = email.find('@');
	string username = email.substr(0, pos);
	cout << username << endl;

	string prex = email.substr(pos + 1);
	cout << prex << endl;

}
/*
插入和删除操作
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符

*/
void test08()
{
	string s = "aaaa";
	s.insert(3, "AAA");
	cout << s << endl;

	s.insert(3, 5, 'M');
	cout << s << endl;

	s.erase(2, 3);
	cout << s << endl;
}

/*
string和c-style字符串转换
*/
void test09()
{
	const char *str = "hello";
	string s=string(str);
	cout << s << endl;

	const char *str2=s.c_str();
	cout << str2 << endl;
}

//字符串内存重新分配，[]和at获取的字符引用，可以能会出错
void test10()
{
	string s = "abcde";
	char &a = s[2];
	char &b = s[3];

	a = '1';
	b = '2';
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << s << endl;
	cout << "字符串的原空间地址:" << (int*)s.c_str() << endl;

	s = "fdasfdasfdsafdasherewrkewhsaferew";
	cout << "字符串的空间地址:" << (int*)s.c_str() << endl;

	//原空间被释放，但是a还是被释放的s[2]空间的别名，如果操作非法的空间，会出错
	//a = '3';


}

//用迭代器遍历字符串
void test11()
{
	string s = "hello";
	for (string::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	//反向遍历
	for (string::reverse_iterator it = s.rbegin(); it != s.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	test11();
	system("pause");
	return EXIT_SUCCESS;
}

