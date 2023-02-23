#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct ConfigInfo
{
	char key[64]; //索引值
	char value[64]; //实值
};


//获取有效行数
int getFileLine( char * fileName );

//判断当前行是否有效
int isValidLine(char * str);

//解析文件
void parseFile(char * filePath, int lines, struct ConfigInfo **  configInfo);

//根据索引值 获取 实值 
char * getInfoByKey(char * key, struct ConfigInfo * configInfo, int line);

//释放信息
void freeSpace(struct ConfigInfo * configInfo);
