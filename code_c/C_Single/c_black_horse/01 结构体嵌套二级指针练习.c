#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Teacher
{
	char * name;
	char ** Students;
};


void allocateSpace( struct Teacher *** teachers)
{

	struct Teacher ** pArray = malloc(sizeof(struct Teacher *) * 3);

	for (int i = 0; i < 3;i++)
	{
		//给每个老师分配空间
		pArray[i] =  malloc(sizeof(struct Teacher));

		//给每个老师姓名 分配空间
		pArray[i]->name = malloc(sizeof(char)* 64);
		sprintf(pArray[i]->name, "Teacher_%d", i + 1);

		//给老师带的学生的数组分配空间
		pArray[i]->Students =  malloc(sizeof(char *)* 4);

		//给4个学生在分配内存，并且赋值
		for (int j = 0; j < 4;j++)
		{
			pArray[i]->Students[j] = malloc(sizeof(char)* 64);
			sprintf(pArray[i]->Students[j], "%s_Student_%d", pArray[i]->name, j + 1);
		}
	}


	*teachers = pArray;
}


void showArray(struct Teacher ** pArray, int len)
{
	for (int i = 0; i < len;i++)
	{
		printf("%s\n", pArray[i]->name);
		for (int j = 0; j < 4;j++)
		{
			printf("     %s\n", pArray[i]->Students[j]);
		}
	}
}

void freeSpace(struct Teacher ** pArray , int len)
{
	for (int i = 0; i < len;i++)
	{
		//释放老师姓名
		if (pArray[i]->name != NULL)
		{
			free(pArray[i]->name);
			pArray[i]->name = NULL;
		}

		//释放每个学生
		for (int j = 0; j < 4;j++)
		{
			if (pArray[i]->Students[j] != NULL)
			{
				free(pArray[i]->Students[j]);
				pArray[i]->Students[j] = NULL;
			}
		}

		//释放学生数组
		free(pArray[i]->Students);
		pArray[i]->Students = NULL;


		//释放老师
		free(pArray[i]);
		pArray[i] = NULL;
	}


	//释放老师数组
	free(pArray);
	pArray = NULL;
}

void test01()
{

	struct Teacher ** pArray = NULL;
	//分配内存
	allocateSpace(&pArray);

	//打印数组
	showArray(pArray , 3);


	//释放内存
	freeSpace(pArray,3);
	pArray = NULL;

}


int main(){
	test01();


	system("pause");
	return EXIT_SUCCESS;
}