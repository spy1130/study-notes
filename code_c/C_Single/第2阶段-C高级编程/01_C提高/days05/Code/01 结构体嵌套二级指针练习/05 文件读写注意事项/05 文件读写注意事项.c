#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
	FILE * file = fopen("./test.txt", "r");

	if (file == NULL)
	{
		return;
	}

#if 0
	char ch;
	while ( !feof (file))
	{
		ch = fgetc(file);

		//滞后性
		if (feof(file))
		{
			break;
		}

		printf("%c", ch);
	}
#endif


	char ch;

	while ((ch = fgetc(file)) != EOF)
	{
		printf("%c", ch);
	}

	fclose(file);
}


//注意事项2
struct Person
{
	char * name; //不要将指针 写入到文件中
	int age;
};


int main(){
	test01();

	//printf("%c",EOF);
	
	system("pause");
	return EXIT_SUCCESS;
}