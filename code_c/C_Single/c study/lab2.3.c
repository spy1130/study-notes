#include<stdio.h>
int main(){
    int n;
    printf("input n:");
    scanf("%d",&n);
    if (n%3==0 && n%5==0){
        printf("TRUE");
    }
    else{
        printf("FALSE");
    }
    return 0;
}