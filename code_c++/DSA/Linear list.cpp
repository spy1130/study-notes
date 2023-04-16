#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#define ElemType int
#define MAXSIZE 50
using namespace std;

typedef struct SqList
{
    ElemType *elem; // 顺序线性表的表头
    int length;     // 顺序线性表的长度
} SQL;
void Union(SqList &a, SqList &b);
bool InitList(SqList &L)
{
    L.elem = new ElemType[MAXSIZE]; // 在堆区开辟内存
    if (!L.elem)
    {
        cerr << "error" << endl;
        return false;
    }
    L.length = 0; // 设定线性表长度为0
    return 1;
}
bool InsertList(SqList &L, const ElemType &e, const int &i)
{
    // 判断线性表长度是否小于最大长度MAXSIZE
    if (L.length == MAXSIZE)
    {
        cerr << "can not insert!" << endl;
        return false;
    }
    if (i < 0 || i > L.length+1)//+1用来实现合并
    {
        cerr << "wrong insert position!" << endl;
        return false;
    }
    if (L.length > 0)
    {
        // 将位于插入位置之后的元素依次向后挪动一位
        for (int p = L.length - 1; p >= i; --p)
        {
            L.elem[p + 1] = L.elem[p];
        }
    }
    // 插入元素
    L.elem[i] = e;
    // 线性表长度+1
    L.length += 1;
    return true;
    // 算法时间复杂度：O(n)
}
void PrintList(SqList &L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.elem[i] << " ";
    }
    cout << endl;
}
bool EraseList(SqList &L, const int &i)
{
    // 异常判断
    if (i < 0 || i > L.length)
    {
        cerr << "wrong erase position!" << endl;
        return false;
    }
    if (L.length == 0)
    {
        cerr << "List has no length" << endl;
        return false;
    }
    // 将位于删除位置之后的元素依次向前挪动一位
    for (int p = i + 1; p < L.length; ++p)
    {
        L.elem[p - 1] = L.elem[p];
    }
    // 线性表长度-1
    L.length -= 1;
    return true;
    // 算法时间复杂度：O(n)
}
bool GetELem(const SqList &L, const size_t i, ElemType &e)
{
    if (i < 1 || i > MAXSIZE)
    {
        cerr << "out of range" << endl;
        return false;
    }
    e = L.elem[i - 1];
    return true;
}
int LocateList(const SqList &L, const ElemType &e)
{
    for (int i = 0; i < L.length; ++i)
    {
        if (L.elem[i] == e)
        {
            return i + 1; // 查找成功，返回其查找元素的第一个下标值
        }
    }
    return 0; // 未能找到对应元素，返回0
    // 算法时间复杂度：O(n)
}
void CLearList(SqList &L)
{
    L.length = 0;
}
bool IsEmpty(const SqList &L)
{
    return static_cast<bool>(L.length);
}
void DestroyList(SqList &L)
{
    if (L.elem)
    {
        delete[] L.elem;
    }
}

int main()
{
    SQL list1, list2;
    int e;
    InitList(list1);
    InitList(list2);
    srand(time(nullptr)); // 用当前时间作为种子
    for (int i = 0; i < 10; i++)
    {
        int random = (rand() % (100 - 1)) + 1;
        InsertList(list1, random, i);
    }
    for (int i = 0; i < 10; i++)
    {
        int random = (rand() % (100 - 1)) + 1;
        InsertList(list2, random, i);
    }
    GetELem(list1, 1, e);
    int loc = LocateList(list1, e);
    cout << e << " " << loc << endl;
    PrintList(list1);
    PrintList(list2);
    EraseList(list1, 3);
    PrintList(list1);
    Union(list1, list2);
    PrintList(list1);
    CLearList(list1);
    IsEmpty(list1);
    DestroyList(list1);
    system("pause");
    return EXIT_SUCCESS;
}
void Union(SqList &a, SqList &b)
{
    int La_len = a.length;
    int Lb_len = b.length;
    int e;
    for (int i = 1; i <= Lb_len; i++)
    {
        GetELem(b, i, e);
        if (!LocateList(a, e))
            InsertList(a, e,++La_len);
    }
}