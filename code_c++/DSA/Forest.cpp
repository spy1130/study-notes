#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
// 森林
typedef struct CSNode
{
    char data;
    struct CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;
// 二叉树结构
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void CreateCSTree(CSTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new CSNode;
        T->data = ch;
        CreateCSTree(T->firstchild);
        CreateCSTree(T->nextsibling);
    }
}
// 森林的先序遍历
void PreOrder(CSTree T)
{
    if (T)
    {
        cout << T->data;
        PreOrder(T->firstchild);
        PreOrder(T->nextsibling);
    }
}
// 森林的后序遍历
void PostOrder(CSTree T)
{
    if (T)
    {
        PostOrder(T->firstchild);
        cout << T->data;
        PostOrder(T->nextsibling);
    }
}
// 森林的层次遍历
void LevelOrder(CSTree T)
{
    CSTree queue[100];
    int front = 0, rear = 0;
    if (T)
    {
        rear = (rear + 1) % 100;
        queue[rear] = T;
        while (front != rear)
        {
            front = (front + 1) % 100;
            T = queue[front];
            cout << T->data;
            if (T->firstchild)
            {
                rear = (rear + 1) % 100;
                queue[rear] = T->firstchild;
            }
            if (T->nextsibling)
            {
                rear = (rear + 1) % 100;
                queue[rear] = T->nextsibling;
            }
        }
    }
}
// 森林转二叉树
void ForestToBinaryTree(CSTree T, BiTree &BT)
{
    if (T)
    {
        BT = new BiTNode;
        BT->data = T->data;
        ForestToBinaryTree(T->firstchild, BT->lchild);
        ForestToBinaryTree(T->nextsibling, BT->rchild);
    }
    else
        BT = NULL;
}
// 二叉树转森林
void BinaryTreeToForest(BiTree BT, CSTree &T)
{
    if (BT)
    {
        T = new CSNode;
        T->data = BT->data;
        BinaryTreeToForest(BT->lchild, T->firstchild);
        BinaryTreeToForest(BT->rchild, T->nextsibling);
    }
    else
        T = NULL;
}
// 森林的叶子结点数
int LeafCount(CSTree T)
{
    if (T == NULL)
        return 0;
    else if (T->firstchild == NULL)
        return 1 + LeafCount(T->nextsibling);
    else
        return LeafCount(T->firstchild) + LeafCount(T->nextsibling);
}
// 森林的高度
int Height(CSTree T)
{
    int hc, hs;
    if (T == NULL)
        return 0;
    else
    {
        hc = Height(T->firstchild);
        hs = Height(T->nextsibling);
        return (hc + 1 > hs) ? hc + 1 : hs;
    }
}
// 森林的宽度
int Width(CSTree T)
{
    int w, maxw = 0;
    while (T)
    {
        w = Width(T->firstchild);
        if (w > maxw)
            maxw = w;
        T = T->nextsibling;
    }
    return maxw;
}
// 森林的结点数
int NodeCount(CSTree T)
{
    if (T == NULL)
        return 0;
    else
        return 1 + NodeCount(T->firstchild) + NodeCount(T->nextsibling);
}
// 森林的度为k的结点数
int DegreeCount(CSTree T, int k)
{
    if (T == NULL)
        return 0;
    else if (k == 0)
        return 1;
    else
        return DegreeCount(T->firstchild, k - 1) + DegreeCount(T->nextsibling, k);
}
// 森林的度最大的结点
CSTree MaxDegreeNode(CSTree T)
{
    CSTree p, q;
    int max = 0;
    if (T == NULL)
        return NULL;
    else
    {
        p = T;
        while (p)
        {
            if (DegreeCount(p, 1) > max)
            {
                max = DegreeCount(p, 1);
                q = p;
            }
            p = p->nextsibling;
        }
        return q;
    }
}
// 森林的度最小的结点
CSTree MinDegreeNode(CSTree T)
{
    CSTree p, q;
    int min = 100;
    if (T == NULL)
        return NULL;
    else
    {
        p = T;
        while (p)
        {
            if (DegreeCount(p, 1) < min)
            {
                min = DegreeCount(p, 1);
                q = p;
            }
            p = p->nextsibling;
        }
        return q;
    }
}
//森林的销毁
void DestroyForest(CSTree &T)
{
    if (T)
    {
        DestroyForest(T->firstchild);
        DestroyForest(T->nextsibling);
        delete T;
    }
}

int main()
{
    CSTree T;
    BiTree BT;
    CreateCSTree(T);
    cout << "森林的先序遍历为：";
    PreOrder(T);
    cout << endl;
    cout << "森林的后序遍历为：";
    PostOrder(T);
    cout << endl;
    cout << "森林的层次遍历为：";
    LevelOrder(T);
    cout << endl;
    cout << "森林的叶子结点数为：" << LeafCount(T) << endl;
    cout << "森林的高度为：" << Height(T) << endl;
    cout << "森林的宽度为：" << Width(T) << endl;
    cout << "森林的结点数为：" << NodeCount(T) << endl;
    cout << "森林的度为2的结点数为:" << DegreeCount(T, 2) << endl;
    cout << "森林的度最大的结点为：" << MaxDegreeNode(T)->data << endl;
    cout << "森林的度最小的结点为：" << MinDegreeNode(T)->data << endl;
    ForestToBinaryTree(T, BT);
    BinaryTreeToForest(BT, T);
    cout << "二叉树转森林的先序遍历为：";
    PreOrder(T);
    cout << endl;
    cout << "二叉树转森林的后序遍历为：";
    PostOrder(T);
    cout << endl;
    cout << "二叉树转森林的层次遍历为：";
    LevelOrder(T);
    cout << endl;
    DestroyForest(T);
    
    system("pause");
    return EXIT_SUCCESS;
}
