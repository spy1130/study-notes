#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "seqStack.h"

/*
	1 、 将根节点压入栈中
	2 、 执行循环
		2.1 获取栈顶元素
		2.2 弹出栈顶元素
		2.3 如果栈顶标志位真 直接输出
		2.4 如果标志位假  将标志改为真
		2.5 将 右子树  左子树  根 入栈
*/


struct BinaryNode
{
	char ch;
	struct BinaryNode * lChild;
	struct BinaryNode * rChild;
	int flag; //标志
};


void nonRecursion(struct BinaryNode * root)
{
	//初始化栈 
	SeqStack myStack = init_SeqStack();

	push_SeqStack(myStack, root);

	while (size_SeqStack(myStack) >0)
	{
		//获取栈顶元素
		struct BinaryNode * topNode =  top_SeqStack(myStack);

		//弹出栈顶元素
		pop_SeqStack(myStack);

		//如果栈顶标志位真 直接输出
		if (topNode->flag == 1)
		{
			printf("%c ",topNode->ch);
			continue;
		}

		//如果标志位假  将标志改为真
		topNode->flag = 1;


		//将 右子树  左子树  根 入栈
		if (topNode->rChild != NULL)
		{
			push_SeqStack(myStack, topNode->rChild);
		}

		if (topNode->lChild != NULL)
		{
			push_SeqStack(myStack, topNode->lChild);
		}

		push_SeqStack(myStack, topNode);

	}

	//销毁栈 
	destroy_SeqStack(myStack);
}

void test01()
{
	//创建节点
	struct BinaryNode nodeA = { 'A', NULL, NULL, 0 };
	struct BinaryNode nodeB = { 'B', NULL, NULL, 0 };
	struct BinaryNode nodeC = { 'C', NULL, NULL, 0 };
	struct BinaryNode nodeD = { 'D', NULL, NULL, 0 };
	struct BinaryNode nodeE = { 'E', NULL, NULL, 0 };
	struct BinaryNode nodeF = { 'F', NULL, NULL, 0 };
	struct BinaryNode nodeG = { 'G', NULL, NULL, 0 };
	struct BinaryNode nodeH = { 'H', NULL, NULL, 0 };

	//建立关系
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;

	nodeB.rChild = &nodeC;

	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;


	//非递归遍历
	nonRecursion(&nodeA);
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}