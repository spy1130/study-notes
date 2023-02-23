#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 底层设计
void selectSort(void *arr, int eleSize, int len, int (*myCompare)(void *, void *))
{
    char *temp = malloc(eleSize);
    for (int i = 0; i < len; i++)
    {
        // 认定i就是最小值 或者最大值
        int minOrmax = i;
        for (int j = i + 1; j < len; j++)
        {
            // 获取j元素的首地址
            char *p = (char *)arr + eleSize * j;
            // 获取当前最小值或者最大值的首地址
            char *pmami = (char *)arr + eleSize * minOrmax;
            if (myCompare(p, pmami))
            {
                minOrmax = j;
            }
        }
        if (i != minOrmax) // 如果认定的最小值或最大值不是计算出的minOrmax
        {
            // 通过内存拷贝实现交换
            char *pi = (char *)arr + eleSize * i;
            char *pminormax = (char *)arr + eleSize * minOrmax;

            memcpy(temp, pi, eleSize);
            memcpy(pi, pminormax, eleSize);
            memcpy(pminormax, temp, eleSize);
        }
    }
    if (temp != NULL)
    {
        free(temp);
        temp = NULL;
    }
}
// 用户方
int compareInt(void *data1, void *data2)
{
    int *num1 = data1;
    int *num2 = data2;

    // 升序
    if (*num1 < *num2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// 结构体数组排序
struct Person
{
    char name[128];
    int age;
};
// 按年龄降序排列
int comparearr(void *data1, void *data2)
{
    struct Person *p1 = data1;
    struct Person *p2 = data2;
    //     if(p1->age>p2->age){
    //        return 1;
    //    }
    //    else{
    //        return 0;
    //    }
    return p1->age > p2->age;
}
void test()
{
    struct Person arr[] = {
        {"aaa", 1323},
        {"bbb", 139},
        {"ddd", 136},
        {"ccc", 312},
        {"eee", 135},
    };
    int len = sizeof(arr) / sizeof(struct Person);
    selectSort(arr, sizeof(struct Person), len, comparearr);
    for (int i = 0; i < len; i++)
    {
        printf("%s\t%d", arr[i].name, arr[i].age);
    }
}

int main()
{
    int arr[] = {10, 20, 401, 102, 1241, 1410, 1412, 14121, 412411};
    int len = sizeof(arr) / sizeof(int);
    selectSort(arr, sizeof(int), len, compareInt);

    for (int i = 0; i < len; i++)
    {
        printf("%d\n", arr[i]);
    }
    system("pause");
    return 0;
}