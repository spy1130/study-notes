#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "linkQueue.h"

struct Person
{
	void * node;
	char name[64];
	int age;
};

void test01()
{
	//初始化队列
	LinkQueue myQueue = init_LinkQueue();

	//准备数据
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };

	//入队
	push_LinkQueue(myQueue, &p1);
	push_LinkQueue(myQueue, &p2);
	push_LinkQueue(myQueue, &p3);
	push_LinkQueue(myQueue, &p4);
	push_LinkQueue(myQueue, &p5);

	printf("队列大小为：%d\n", size_LinkQueue(myQueue));

	while (isEmpty_LinkQueue(myQueue) == 0)
	{
		//队头元素
		struct Person * pFront = front_LinkQueue(myQueue);
		printf("链式存储 队头元素姓名：%s 年龄：%d \n", pFront->name, pFront->age);

		//队尾元素
		struct Person * pBack = back_LinkQueue(myQueue);
		printf("链式存储 队尾元素姓名：%s 年龄：%d \n", pBack->name, pBack->age);

		//出队
		pop_LinkQueue(myQueue);
	}

	printf("队列大小为：%d\n", size_LinkQueue(myQueue));

	//销毁队列
	destroy_LinkQueue(myQueue);
	myQueue = NULL;
}


int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}