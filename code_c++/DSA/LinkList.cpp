#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

string rand_str(const int len);
typedef struct Data
{
    string name;
    int age;
} Data;
typedef struct Lnode
{
    Data note;   // 结点的数据域
    Lnode *next; // 结点的指针域
} Lnode, *LinkList;
bool InitList(LinkList &L) // 插入题外话：LinkList &L等价于 Lnode *&L，Lnode *&L是一个指向指针的引用
{
    L = new Lnode;     // 堆区开辟一个头结点，结点的数据类型为Lnode
    L->next = nullptr; // 空表，也就是说头结点的指针指向为空
    return true;
}
void CreatListHead(LinkList &L, const int n)
{
    for (int i = 0; i < n; ++i)
    {
        Lnode *p = new Lnode;
        p->note.name = rand_str(5);
        // cin >> "input name:">>p->note.name;
        p->note.age = rand() % 100;
        // cin >> "input age:">>p->note.age;
        p->next = L->next;
        L->next = p;
    }
}
void CreatListTail(LinkList &L, const int n)
{
    Lnode *r = L;
    for (int i = 0; i < n; ++i)
    {
        Lnode *p = new Lnode;
        p->note.name = rand_str(5);
        // cin >> "input name:">>p->note.name;
        p->note.age = rand() % 100;
        // cin >> "input age:">>p->note.age;
        p->next = r->next;
        r->next = p;
        r = r->next;
    }
}
void printlist(const LinkList &L, const int len)
{
    Lnode *p = L->next;
    for (int i = 1; i < len; i++)
    {
        cout << p->note.name << ':'<<p->note.age<<" ";
        p=p->next;
    }
    cout<<endl;
}
int GetLength(const LinkList &L)
{
    Lnode *p;
    int i = 0;
    p = L->next;
    while (p != nullptr)
    {
        i++;
        p = p->next;
    }
    return i;
}
bool GetElem(const LinkList &L, const int &i, Data &e)
{
    if (i < 0)
    {
        cerr << "out of range" << endl;
        return false;
    }
    Lnode *p = L->next;
    for (int j = 1; j < i; ++j)
    {
        p = p->next;
        if (!p)
        {
            cerr << "out of range" << endl;
            return false; // 如果此时p为空，意味着已经到达链表尾端，停止循环
        }
    }
    e = p->note;
    return true;
}
int LocateElem(LinkList &L, Data &e)
{
    Lnode *p = L->next;
    int cnt = 1;
    while (p)
    {
        if (!(p->note.name.compare(e.name)))
        {
            return cnt;
        }
        ++cnt;
        p = p->next;
    }
    cerr << "not found" << endl;
    return cnt;
}
bool InsertList(LinkList &L, const int &i, const Data &e)
{
    Lnode *p = L;
    int j = 0;                     // 这里可以判断在第一个节点前插入时的情况
    for (j; j < (i - 1 && p); j++) // 范围1到n+1
    {                              // p！=NULL
        p = p->next;
    }
    if (!p || j > i - 1)
        return false;
    LinkList s = new Lnode;
    s->note = e;
    s->next = p->next; // s指向p的下一个
    p->next = s;       // p指向s
    return true;
}
bool deletelist(LinkList &L, const int &i, Data &e)
{
    Lnode *p = L, *s;
    int j = 0;
    for (j; j < i - 1 && p->next; j++) // 范围1到n
    {
        p = p->next;
    }
    if (!(p->next) || j > i - 1)
        return false;
    s = p->next;
    p->next = p->next->next;
    e = s->note; // 保存删除的节点
    delete s;
    return true;
}
bool clearlist(LinkList &L)
{
    Lnode *p, *q;
    p = L->next;
    while (p != nullptr)
    {
        q = p->next;
        delete p;
        p = q;
    }
    L->next = nullptr;
    return true;
}
bool IsEmpty(const LinkList &L)
{
    if (L->next) // 非空
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool DestroyList(LinkList &L)
{
    // 判断链表是否为空
    if (IsEmpty(L))
    {
        cerr << "empty List!" << endl;
        return false;
    }
    while (L) // 链表还未到达尾端
    {
        auto temp = L->next; // 将头指针指向下一个结点
        delete L;
        L = temp;
    }
    return true;
}
int main()
{
    srand(unsigned(time(nullptr)));
    LinkList L;
    Data S, e;
    S.name = "spric";
    S.age = 18;
    InitList(L);
    CreatListTail(L, 5);
    CreatListHead(L, 5);
    InsertList(L, 3, S);
    int length = GetLength(L);
    printlist(L, length);
    GetElem(L, 5, e);
    cout << e.name <<":"<< e.age << endl;
    int locate_nember = LocateElem(L, S);
    cout << locate_nember << endl;
    deletelist(L, 2, e);
    printlist(L, length - 1);
    cout << e.name << ":"<< e.age << endl;
    clearlist(L);
    IsEmpty(L);
    DestroyList(L);

    system("pause");
    return EXIT_SUCCESS;
}
string rand_str(const int len) /*参数为字符串的长度*/
{
    /*初始化*/
    string str; /*声明用来保存随机字符串的str*/
    char c;     /*声明字符c，用来保存随机生成的字符*/
    int idx;    /*用来循环的变量*/
    /*循环向字符串中添加随机生成的字符*/
    for (idx = 0; idx < len; idx++)
    {
        c = 'a' + rand() % 26;
        str.push_back(c); /*push_back()是string类尾插函数。这里插入随机字符c*/
    }
    return str; /*返回生成的随机字符串*/
}
