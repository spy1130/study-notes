#include <stdio.h>
#include <stdlib.h>
// 基本单位
struct node
{
    int data;
    struct node *next;
};
// 创建头链表(需要一个同类型指针接受)
struct node *creatlist()
{
    struct node *headnode = (struct node *)malloc(sizeof(struct node));
    headnode->next = NULL;
    return headnode;
}
// 创建新的节点
struct node *newnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
// 表头法插入，体现了头节点的作用
void insertbyhead(struct node *headnode, int data)
{
    struct node *newNode = newnode(data);
    newNode->next = headnode->next;
    headnode->next = newNode;
}
// 遍历打印链表
void printlist(struct node *headnode)
{
    struct node *pmove = headnode->next; // 有表头链表，要从第二个开始，体现了头节点的作用+1
    if (pmove == NULL)
        printf("空链表\n");
    else
    {
        while (pmove != NULL)
        {
            printf("%d->", pmove->data);
            pmove = pmove->next;
        }
        printf("\n");
    }
}
// 表尾法插入（往后建新的节点）
void insertbytail(struct node *headnode, int data)
{
    // 插入的节点
    struct node *newNode = newnode(data);
    // 临时尾指针
    struct node *tailnode = headnode;
    while (tailnode->next != NULL) // 查找尾指针
    {
        tailnode = tailnode->next;
    }
    tailnode->next = newNode; // 建立连接
}
// 插在某个数据的前面的函数
void insert(struct node *headnode, int data, int posdata)
{
    // 创建两个临时指针实现节点插入
    struct node *posfrt = headnode;
    struct node *pos = headnode->next;
    // 查找位置
    while (pos != NULL && pos->data != posdata)
    {
        posfrt = pos;
        pos = pos->next;
    }
    if (pos == NULL)
        printf("找不到合适位置\n");
    else
    {
        struct node *newNode = newnode(data); // 找不到合适的位置时候就先别申请内存节省空间
        newNode->next = pos;
        posfrt->next = newNode;
    } // 连接
}
// 表头法删除节点
void deletebyhead(struct node *headnode)
{
    if (headnode->next == NULL)
        printf("这是个空链表\n"); // 空链表无法删除
    else
    {
        struct node *nextnode = headnode->next;
        headnode->next = headnode->next->next;
        free(nextnode);
    }
}
// 表尾法删除节点
void deletebytail(struct node *headnode)
{
    if (headnode->next == NULL)
        printf("这是个空链表\n"); // 防止bug，查询一下是不是空链表
    else
    {
        // 临时
        struct node *tailnode = headnode->next;
        struct node *tailfro = headnode;
        // 查找尾
        while (tailnode->next != NULL)
        {
            tailfro = tailnode;
            tailnode = tailnode->next;
        }
        // 删除
        tailfro->next = NULL;
        free(tailnode);
    }
}
// 查找并删除
void deletenode(struct node *headnode, int data)
{
    // 临时
    struct node *deletenodefro = headnode;
    struct node *deletenode = headnode->next;
    // 查找
    while (deletenode != NULL && deletenode->data != data)
    {
        deletenodefro = deletenode;
        deletenode = deletenode->next;
    }
    if (deletenode == NULL)
        printf("找不到对应节点\n");
    else
    {
        // 删除
        deletenodefro->next = deletenode->next;
        free(deletenode);
    }
}
// 清空链表（只是清空用这个）
void clear_LinkList(struct node *headnode)
{
    if (headnode == NULL)
        return;
    else
    {
        // 临时
        struct node *pCurrent = headnode->next;
        while (pCurrent != NULL)
        { // 先记录下一个节点的位置
            struct node *nextNode = pCurrent->next;
            // 释放当前节点
            free(pCurrent);
            // 节点向后移动
            pCurrent = nextNode;
        }
        // 头节点next置空
        headnode->next = NULL;
    }
}
// 销毁列表(删链表用这个)
void destroy_LinkList(struct node *headnode)
{
    if (headnode == NULL)
        return;
    else
    {
        //先清空列表
        clear_LinkList(headnode);
        free(headnode);
        headnode =NULL;
    }
}
