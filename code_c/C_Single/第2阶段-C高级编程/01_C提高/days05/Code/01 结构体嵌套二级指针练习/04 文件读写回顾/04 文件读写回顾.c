#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、字符的读写回顾 fgetc(), fputc()
void test01()
{
	//写文件
	FILE * f_write = fopen("./test1.txt", "w");

	if (f_write == NULL)
	{
		return;
	}


	char buf[] = "hello world";

	for (int i = 0; i < strlen(buf);i++)
	{
		fputc(buf[i], f_write);
	}

	fclose(f_write);

	//读文件
	FILE * f_read = fopen("./test1.txt", "r");
	if (f_read == NULL)
	{
		return;
	}

	char ch;

	while (  (ch = fgetc(f_read)) != EOF) // EOF  END  OF  FILE
	{
		printf("%c", ch);
	}

	fclose(f_read);
}



//2、按行进行读写
void test02()
{
	//写文件
	FILE * f_write = fopen("./test2.txt", "w+");

	if (f_write == NULL)
	{
		return;
	}

	char * buf[]=
	{
		"锄禾日当午\n",
		"汗滴禾下土\n",
		"谁知盘中餐\n",
		"粒粒皆辛苦\n"
	};

	for (int i = 0; i < 4;i++)
	{
		fputs(buf[i], f_write);
	}

	fclose(f_write);


	//读文件
	FILE * f_read = fopen("./test2.txt", "r");
	if (f_read == NULL)
	{
		return;
	}
	while ( !feof(f_read))
	{
		char temp[1024] = { 0 };

		fgets(temp, 1024, f_read);

		printf("%s", temp);

	}

	fclose(f_read);

}


//3、按块进行读写

struct Hero
{
	char name[64];
	int age;
};
void test03()
{
	//写文件
	FILE * f_wirte = fopen("./test3.txt", "wb"); 
	if (f_wirte == NULL)
	{
		return;
	}

	struct Hero heros[] = 
	{
		{ "孙悟空", 999 },
		{ "亚瑟", 20 },
		{ "曹操", 80 },
		{ "鲁班", 5 },
	};

	for (int i = 0; i < 4;i++)
	{
		//参数1 数据地址   参数2  块大小   参数3  块个数   参数4  文件指针
		fwrite(&heros[i], sizeof(struct Hero), 1, f_wirte);
	}

	fclose(f_wirte);


	//读文件
	FILE * f_read = fopen("./test3.txt", "rb");

	if (f_read == NULL)
	{
		return;
	}

	struct Hero temp[4];
	fread(&temp, sizeof(struct Hero), 4, f_read);
	for (int i = 0; i < 4;i++)
	{
		printf("姓名： %s  年龄：%d\n", temp[i].name, temp[i].age);
	}

	fclose(f_read);

}

//4、格式化读写回顾
void test04()
{
	
	//写文件
	FILE *f_write = fopen("./test4.txt", "w");
	if (f_write == NULL)
	{
		return;
	}

	fprintf(f_write, "hello world %s", "abcd");

	fclose(f_write);


	//读文件
	FILE * f_read = fopen("./test4.txt", "r");
	if (f_read == NULL)
	{
		return;
	}
	char temp[1204] = { 0 };
	while (! feof(f_read ))
	{
		fscanf(f_read, "%s", temp);
		printf("%s\n", temp);
	}

	fclose(f_read);
}

void test05()
{
	//写文件
	FILE * f_wirte = fopen("./test5.txt", "wb");
	if (f_wirte == NULL)
	{
		return;
	}

	struct Hero heros[] =
	{
		{ "孙悟空", 999 },
		{ "亚瑟", 20 },
		{ "曹操", 80 },
		{ "鲁班", 5 },
	};

	for (int i = 0; i < 4; i++)
	{
		//参数1 数据地址   参数2  块大小   参数3  块个数   参数4  文件指针
		fwrite(&heros[i], sizeof(struct Hero), 1, f_wirte);
	}

	fclose(f_wirte);


	//读文件
	FILE * f_read = fopen("./test51.txt", "rb");
	if (f_read == NULL)
	{
		//error 宏
		//printf("文件加载失败\n");
		perror("文件加载失败"); //用户提示信息 + 系统提示信息

		return;
	}
	struct Hero tempHero;
	//移动光标
	// 参数1  文件指针   参数2 偏移大小    参数3  起始位置   
	// SEEK_SET 从开始  SEEK_END 从结尾   SEEK_CUR 从当前位置
	//fseek(f_read, sizeof(struct Hero) * 2, SEEK_SET);

	fseek(f_read, - (long)sizeof(struct Hero) * 2, SEEK_END);

	rewind(f_read); //将文件光标置首

	fread(&tempHero, sizeof(struct Hero), 1, f_read);

	printf(" 姓名： %s , 年龄： %d\n", tempHero.name, tempHero.age);


	fclose(f_read);
}


int main(){
	//test01();
	//test02();
	//test03();
	//test04();
	test05();


	system("pause");
	return EXIT_SUCCESS;
}