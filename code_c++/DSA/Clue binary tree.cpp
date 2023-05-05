#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// 给这个线索二叉树加一个头结点

typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lchild, *rchild;
    int LTag, RTag;
} BiThrNode, *BiThrTree;
BiThrTree pre; // 全局变量，始终指向刚刚访问过的节点
// 先序创建二叉树
void CreateBiThrTree(BiThrTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new BiThrNode;
        T->data = ch;
        T->LTag = 0;
        T->RTag = 0;
        CreateBiThrTree(T->lchild);
        CreateBiThrTree(T->rchild);
    }
}
// 先序遍历线索化
void PreThreading(BiThrTree T)
{
    if (T)
    {
        if (!T->lchild) // 没有左孩子
        {
            T->LTag = 1; // 前驱线索
            T->lchild = pre;
        }
        if (!pre->rchild) // 前一个节点没有右孩子
        {
            pre->RTag = 1; // 后继线索
            pre->rchild = T;
        }
        pre = T; // 保持pre指向T的前驱
        PreThreading(T->lchild);
        PreThreading(T->rchild);
    }
}
// 中序遍历线索化
void InThreading(BiThrTree T)
{
    if (T)
    {
        InThreading(T->lchild); // 递归左子树线索化
        if (!T->lchild)         // 没有左孩子
        {
            T->LTag = 1; // 前驱线索
            T->lchild = pre;
        }
        if (!pre->rchild) // 前一个节点没有右孩子
        {
            pre->RTag = 1; // 后继线索
            pre->rchild = T;
        }
        pre = T; // 保持pre指向T的前驱
        InThreading(T->rchild);
    }
}
// 后序遍历线索化
void PostThreading(BiThrTree T)
{
    if (T)
    {
        PostThreading(T->lchild);
        PostThreading(T->rchild);
        if (!T->lchild) // 没有左孩子
        {
            T->LTag = 1; // 前驱线索
            T->lchild = pre;
        }
        if (!pre->rchild) // 前一个节点没有右孩子
        {
            pre->RTag = 1; // 后继线索
            pre->rchild = T;
        }
        pre = T; // 保持pre指向T的前驱
    }
}
// 中序遍历二叉树
void InOrder(BiThrTree T)
{
    BiThrTree p;
    p = T->lchild; // p指向根节点
    while (p != T)
    {
        while (p->LTag == 0)
            p = p->lchild;
        cout << p->data;
        while (p->RTag == 1 && p->rchild != T)
        {
            p = p->rchild;
            cout << p->data;
        }
        p = p->rchild;
    }
}
int main()
{
    BiThrTree T;
    CreateBiThrTree(T);
    pre = T;
    // PreThreading(T);
    // PostThreading(T);
    InThreading(T);
    InOrder(T);
    system("pause");
    return 0;
}
