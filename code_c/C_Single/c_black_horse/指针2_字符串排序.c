#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//%s方式打印数组的元素
// n代表数组元素个数
void print_word(char *words[], int n);

// 冒泡排序
void sort_word(char *words[], int n);

int main()
{
    char *words[] = {"city", "student", "tree", "bee"};
    int n = sizeof(words) / sizeof(words[0]);

    // 排序前，city student tree bee
    print_word(words, n);

    // 冒泡排序
    sort_word(words, n);

    // 排序后，bee city student tree
    print_word(words, n);

    return 0;
}
void print_word(char *words[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");
}
void sort_word(char *words[], int n)
{
    for (int i = 0; i < n - 1; i++) // 比较的轮数
    {
        for (int j = 0; j < n - 1 - i; j++) // 每一轮需要比较的次数
        {
            if (strcmp(words[j], words[j + 1]) > 0)
            {
                char *tmp;
                tmp = words[j + 1];
                words[j + 1] = words[j];
                words[j] = tmp;
            }
        }
    }
}