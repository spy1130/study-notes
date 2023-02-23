#include <stdio.h>

int main()
{
	int A;
	int B;
	scanf("%d %d",&A,&B);
	int X =A+B;
	int Y =A-B;
	int W =A*B;
	int Z =A/B;
	printf("%d + %d = %d\n",A,B,X);
	printf("%d - %d = %d\n",A,B,Y);
	printf("%d * %d = %d\n",A,B,W);
	printf("%d / %d = %d\n",A,B,Z);
	
	return 0;
}
