#include<stdio.h>
int main(){
    int x;
    printf("input x:");
    scanf("%d",&x);
    if(x<1){
        printf("y=%d",x);    
    }
    else
    {
       printf("y=%d",x*2+1);
    }
    return 0;
}