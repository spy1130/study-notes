#include "config.h"

//获取有效行数
int getFileLine(char * fileName)
{
	FILE * file = fopen(fileName, "r");
	if (file == NULL)
	{
		return -1 ;
	}

	char buf[1024] = { 0 };
	int lines = 0;
	while (fgets(buf, 1024, file) != NULL)
	{
		//如果是有效行 才统计
		if (isValidLine(buf))
		{
			lines++;
		}
		
	}
	fclose(file);

	return lines;
}

//判断当前行是否有效
int isValidLine(char * str)
{
	if (str[0] == ' ' || str[0] == '\0' ||  strchr(str,':') == NULL)
	{
		return 0; //无效数据 都返回假
	}
	return 1;
}


//解析文件
void parseFile(char * filePath, int lines, struct ConfigInfo **  configInfo)
{
	
	struct ConfigInfo  * info =  malloc(sizeof(struct ConfigInfo) * lines);

	if (info == NULL)
	{
		return;
	}

	FILE * file = fopen(filePath, "r");

	char buf[1024] = { 0 };
	int index = 0;
	while ( fgets(buf,1024,file ) != NULL)
	{
		//解析数据  有效数据才解析
		// heroName:aaaa\n
		if (isValidLine(buf))
		{
			memset(info[index].key, 0, 64);
			memset(info[index].value, 0, 64);

			char * pos = strchr(buf, ':'); //pos代表冒号所在位置

			strncpy(info[index].key, buf, pos - buf); //将key截取到 结构体中 最后-1的原因是不需要截取换行符
			strncpy(info[index].value, pos + 1, strlen(pos + 1) - 1);

			/*printf("key =  %s\n", info[index].key);
			printf("value =  %s", info[index].value);*/
			index++;

		}

		memset(buf, 0, 1024);

	}


	*configInfo = info;
}


//根据索引值 获取 实值 
char * getInfoByKey(char * key, struct ConfigInfo * configInfo, int line)
{
	for (int i = 0; i < line;i++)
	{
		if ( strcmp (key, configInfo[i].key  ) == 0)
		{
			return configInfo[i].value;
		}
	}
	return NULL;
}


//释放信息
void freeSpace(struct ConfigInfo * configInfo)
{
	if (configInfo != NULL)
	{
		free(configInfo);
		configInfo = NULL;
	}

}