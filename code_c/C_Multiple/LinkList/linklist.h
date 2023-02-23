#pragma once
#include <stdio.h>
#include <stdlib.h>
// 基本单位
struct node
{
    int data;
    struct node *next;
};
//外部函数需要特殊声明 __declspec(dllexport)
// 创建头链表(需要一个同类型指针接受)
__declspec(dllexport) struct node *creatlist();
//创建新的节点
struct node *newnode(int data);
// 表头法插入，体现了头节点的作用
void insertbyhead(struct node *headnode, int data);
// 遍历打印链表
void printlist(struct node *headnode);
// 表尾法插入（往后建新的节点）
void insertbytail(struct node *headnode, int data);
// 插在某个数据的前面的函数
void insert(struct node *headnode, int data, int posdata);
// 表头法删除节点
void deletebyhead(struct node *headnode);
// 表尾法删除节点
void deletebytail(struct node *headnode);
// 查找并删除
void deletenode(struct node *headnode, int data);
// 清空链表（只是清空用这个）
void clear_LinkList(struct node *headnode);
// 销毁列表(删链表用这个)
void destroy_LinkList(struct node *headnode);
// 链表的反转
void reverse_Linklist(struct node* pHeader);
// 统计链表个数
int size_linklist(struct node* pHeader);