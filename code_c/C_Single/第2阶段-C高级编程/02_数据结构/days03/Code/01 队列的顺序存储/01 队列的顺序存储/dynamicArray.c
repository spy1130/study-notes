#include "dynamicArray.h"


//初始化数组 参数代表 初始化的容量
struct dynamicArray * init_dynamicArray(int capacity)
{
	struct dynamicArray * array = malloc(sizeof(struct dynamicArray));

	if (array == NULL)
	{
		return NULL;
	}

	//给数组属性初始化
	array->m_Capacity = capacity;
	array->m_Size = 0;
	array->pAddr = malloc(sizeof(void *)* capacity);

	if (array->pAddr == NULL)
	{
		return NULL;
	}

	return array;
}


//插入元素
void insert_dynamicArray(struct dynamicArray * arr, int pos, void * data)
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	if (pos < 0 || pos > arr->m_Size)
	{
		//无效的位置  进行尾插
		pos = arr->m_Size;
	}

	//判断是否有空间进行插入，如果没有空间了，那么动态扩展
	if (arr->m_Size >= arr->m_Capacity)
	{
		//1、计算申请空间大小
		int newCapacity = arr->m_Capacity * 2;

		//2、创建新空间
		void ** newSpace = malloc(sizeof (void *)* newCapacity);

		//3、 将原有数据拷贝到新空间下
		memcpy(newSpace, arr->pAddr, sizeof(void*)* arr->m_Capacity);

		//4、 释放原有空间
		free(arr->pAddr);

		//5、 更新指针的指向
		arr->pAddr = newSpace;

		//6、更新新数组容量
		arr->m_Capacity = newCapacity;
	}


	//插入数据

	for (int i = arr->m_Size - 1; i >= pos; i--)
	{
		//数据后移
		arr->pAddr[i + 1] = arr->pAddr[i];
	}
	//将新数据放入到指定位置中
	arr->pAddr[pos] = data;


	//更新数组大小
	arr->m_Size++;
}

//遍历数组
void foreach_dynamicArray(struct dynamicArray * arr, void(*myPrint)(void *))
{
	if (arr == NULL)
	{
		return;
	}

	if (myPrint == NULL)
	{
		return;
	}

	for (int i = 0; i < arr->m_Size; i++)
	{
		myPrint(arr->pAddr[i]);
	}
}


//删除数组
void removeByPos_dynamicArray(struct dynamicArray * arr, int pos)
{
	if (arr == NULL)
	{
		return;
	}

	//无效位置 就直接return
	if (pos < 0 || pos >arr->m_Size - 1)
	{
		return;
	}

	//移动数据
	for (int i = pos; i < arr->m_Size - 1; i++)
	{
		arr->pAddr[i] = arr->pAddr[i + 1];
	}

	//更新大小
	arr->m_Size--;

}

//按照值 来删除数组中数据
void removeByValue_dynamicArray(struct dynamicArray * arr, void * data, int(*myCompare)(void *, void *))
{
	if (arr == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}

	for (int i = 0; i < arr->m_Size; i++)
	{
		if (myCompare(arr->pAddr[i], data))
		{
			//如果对比成功了，那么要删除i下标的元素
			removeByPos_dynamicArray(arr, i);
			break;
		}
	}


}

//销毁数组
void destroy_dynamicArray(struct dynamicArray * arr)
{

	if (arr == NULL)
	{
		return;
	}

	if (arr->pAddr != NULL)
	{
		free(arr->pAddr);
		arr->pAddr = NULL;
	}


	free(arr);
	arr = NULL;

}
