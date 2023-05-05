#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//孩子链表（找孩子容易，找双亲难）
// 孩子结点结构
typedef struct CTNode
{
    char child;
    struct CTNode *next;
} *ChildPtr;
// 双亲结点结构
typedef struct
{
    char data;
    ChildPtr firstchild;
} CTBox;
// 树结构
typedef struct
{
    CTBox nodes[100]; // max=100
    int n, r;         // 结点数和根的位置
} CTree;


// 孩子兄弟链表
typedef struct CSNode
{
    char data;
    struct CSNode *firstchild, *nextsibling;//指向第一个孩子和下一个兄弟
} CSNode, *CSTree;

//二叉树
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild; // 左右孩子的指针
} BiTNode, *BiTree;

// 孩子兄弟链表的建立
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
// 孩子兄弟链表的先序遍历
void PreOrder(CSTree T)
{
    if (T)
    {
        cout << T->data;
        PreOrder(T->firstchild);
        PreOrder(T->nextsibling);
    }
}
// 孩子兄弟链表的后序遍历
void PostOrder(CSTree T)
{
    if (T)
    {
        PostOrder(T->firstchild);
        cout << T->data;
        PostOrder(T->nextsibling);
    }
}
// 孩子兄弟链表的深度
int Depth(CSTree T)
{
    int max = 0, dep;
    CSTree p;
    if (T)
    {
        p = T->firstchild;
        while (p)
        {
            dep = Depth(p);
            if (dep > max)
                max = dep;
            p = p->nextsibling;
        }
        return max + 1;
    }
    else
        return 0;
}
// 孩子兄弟链表的叶子结点数
int LeafCount(CSTree T)
{
    int count = 0;
    CSTree p;
    if (T)
    {
        p = T->firstchild;
        if (!p)
            count++;
        while (p)
        {
            count += LeafCount(p);
            p = p->nextsibling;
        }
        return count;
    }
    else
        return 0;
}
// 孩子兄弟链表的复制
void Copy(CSTree &T, CSTree &NewT)
{
    if (T)
    {
        NewT = new CSNode;
        NewT->data = T->data;
        Copy(T->firstchild, NewT->firstchild);
        Copy(T->nextsibling, NewT->nextsibling);
    }
    else
        NewT = NULL;
}
// 孩子兄弟链表的销毁
void Destroy(CSTree &T)
{
    if (T)
    {
        Destroy(T->firstchild);
        Destroy(T->nextsibling);
        delete T;
    }
}
// 孩子兄弟链表的求值
int Value(CSTree T)
{
    int x, y;
    if (T)
    {
        if (!T->firstchild)
            return T->data - '0';
        else
        {
            x = Value(T->firstchild);
            y = Value(T->firstchild->nextsibling);
            switch (T->data)
            {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            }
        }
    }
    else
        return 0;
}
// 孩子兄弟链表的求值(后缀表达式)
int Value2(CSTree T)
{
    int x, y;
    if (T)
    {
        if (!T->firstchild)
            return T->data - '0';
        else
        {
            x = Value2(T->firstchild);
            y = Value2(T->firstchild->nextsibling);
            switch (T->data)
            {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            }
        }
    }
    else
        return 0;
}
// 孩子兄弟链表的求值(前缀表达式)
int Value3(CSTree T)
{
    int x, y;
    if (T)
    {
        if (!T->firstchild)
            return T->data - '0';
        else
        {
            x = Value3(T->firstchild->nextsibling);
            y = Value3(T->firstchild);
            switch (T->data)
            {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            }
        }
    }
    else
        return 0;
}
// 孩子兄弟链表的求值(中缀表达式)
int Value4(CSTree T)
{
    int x, y;
    if (T)
    {
        if (!T->firstchild)
            return T->data - '0';
        else
        {
            x = Value4(T->firstchild);
            y = Value4(T->firstchild->nextsibling);
            switch (T->data)
            {
            case '+':
                return x + y;
            case '-':
                return x - y;
            case '*':
                return x * y;
            case '/':
                return x / y;
            }
        }
    }
    else
        return 0;
}
//将树的孩子兄弟链表表示转换为二叉树表示
void CSTree2BiTree(CSTree T, BiTree &BT)
{
    if (T)
    {
        BT = new BiTNode;
        BT->data = T->data;
        CSTree2BiTree(T->firstchild, BT->lchild);
        CSTree2BiTree(T->nextsibling, BT->rchild);
    }
    else
        BT = NULL;
}
//将二叉树转换为树的孩子兄弟链表
void BiTree2CSTree(BiTree BT, CSTree &T)
{
    if (BT)
    {
        T = new CSNode;
        T->data = BT->data;
        BiTree2CSTree(BT->lchild, T->firstchild);
        BiTree2CSTree(BT->rchild, T->nextsibling);
    }
    else
        T = NULL;
}
int main()
{
    CSTree T;
    CreateCSTree(T);
    PreOrder(T);
    cout << endl;
    PostOrder(T);
    cout << endl;
    cout << Depth(T) << endl;
    cout << LeafCount(T) << endl;
    CSTree NewT;
    Copy(T, NewT);
    PreOrder(NewT);
    cout << endl;
    cout << Value(T) << endl;
    cout << Value2(T) << endl;
    cout << Value3(T) << endl;
    cout << Value4(T) << endl;
    BiTree BT;
    CSTree2BiTree(T, BT);
    BiTree2CSTree(BT, T);
    PreOrder(T);
    cout << endl;
    Destroy(T);
    system("pause");
    return EXIT_SUCCESS;
}