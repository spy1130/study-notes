#include <stdio.h>
#include <stdlib.h> //srand(),  rand()
#include <time.h>	//time()
int main()
{
	srand((unsigned)time(NULL));
	int answer = rand() % 10;
	int gus = 0;
	do
	{
		printf("请输入你猜的数：");
		scanf("%d", &gus);
		if (answer > gus)
		{
			printf("小了小了\n");
		}
		else if (answer < gus)
		{
			printf("大了大了\n");
		}
		else
		{
			printf("恭喜你答对了");
			break;
		}
	} while (gus >= 0 && gus <= 9);
	system("pause");
	return 0;
}