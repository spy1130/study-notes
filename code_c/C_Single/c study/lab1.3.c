#include<stdio.h>
int main(){
    char i;
    printf("Please enter lowercase letters:");
    scanf("%c",&i);
    printf("Uppercase letters is %c",i-32);
    return 0;
}