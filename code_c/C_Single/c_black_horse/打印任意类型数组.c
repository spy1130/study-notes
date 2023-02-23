#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 1 数组首地址 2 每个元素的占用空间 3 数组长度
void printAllArray(void *arr, int len, int eleSzie, void(*myPrint(void *)))
{
    char *p = arr; // 利用p指针接受数组首地址
    for (int i = 0; i < len; i++)
    {
        // 获取每个元素的首地址
        char *pAddr = p + eleSzie * i;
        printf("%d\n", *(int *)pAddr);
    }
}
void printInt(void *data)
{
    int *num = data;
    printf("%d\n", *num);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(int);
    printAllArray(arr, len, sizeof(int), printInt);
    system("pause");
    return 0;
}