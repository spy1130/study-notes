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

//获取叶子数量
void calculateLeafNum( struct BinaryNode * root , int *p )
{
	if (root == NULL)
	{
		return;
	}

	if (root->lChild == NULL && root->rChild == NULL)
	{
		(*p)++;
	}

	calculateLeafNum(root->lChild, p);

	calculateLeafNum(root->rChild, p);
}


//获取树的高度
int getTreeHeight(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return 0;
	}

	//获取左子树高度
	int lHeight= getTreeHeight(root->lChild);

	//再获取右子树高度
	int rHeight = getTreeHeight(root->rChild);

	//在左子树和右子树中取大的值 +1 
	int height = lHeight > rHeight ? lHeight + 1 : rHeight + 1;

	return height;

}

//拷贝二叉树

struct BinaryNode * copyTree(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return NULL;
	}


	//先拷贝左子树
	struct  BinaryNode * lChild = copyTree(root->lChild);

	//再拷贝右子树
	struct BinaryNode * rChild = copyTree(root->rChild);

	//再拷贝根节点
	struct BinaryNode * newNode = malloc(sizeof(struct BinaryNode));

	newNode->lChild = lChild;
	newNode->rChild = rChild;
	newNode->ch = root->ch;

	return newNode;


}


void showTree(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return;
	}

	

	showTree(root->lChild);

	printf("%c ", root->ch);

	showTree(root->rChild);

}


void freeTree(struct BinaryNode * root)
{
	if (root == NULL)
	{
		return;
	}

	//先释放左子树
	freeTree(root->lChild);
	//再释放右子树
	freeTree(root->rChild);
	//再释放根节点
	printf("%c 被释放了\n", root->ch);
	free(root);
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

	//1、获取叶子数量
	int num = 0;
	calculateLeafNum(&nodeA, &num);

	printf("树中的叶子数量为： %d\n", num);


	//2、获取树的高度
	int height = getTreeHeight(&nodeA);

	printf("树的高度为：%d\n", height);


	//3、拷贝二叉树

	struct BinaryNode * newTree = copyTree(&nodeA);

	showTree(newTree);
	printf("\n");

	//4、释放二叉树
	freeTree(newTree);

}

int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}