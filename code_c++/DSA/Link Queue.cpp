#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAXSIZE 100
using namespace std;
struct Qnode
{
    int data; // 元素个数
    Qnode *next;
};
struct LinkQueue // 再定义一个抽象数据类型，一次性建立两个Qnode指针
{
    Qnode *front; // 头指针
    Qnode *rear;  // 尾指针
};
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = new Qnode;
    Q.front->data = 0; // 用于保存链队的元素个数
    Q.rear->next = nullptr;
}
void InsertQueue(LinkQueue &Q, const int &e)
{
    // 把元素插在最后面
    Qnode *temp = new Qnode;
    temp->data = e;
    temp->next = nullptr;
    Q.rear->next = temp;
    Q.rear = temp;
    ++Q.front->data; // 元素个数加1
}
void CreatQueue(LinkQueue &Q, const int n)
{
    cout << "input msg" << endl;
    int input;
    for (int i = 0; i < n; ++i)
    {
        cin >> input;
        InsertQueue(Q, input);
    }
}
bool GetHead(LinkQueue Q, int &e)
{
    if (Q.front == Q.rear)
        return false;
    e = Q.front->next->data;
    return true;
}
bool EraseQueue(LinkQueue &Q)
{
    if (Q.front->next == nullptr)
    {
        cerr << "empty Queue" << endl;
        return false;
    }
    Qnode *p = Q.front->next;
    Q.front->next = p->next;
    if (Q.rear == p)
        Q.rear = Q.front;
    delete p;
    --Q.front->data; // 元素个数-1
    return true;
}
int main()
{

    system("pause");
    return EXIT_SUCCESS;
}