#include "linkQueue.h"


//初始化队列
LinkQueue init_LinkQueue()
{
	struct LQueue * myQueue = malloc(sizeof(struct LQueue));
	if (myQueue == NULL)
	{
		return NULL;
	}

	myQueue->m_Size = 0;
	myQueue->pHeader.next = NULL;
	myQueue->pTail = &myQueue->pHeader; //尾节点开始指向的就是头节点
	return myQueue;
}
//入队
void push_LinkQueue(LinkQueue queue, void * data)
{
	//等价于 尾插
	if (queue == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct LQueue * myQueue = queue;

	struct QueueNode * myNode = data; 


	//更改指针指向
	myQueue->pTail->next = myNode;
	myNode->next = NULL;
	//更新尾节点
	myQueue->pTail = myNode;

	//更新队列大小
	myQueue->m_Size++;

}
//出队
void pop_LinkQueue(LinkQueue queue)
{
	//等价于 头删 

	if (queue == NULL)
	{
		return;
	}
	struct LQueue * myQueue = queue;

	if (myQueue->m_Size == 0)
	{
		return;
	}

	if (myQueue->m_Size == 1)
	{
		myQueue->pHeader.next = NULL;
		myQueue->pTail = &myQueue->pHeader; //维护尾节点指针
		myQueue->m_Size = 0;
		return;
	}

	//记录第一个节点
	struct QueueNode * pFirst = myQueue->pHeader.next;

	myQueue->pHeader.next = pFirst->next;

	//更新队列大小
	myQueue->m_Size--;

}
//返回队头
void * front_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue * myQueue = queue;

	return myQueue->pHeader.next;

}
//返回队尾
void * back_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}
	struct LQueue * myQueue = queue;

	return myQueue->pTail;

}
//返回队列大小
int size_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue * myQueue = queue;

	return myQueue->m_Size;

}
//判断队列是否为空
int isEmpty_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	struct LQueue * myQueue = queue;

	if (myQueue->m_Size == 0)
	{
		return 1;
	}

	return 0;

}
//销毁队列
void destroy_LinkQueue(LinkQueue queue)
{
	if (queue == NULL)
	{
		return;
	}
	free(queue);
	queue = NULL;
}