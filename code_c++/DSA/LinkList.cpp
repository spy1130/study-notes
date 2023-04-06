#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;

typedef struct Data
{
    char *name;
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
    if(i < 0)
    {
        cerr << "out of range" << endl;
        return false;
    }
    Lnode *p = L->next;
    for (int j = 1; j < i + 1; ++j)
    {
        p = p->next;
        if(!p)
        {
            cerr << "out of range" << endl;
            return false;//如果此时p为空，意味着已经到达链表尾端，停止循环
        }
    }
    e = p->note;
    return true;
}
size_t LocateElem(LinkList &L, Data &e)
{
    Lnode *p = L->next;
    size_t cnt = 1;
    while (p)
    {
        if (!strcmp(p->note.name,e.name))
        {
            return cnt;
        }
        ++cnt;
        p = p->next;
    }
    cerr << "not found" << endl;
    return 0;
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

    system("pause");
    return EXIT_SUCCESS;
}