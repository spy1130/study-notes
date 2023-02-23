#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct BinaryNode
{
	char ch; //数据域

	struct BinaryNode * lChild;//左子树指针

	struct BinaryNode * rChild; //右子树指针

};

//递归遍历
void recursion(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return; //结束条件
	}

	//先序

	printf("%c ", root->ch);

	recursion(root->lChild);

	recursion(root->rChild);

}


void test01()
{
	//创建节点
	struct BinaryNode nodeA = { 'A', NULL, NULL };
	struct BinaryNode nodeB = { 'B', NULL, NULL };
	struct BinaryNode nodeC = { 'C', NULL, NULL };
	struct BinaryNode nodeD = { 'D', NULL, NULL };
	struct BinaryNode nodeE = { 'E', NULL, NULL };
	struct BinaryNode nodeF = { 'F', NULL, NULL };
	struct BinaryNode nodeG = { 'G', NULL, NULL };
	struct BinaryNode nodeH = { 'H', NULL, NULL };

	//建立关系
	nodeA.lChild = &nodeB;
	nodeA.rChild = &nodeF;
	
	nodeB.rChild = &nodeC;
	
	nodeC.lChild = &nodeD;
	nodeC.rChild = &nodeE;

	nodeF.rChild = &nodeG;

	nodeG.lChild = &nodeH;

	//递归遍历
	recursion(&nodeA);

}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}