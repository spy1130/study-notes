#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define ElemType int
#define MAXSIZE 100
using namespace std;
// 循环队列
struct SqQueue
{
    ElemType *elem;
    int front; // 头指针
    int rear;  // 尾指针
};
void InitQueue(SqQueue &Q)
{
    Q.elem = new ElemType[MAXSIZE];
    Q.front = Q.rear = 0;
}
bool IsEmpty(SqQueue &Q)
{
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}
bool IsFull(SqQueue &Q)
{
    auto rear_next = (Q.rear + 1) % MAXSIZE; // 循环判断是否满了F少用了一个元素空间
    if (rear_next == Q.front)
        return true;
    else
        return false;
}
bool InsertQueue(SqQueue &Q, const ElemType &e)
{
    // 如果队尾+1等于队头，表明队已经满了（该队列是少用一个空间的循环队列，满队和空队的判断条件不一致）
    if (IsFull(Q))
    {
        cerr << "full of Queue" << endl;
        return false;
    }
    Q.elem[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE; // 循环核心，把maxsize->0
    return true;
}
void CreatQueue(SqQueue &Q, const int n) // 批量进队
{
    cout << "input msg" << endl;
    ElemType input;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        InsertQueue(Q, input);
    }
}
bool EraseQueue(SqQueue &Q)
{
    // 如果队头等于队尾，表明队里没有元素，不执行该程序
    if (IsEmpty(Q))
    {
        cerr << "no elem to erase" << endl;
        return false;
    }
    // e = Q.elem[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return true;
}
int GetLength(SqQueue &Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE; // 去余是为了防止rear还没开始循环时，计算错误
}
void PrintQueue(SqQueue &Q)
{
    cout << "Queue:" << endl;
    for (auto i = Q.front; i != Q.rear; i = (i + 1) % MAXSIZE)
    {
        cout << Q.elem[i] << endl;
    }
}
ElemType GetHead(const SqQueue Q)
{
    if (Q.front != Q.rear) // 队列不为空
        return Q.elem[Q.front];
}
int main()
{
    SqQueue Q;
    InitQueue(Q);
    CreatQueue(Q, 5);
    PrintQueue(Q);
    EraseQueue(Q);
    PrintQueue(Q);
    cout << "length:" << GetLength(Q) << endl;
    cout << "head:" << GetHead(Q) << endl;
    
    system("pause");
    return EXIT_SUCCESS;
}