#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
/*定义二叉树的结构*/
typedef struct Node
{
    char data;                    /*数据域*/
    struct Node *lchild, *rchild; /*左子树和右子树*/
} * BiTree, BiNode;
/*整棵树和结点名称*/

/*先需创建二叉树*/
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new BiNode; /*创建一个新节点*/
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    /*递归创建*/
}
void InOrderTraverse(BiTree T)
{
    /*中序遍历*/
    if (T)
    {
        InOrderTraverse(T->lchild);
        cout << T->data;
        InOrderTraverse(T->rchild);
    }
}
void PreOrderTraverse(BiTree T)
{
    /*先序遍历*/
    if (T)
    {
        cout << T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}
void PostOrderTraverse(BiTree T)
{
    /*后序遍历*/
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data;
    }
}
/*统计二叉树中结点的个数*/
int NodeCount(BiTree T)
{
    if (T == NULL)
        return 0;
    else
        return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
/*求树的深度*/
int Depth(BiTree T)
{
    if (T == NULL)
        return 0;
    else
    {
        int i = Depth(T->lchild);
        int j = Depth(T->rchild);
        return i > j ? i + 1 : j + 1;
    }
}
/*复制二叉树*/
void Copy(BiTree T, BiTree &NewT)
{
    if (T == NULL)
    {
        NewT = NULL;
        return;
    }
    else
    {
        NewT = new BiNode;
        NewT->data = T->data;
        Copy(T->lchild, NewT->lchild);
        Copy(T->rchild, NewT->rchild);
    }
}
/*统计二叉树中叶子结点的个数*/
int LeafCount(BiTree T)
{
    if (!T)
        return 0;
    if (!T->lchild && !T->rchild)
        return 1;
    /*如果二叉树左子树和右子树皆为空，说明该二叉树根节点为叶子结点，结果为1*/
    else
        return LeafCount(T->lchild) + LeafCount(T->rchild);
}
/*二叉树中从每个叶子结点到跟结点的路径*/
void PrintAllPath(BiTree T, char path[], int pathlen)
{
    int i;
    if (T != NULL)
    {
        path[pathlen] = T->data; /*将当前结点放入路径中*/
        if (T->lchild == NULL && T->rchild == NULL)
        {
            /*若这个节点是叶子结点*/
            for (i = pathlen; i >= 0; i--)
                cout << path[i] << " ";
            cout << "\n";
        }
        else
        {
            PrintAllPath(T->lchild, path, pathlen + 1);
            PrintAllPath(T->rchild, path, pathlen + 1);
        }
    }
}
/*判断二叉树是否为空*/
int BiTree_empty(BiTree T)
{
    if (T)
        return 1;
    else
        return 0;
}
int main()
{
    BiTree T;
    //测试数据AB#CD##E##F#GH###
    cout << "先序遍历输入(以#结束):";
    CreateBiTree(T);
    cout << "中序遍历输出：";
    InOrderTraverse(T);
    cout << endl
         << "先序遍历输出:";
    PreOrderTraverse(T);
    cout << "\n"
         << "后序遍历输出:";
    PostOrderTraverse(T);
    cout << endl
         << "树的深度:" << Depth(T);
    cout << endl
         << "结点的个数:" << NodeCount(T);
    cout << endl
         << "二叉树中从每个叶子结点到根结点的所有路径：" << endl;
    char path[256];
    int pathlen = 0;
    PrintAllPath(T, path, pathlen);
    return 0;
}
