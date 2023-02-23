#include<stdio.h>

int main(){
	int i ;
    int two =0 ;
    int single =0;
    scanf("%d",&i);
    if(i<0 || i>1000000){
        printf("你的数未在(0,1000000)之间请重新输入");

    }
    else{
        while(i !=-1){
            if(i%2 ==0){
                two++;
            }
            else{
                single++;
            }
            scanf("%d",&i);
        }
    }
    printf("%d %d",single,two);
    return 0;
}