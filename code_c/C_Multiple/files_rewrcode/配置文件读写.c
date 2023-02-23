#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "config.h"
#include "code.h"

struct Person
{
	char a;
	int b;
};

int main()
{
	srand((unsigned int)time(NULL));

	char *filePath = "./config.txt";

	int line = getFileLine(filePath);

	printf("文件的有效行数为：%d\n", line);

	struct ConfigInfo *pArray = NULL;

	parseFile(filePath, line, &pArray);

	// 测试 根据key 访问value
	printf("heroId = %s\n", getInfoByKey("heroId", pArray, line));
	printf("heroName = %s\n", getInfoByKey("heroName", pArray, line));
	printf("heroAtk = %s\n", getInfoByKey("heroAtk", pArray, line));
	printf("heroDef = %s\n", getInfoByKey("heroDef", pArray, line));
	printf("heroInfo = %s\n", getInfoByKey("heroInfo", pArray, line));

	// 文件加密
	codeFile("config.txt", "configCode.txt");

	// #  35  转为 short
	// 0000 0000 0010 0011   << 4
	// 0000 0010 0011 0000
	// 1000 0000 0000 0000    |

	// 1000 0010 0011 0000  + 0000 ~ 1111 随机数  rand()%16     0~ 15
	// 1000 0010 0011 1010

	// 解密
	decodeFile("configCode.txt", "deConfig.txt");
	// 1000 0010 0011 1010  <<1
	// 000  0010 0011 10100  >> 5
	// 0000 0000  0010 0011

	// 释放内存
	freeSpace(pArray);
	pArray = NULL;

	system("pause");
	return EXIT_SUCCESS;
}