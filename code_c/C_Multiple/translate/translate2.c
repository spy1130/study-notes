#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _dict
{
    char *key;//可以对未知大小的单词储存，到时候开辟空间
    char *content;  
} DICT;
void dict_init(DICT **tmp)
{ // 为dict开辟空间,初始化
    DICT *p;
    p = malloc(sizeof(DICT) * 2);
    p[0].key =malloc(strlen("hello")+1);
    strcpy(p[0].key, "hello");//将“holle”存p[0].key指向的空间
    p[0].content =malloc(strlen("你好")+1);
    strcpy(p[0].content, "你好");
    p[0].key =malloc(strlen("world")+1);
    strcpy(p[1].key, "world");
    p[0].content =malloc(strlen("世界")+1);
    strcpy(p[1].content, "世界");

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
int main()
{
    DICT *dict = NULL;
    dict_init(&dict);
    char cmd[256] = "";     // 输入单词储存
    char content[256] = ""; // 输出中文储存
    int ret = 0;            // 判断search_dict（）是否找到翻译
    while (1)
    {
        printf("请输入需要翻译的单词：");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strlen(cmd) - 1] = 0;                 // 将最后一个字符去掉\n
        ret = search_dict(cmd, dict, 2, content); // 2个单词要找
        if (ret == 0)
        {
            printf("word not found\n");
        }
        else
        {
            printf("翻译为“%s\n", content);
        }
    }

    system("pause");
    return 0;
}