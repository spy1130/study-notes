#include<stdio.h>
int main(){
    int x,y,i;
    printf("input two number:");
    scanf("%d %d",&x,&y);
    if (x<y){
    i=y;y=x;x=i;
    }
    printf("%d %d",y,x);
    return 0;
}