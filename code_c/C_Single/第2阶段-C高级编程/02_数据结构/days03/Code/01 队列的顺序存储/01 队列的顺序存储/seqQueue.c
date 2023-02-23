#include "seqQueue.h"

//初始化队列
seqQueue init_SeqQueue()
{
	struct dynamicArray * array = init_dynamicArray(MAX);

	return array;
}
//入队
void push_SeqQueue(seqQueue queue, void * data)
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

	struct dynamicArray * array = queue;

	if (array->m_Size >= MAX)
	{
		return;
	}

	insert_dynamicArray(array, array->m_Size, data);
}
//出队
void pop_SeqQueue(seqQueue queue)
{
	//等价于  头删除
	if (queue == NULL)
	{
		return;
	}

	struct dynamicArray * array = queue;

	if (array->m_Size <= 0)
	{
		return;
	}
	removeByPos_dynamicArray(array, 0);
}
//返回队头元素
void * front_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct dynamicArray * array = queue;

	return array->pAddr[0];

}

//返回队尾元素
void * back_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	struct dynamicArray * array = queue;
	
	return array->pAddr[array->m_Size - 1];

}

//队列大小
int size_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct dynamicArray * array = queue;

	return array->m_Size;

}

//判断是否为空
int isEmpty_SeqQueue(seqQueue queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	struct dynamicArray * array = queue;
	if (array->m_Size == 0)
	{
		return 1;
	}

	return 0;
}

//销毁队列
void destroy_SeqQueue(seqQueue queue)
{

	if (queue == NULL)
	{
		return ;
	}

	destroy_dynamicArray(queue);
	queue = NULL;
}