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
typedef struct DuLnode
{
    Data note;             // 结点的数据域
    DuLnode *prior, *next; // 结点的指针域
} DuLnode, *LinkList;
bool InitList(LinkList &L) // 插入题外话：LinkList &L等价于 DuLnode *&L，DuLnode *&L是一个指向指针的引用
{
    L = new DuLnode;    // 堆区开辟一个头结点，结点的数据类型为DuLnode
    L->prior = nullptr; // 双向链表
    L->next = nullptr;  // 空表，也就是说头结点的指针指向为空
    return true;
}
void CreatListHead(LinkList &L, const int n)
{
    for (int i = 0; i < n; ++i)
    {
        DuLnode *p = new DuLnode;
        if (p == NULL)
        {
            cout << "Memory allocation failed." << endl;
            return;
        }
        p->note.name = rand_str(5);
        // cin >> "input name:">>p->note.name;
        p->note.age = rand() % 100;
        // cin >> "input age:">>p->note.age;
        p->prior = L;
        if (L->next == NULL)
        { // the list is empty
            p->next = NULL;
        }
        else
        { // the list is not empty
            p->next = L->next;
            L->next->prior = p;
        }
        L->next = p;
    }
}
void CreatListTail(LinkList &L, const int n)
{
    DuLnode *r = L; // 尾节点，
    for (int i = 0; i < n; ++i)
    {
        DuLnode *p = new DuLnode;

        if (p == NULL)
            return; // 检查是否分配成功
        p->note.name = rand_str(5);
        // cin >> "input name:">>p->note.name;
        p->note.age = rand() % 100;
        // cin >> "input age:">>p->note.age;
        p->prior = r;
        p->next = r->next; // r->next如果不是循环链表则一直为空
        r->next = p;
        r = p; // 把r移动到末尾
    }
}
void printlist(const LinkList &L, const int len)
{
    DuLnode *p = L->next;
    for (int i = 1; i <= len; i++)
    {
        cout << p->note.name << ':' << p->note.age << " ";
        p = p->next;
    }
    cout << endl;
}
int GetLength(const LinkList &L)
{
    DuLnode *p;
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
    DuLnode *p = L->next;
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
    DuLnode *p = L->next;
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
bool InsertList(LinkList &L, const int i, const Data &e)
{
    // 移动指针到i处
    DuLnode *p = L->next;
    int j = 1;
    while ((p->next) && (j < i))
    {
        ++j;
        p = p->next;
    }
    if (j < i || j < 1) // 如果i在链表范围内，上面的while循环的终止条件就是j<i
    {
        cerr << "out of range" << endl;
        return false;
    }
    // 在堆区创建要插入的结点
    DuLnode *s = new DuLnode;
    if (s == NULL) // 检查内存分配是否成功
    {
        cout << "Memory allocation failed." << endl;
        return false;
    }
    s->note = e;
    // 重新建立链接关系
    if (i == 1) // 如果插入位置为第一个节点
    {
        s->prior = L;  // s的前趋为头节点
        s->next = p;   // s的后继为原来的第一个节点
        if (p != NULL) // 如果链表不为空
        {
            p->prior = s; // 原来的第一个节点的前趋为s
        }
        L->next = s; // 头节点的后继为s
    }
    else // 如果插入位置不是第一个节点
    {
        s->prior = p->prior; // s的前趋等于p的前趋
        p->prior->next = s;  // p的前趋结点的next指向s
        s->next = p;         // s的后继指向p
        p->prior = s;        // p的前趋改为指向s
    }
    // return
    return true;
}
bool deletelist(LinkList &L, const int i, Data &e)
{
    // 移动指针到i处
    DuLnode *p = L->next;
    int j = 1;
    while (p->next && j < i)
    {
        ++j;
        p = p->next;
    }
    if (j < i || j < 1) // 如果i在链表范围内，上面的while循环的终止条件就是j<i
    {
        cerr << "out of range" << endl;
        return false;
    }
    // 改变链接关系
    p->prior->next = p->next; // p的前趋结点的next等于p的后继
    if ((p->next))            // 如果删除的不是最后一个元素
    {
        p->next->prior = p->prior;
    }
    e = p->note; // 保存删除的节点
    // 释放p
    delete p;
    // 结束
    return true;
}
bool clearlist(LinkList &L)
{
    DuLnode *p, *q;
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
    // CreatListTail(L, 9);
    CreatListHead(L, 9);
    InsertList(L, 3, S);
    int length = GetLength(L);
    printlist(L, length);
    GetElem(L, 5, e);
    cout << e.name << ":" << e.age << endl;
    int locate_nember = LocateElem(L, S);
    cout << locate_nember << endl;
    deletelist(L, 2, e);
    printlist(L, length - 1);
    cout << e.name << ":" << e.age << endl;
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
