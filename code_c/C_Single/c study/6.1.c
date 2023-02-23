#include <stdio.h>

int main()
{
	int b,z,i,a,m;/*除数 商 循环 被除数 余数*/
    do{
        scanf("%d/%d",&a,&b);
    }while (10>=a && a>b && b>100);
    printf("0.");
    a*=10;
    m=a%b;
    for(i=0;i<200;i++){
        m=a%b;
        z=a/b;
        printf("%d",z);
        m*=10;
        a=m;
        if(m==0){
            break;
        }      
         
    }
    
	return 0;
}
