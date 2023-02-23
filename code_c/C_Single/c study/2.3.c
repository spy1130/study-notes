#include<stdio.h>
int main(){
	int number;
	scanf("%d",&number);
	int x=number%100%10;
	int y=number/100;
	int z=number%100/10;
	number =x*100+z*10+y;
	printf("%d",number);
	return 0;
}
