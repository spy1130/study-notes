#include "seqStack.h"


//初始化栈
SeqStack init_SeqStack()
{
	struct SStack *myStack = malloc(sizeof(struct SStack));

	if (myStack == NULL)
	{
		return NULL;
	}

	memset(myStack->data, 0, sizeof(void *)* MAX); //数组置空

	myStack->m_Size = 0;

	return myStack;
}
//入栈

void push_SeqStack(SeqStack stack, void * data)
{
	//本质就是数组尾插

	if (stack == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	struct SStack * myStack = stack;

	if (myStack->m_Size == MAX)
	{
		return;
	}

	myStack->data[myStack->m_Size] = data;

	myStack->m_Size++;

}


//出栈
void pop_SeqStack(SeqStack stack)
{
	//出栈本质 尾删
	if (stack == NULL)
	{
		return;
	}
	struct SStack * myStack = stack;

	//如果是空栈 直接 return
	if (myStack->m_Size == 0)
	{
		return;
	}

	myStack->data[myStack->m_Size - 1] = NULL;
	myStack->m_Size--;
}


//返回栈顶元素
void * top_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	struct SStack * myStack = stack;

	//如果是空栈 返回NULL
	if (myStack->m_Size == 0)
	{
		return NULL;
	}

	return myStack->data[myStack->m_Size - 1];
}


//获取栈大小
int size_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return 0;
	}
	struct SStack * myStack = stack;

	return myStack->m_Size;

}

//判断栈是否为空
int isEmpty_SeqStack(SeqStack stack)
{

	if (stack == NULL)
	{
		return -1; //如果传入的是NULL，返回也是空栈
	}
	struct SStack * myStack = stack;

	if (myStack->m_Size == 0)
	{
		return 1;
	}

	return 0;

}


//销毁栈
void destroy_SeqStack(SeqStack stack)
{
	if (stack == NULL)
	{
		return;
	}

	free(stack);
	stack = NULL;
}
