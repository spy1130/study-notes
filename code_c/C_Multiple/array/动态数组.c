#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"DynamicArray.h"
void test01()
{
        //初始化动态数组
        Dynamic_Array*myArray = Init_Array();
        //打印容量
        printf("数组容量：%d\n",Capacity_Array(myArray));
        printf("数组大小：%d\n", Size_Array(myArray));
        //插入元素
        for (int i = 0; i < 30; i++)
        {
               PushBack_Array(myArray, i);
        }
        printf("数组容量：%d\n", Capacity_Array(myArray));
        printf("数组大小：%d\n", Size_Array(myArray));
        //打印
        Print_Array(myArray);
        //删除
        RemoveByPos_Array(myArray, 0);
        RemoveByValue_Array(myArray, 27);
        //打印
        Print_Array(myArray);
        //查找5个位置
        int pos = Find_Array(myArray,5);
        printf("5查找到:pos%d %d\n",pos,At_Array(myArray,pos));
        //销毁
        FreeSpace_Array(myArray);
}
int main()
{
        test01();
        return EXIT_SUCCESS;
}
