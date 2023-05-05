#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 20
typedef char TElemType;
typedef int Status;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild; // 左右孩子的指针
} BiTNode, *BiTree;
typedef struct
{
    BiTree link;
    int flag;
} stacktype;
// 先序创建二叉树
void CreateBiTree(BiTree &T)
{
    char ch;
    ch = getchar();
    if (ch == '#')
        T = NULL; // #代表空指针
    else
    {
        T = new BiTNode; // 申请节点
        T->data = ch;    // 生成跟节点
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
// 先序输出二叉树
void PreOrder(BiTree T)
{
    if (T)
    {
        printf("%2c", T->data); // 访问根节点，此处为输出根节点的数据值
        PreOrder(T->lchild);    // 先序遍历左子树
        PreOrder(T->rchild);    // 先序遍历右子树
    }
}
// 中序输出二叉树
void InOrder(BiTree T)
{
    if (T)
    {
        InOrder(T->lchild);
        printf("%2c", T->data);
        InOrder(T->rchild);
    }
}
// 后序输出二叉树
void PostOrder(BiTree T)
{
    if (T)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%2c", T->data);
    }
}
// 先序非递归先序
int NRPreOrder(BiTree T) // 非递归先序遍历二叉树
{
    BiTree stack[MAX], p;
    int top; // 栈顶
    if (T == NULL)
        return 0; // 树为空则返回
    top = 0;
    p = T;                           // 这是一个用于存储移动的指针的变量
    while (!(p == NULL && top == 0)) // 当根结点不为空且栈不为空时
    {
        while (p != NULL) // 先深入左子树
        {
            printf("%2c", p->data); // 在此处用打印表示访问该结点
            if (top <= MAX - 1)
            {
                stack[top] = p; // 入栈
                top++;          // 栈顶位置++
            }
            else // 栈满时
            {
                printf("栈溢出");
                return 0;
            }
            p = p->lchild; // 深入当前根结点的左子树
        }
        if (top <= 0)
            return 0;
        else
        {
            top--;          // 栈顶--,
            p = stack[top]; // 弹出栈顶元素
            p = p->rchild;  // 指向右子树
        }
    }
}
// 中序非递归先序
int NRInOrder(BiTree T) // 非递归先序遍历二叉树
{
    BiTree stack[MAX], p;
    int top; // 栈顶
    if (T == NULL)
        return 0; // 树为空则返回
    top = 0;
    p = T;                           // 这是一个用于存储移动的指针的变量
    while (!(p == NULL && top == 0)) // 当根结点不为空且栈不为空时
    {
        while (p != NULL) // 先深入左子树
        {
            if (top <= MAX - 1)
            {
                stack[top] = p; // 入栈
                top++;          // 栈顶位置++
            }
            else // 栈满时
            {
                printf("栈溢出");
                return 0;
            }
            p = p->lchild; // 深入当前根结点的左子树
        }
        if (top <= 0)
            return 0;
        else
        {
            top--;                  // 栈顶--,
            p = stack[top];         // 弹出栈顶元素
            printf("%2c", p->data); // 在此处用打印表示访问该结点
            p = p->rchild;          // 指向右子树
        }
    }
}
// 层次遍历二叉树
void LevelOrder(BiTree T)
{
    BiTree Queue[MAX], b; // 用一维数组表示队列，front和rear表示队首和队尾的指针
    int front, rear;
    front = rear = 0;
    if (T)
    // 若树为空
    {
        Queue[rear++] = T;    // 根节点入队列
        while (front != rear) // 当队列非空
        {
            b = Queue[front++]; // 队首元素出队列，并访问这个节点
            printf("%2c", b->data);
            if (b->lchild != NULL)
                Queue[rear++] = b->lchild; // 若左子树非空，则入队列
            if (b->rchild != NULL)
                Queue[rear++] = b->rchild; // 若右子树非空，则入队列
        }
    }
}
// 求树的深度
int depth(BiTree T)
{
    int dep1, dep2;
    if (T == NULL)
        return 0;
    else
    {
        dep1 = depth(T->lchild);
        dep2 = depth(T->rchild);
        return dep1 > dep2 ? dep1 + 1 : dep2 + 1;
    }
}
// 后序非递归
void Nrpostorder(BiTree T)
{
    stacktype stack[MAX];
    BiTree p;
    int top, sign;
    if (T == NULL)
        return;
    top = -1;
    p = T;
    while (!(p == NULL && top == -1))
    {
        if (p != NULL)
        {
            top++;
            stack[top].link = p;
            stack[top].flag = 1;
            p = p->lchild;
        }
        else
        {
            p = stack[top].link;
            sign = stack[top].flag;
            top--;
            if (sign == 1)
            {
                top++;
                stack[top].link = p;
                stack[top].flag = 2;
                p = p->rchild;
            }
            else
            {
                printf("%2c", p->data);
                p = NULL;
            }
        }
    }
}

int copy(BiTree T, BiTree &NewT)
{
    if (T == NULL)
        NewT = NULL;
    else
    {
        NewT = new BiTNode;
        NewT->data = T->data;
        copy(T->lchild, NewT->lchild);
        copy(T->rchild, NewT->rchild);
    }
    return 1;
}
int NoteCount(BiTree T)
{
    if (T == NULL)
        return 0;
    else
        return NoteCount(T->lchild) + NoteCount(T->rchild) + 1; // 1为不同阶段不同的根节点
}
int LeafCount(BiTree T)
{
    if (T == NULL)
        return 0;
    else if (T->lchild == NULL && T->rchild == NULL)
        return 1;
    else
        return LeafCount(T->lchild) + LeafCount(T->rchild);
}
int main()
{
    BiTree T = NULL;
    BiTree NewT = NULL;
    printf("\n 创建一棵二叉树： \n");
    CreateBiTree(T); // 创建二叉树
    printf("\n先序遍历的结果为:\n");
    PreOrder(T); // 先序遍历
    printf("\n先序非递归遍历的结果为:\n");
    NRPreOrder(T);
    printf("\n中序遍历的结果为:\n");
    InOrder(T); // 中序遍历
    printf("\n中序非递归遍历的结果为:\n");
    NRInOrder(T); // 中序遍历
    printf("\n 后序遍历的结果为： \n");
    PostOrder(T);
    printf("\n 后序遍历非递归的结果为： \n");
    Nrpostorder(T);
    printf("\n 层次遍历的结果为: \n");
    LevelOrder(T); // 层次遍历
    printf("\n 树的深度为:%d\n", depth(T));
    printf("\n 树的结点个数为:%d\n", NoteCount(T));
    printf("\n 树的叶子结点个数为:%d\n", LeafCount(T));
    copy(T, NewT);
    printf("\n复制后的树的先序遍历的结果为:\n");
    PreOrder(NewT); // 先序遍历
    printf("\n复制后的树的中序遍历的结果为:\n");
    InOrder(NewT); // 中序遍历
    printf("\n复制后的树的后序遍历的结果为:\n");
    PostOrder(NewT); // 后序遍历
    printf("\n复制后的树的层次遍历的结果为:\n");
    LevelOrder(NewT); // 层次遍历
    printf("\n");
    printf("\n 复制后树的结点个数为:%d\n", NoteCount(T));
    printf("\n 复制后树的叶子结点个数为:%d\n", LeafCount(T));

    return 0;
}
// https://www.cnblogs.com/kangna/p/11846156.html#:~:text=void%20NRPreOrder%28BiTree%20t%29%20%2F%2F%E9%9D%9E%E9%80%92%E5%BD%92%E5%85%88%E5%BA%8F%E9%81%8D%E5%8E%86%E4%BA%8C%E5%8F%89%E6%A0%91%20%7B%20BiTree%20stack%20%5Bmaxsize%5D%2Cp%3B,printf%20%EF%BC%88%20%22%252c%22%2C%26p-%3Edata%EF%BC%89%EF%BC%9B%20%2F%2F%E5%9C%A8%E6%AD%A4%E5%A4%84%E7%94%A8%E6%89%93%E5%8D%B0%E8%A1%A8%E7%A4%BA%E8%AE%BF%E9%97%AE%E8%AF%A5%E7%BB%93%E7%82%B9%20p%3Dp-%3Erchild%3B%20%2F%2F%E6%8C%87%E5%90%91%E5%8F%B3%E5%AD%90%E6%A0%91%20%7D%20%7D
