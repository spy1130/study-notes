#include<stdio.h>
int main(){
    int i;
    int sum = 0;
    int y, x = 1; // y表示余数，x为叠加的系数
    printf("Please input a number:");
    scanf("%d",&i);
    while (i){
        y = i % 2;
        sum += x * y;
        x *= 10;
        i /= 2;
    }
    printf("%d", sum);
    return 0;
}