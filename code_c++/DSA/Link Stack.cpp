#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

typedef struct StackNode
{
    int data;
    StackNode *next;
} * LinkStack;
void InitStack(LinkStack &S)
{
    //创建头结点
    S = new StackNode;
    S->next = nullptr;
    S->data = 0; //表示栈的元素个数
}
//王老师的视频中没有设置头结点
//我设置了一个头结点，在头结点的数据域中保存栈的元素个数

void Push(LinkStack &S, const int &e)
{
    //插入元素
    StackNode *temp = new StackNode;
    temp->data = e;
    temp->next = S->next;
    S->next = temp;
    ++(S->data);//元素个数加一
}
void Pop(LinkStack &S, int &e)
{
    //删除元素
    StackNode *p = S->next;
    e = p->data;
    S->next = p->next;
    --(S->data);
    delete p;
}
void CreatStack(LinkStack &S, const int n)
{
    int input;
    for (int i = 0; i < n;++i)
    {
        cin >> input;
        Push(S, input);
    }
}
int StackLength(LinkStack &S)
{
    return S->data;
}
bool IsEmpty(LinkStack &S)
{
    if(!(S->next))
    {
        return true;
    }
    else 
    {
        return false;
    }
}
bool ClearStack(LinkStack &S)
{
    if(!(S->next))
    {
        cerr << "empty Stack" << endl;
        return false;
    }
    StackNode *q, *p = S->next;
    while(p)
    {
        q = p;
        p = p->next;
        delete q;
    }
    S->data = 0;
    S->next = nullptr;
    return true;
}
bool DestoryStack(LinkStack &S)
{
    if(S)
    {
        cerr << "error" << endl;
        return false;
    }
    while(S)
    {
        StackNode *temp = S;
        S = S->next;
        delete temp;
    }
    return true;
}
int main(){
    LinkStack S;
    InitStack(S);
    CreatStack(S, 5);
    int e;
    Pop(S, e);
    cout << e << endl;
    cout << StackLength(S) << endl;
    ClearStack(S);
    cout << StackLength(S) << endl;
    DestoryStack(S);

    system("pause");
    return EXIT_SUCCESS;
}