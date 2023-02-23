#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#define FLIRNAME "./dict.txt"
typedef struct _dict
{
    char *key; // 可以对未知大小的单词储存，到时候开辟空间
    char *content;
} DICT;
FILE *open_file()
{
    FILE *fp = fopen(FLIRNAME, "r");
    if (fp == NULL)
    {
        perror("");
        return NULL;
    }
    return fp;
}
void filter_buf(char *buf)
{
    int end = strlen(buf) - 1; // 最后一个字符下标
    while (buf[end] == ' ' || buf[end] == '\n' || buf[end] == '\t' || buf[end] == '\r')
        end--;
    buf[end + 1] = 0;
}
void dict_init(DICT **tmp, int line)
{ // 为dict开辟空间,初始化
    DICT *p;
    p = malloc(sizeof(DICT) * line); // 针对此dict.txt
    char *q = NULL;
    char buf[256] = "";
    int i = 0;
    FILE *fp = open_file(); // 打开文件dict.txt
    while (1)
    {
        q = fgets(buf, sizeof(buf), fp); // 获取一行
        if (q == NULL)
            break;
        filter_buf(buf);                    // 过滤掉/r/n/t空格
        p[i].key = malloc(strlen(buf) + 1); /// 给存储单词开辟空间
        strcpy(p[i].key, buf + 1);          //(buf+1)跳过#号
        q = fgets(buf, sizeof(buf), fp);
        if (q == NULL)
            break;
        filter_buf(buf); // 过滤掉/r/n/t空格
        p[i].content = malloc(strlen(buf) + 1);
        strcpy(p[i].content, buf + 6); //(buf+6)跳过"Trans:"
        i++;
    }
    fclose(fp);
    *tmp = p; // 用p操纵空间比用**tmp操作空间简单
}
int search_dict(char *cmd, DICT *dict, int n, char *content)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(cmd, dict[i].key) == 0)
        {
            strcpy(content, dict[i].content);
            return 1;
        }
    }
    return 0;
}
int get_file_line()
{
    char *q = NULL;
    char buf[256] = "";
    int i = 0;
    FILE *fp = open_file(); // 打开文件dict.txt
    while (1)
    {
        q = fgets(buf, sizeof(buf), fp); // 获取一行
        if (q == NULL)
            break;
        q = fgets(buf, sizeof(buf), fp);
        if (q == NULL)
            break;
        i++;
    }
    fclose(fp);
    return i;
}
int main()
{
    DICT *dict = NULL;
    int line = 0;
    line = get_file_line(); // 获取文件行数，看有多少个单词
    dict_init(&dict, line);
    char cmd[256] = "";               // 输入单词储存
    char content[256] = "";           // 输出中文储存
    int ret = 0;                      // 判断search_dict（）是否找到翻译
    LARGE_INTEGER lpPerformanceCount; // 测时间用的
    QueryPerformanceFrequency(&lpPerformanceCount);
    int c1, c2;
    while (1)
    {
        printf("请输入需要翻译的单词：");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strlen(cmd) - 1] = 0;                     //"/0" 将最后一个字符去掉\n
        QueryPerformanceCounter(&lpPerformanceCount); // 获得当前时间，单位是微秒
        c1 = lpPerformanceCount.QuadPart;
        ret = search_dict(cmd, dict, line, content); // line个单词要找
        if (ret == 0)
        {
            printf("word not found\n");
        }
        else
        {
            printf("翻译为“%s\n", content);
        }
        QueryPerformanceCounter(&lpPerformanceCount);
        c2 = lpPerformanceCount.QuadPart;
        printf("用时%d us\n", c2 - c1);
    }
    system("pause");
    return 0;
}