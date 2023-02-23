#include <stdio.h>

int main()
{
	int x;
    int mask=1;                  //位数 
    do{
	    scanf("%d",&x);
	}while(x>100000||x<-100000);  //范围
	if(x<0){
		printf("fu");
		x=-x;
	}
	int s=x;
	while (s>9)
	{
		s/=10;
		mask*=10;
	}
	int a;
	while(mask>0){
		a=x/mask;                         //用来分解x 
		x%=mask;                           
		mask/=10;
		switch (a){
			case 0:
				printf("ling");
				break;
			case 1:
				printf("yi");
				break;
			case 2:
				printf("er");
				break;
			case 3:
				printf("san");
				break;
			case 4:
				printf("si");
				break;
			case 5:
				printf("wu");
				break;
			case 6:
				printf("liu");
			    break;
			case 7:
				printf("qi");
				break;
			case 8:
				printf("ba");
				break;
			case 9:
				printf("jiu");
				break;
		}
	        if(mask>0){
			printf(" ");      
			}                  
	}

	
	return 0;
}