#include <stdio.h>
#include <string.h>
int main(){
    char string[200];
    int len;
    int i =0;
    char end ='.';
    do{
        scanf("%s",string);
        len = strlen(string);
        if (string[len-1]==end){
            printf("%d",len-1);
            i =1;
        }else{
            printf("%d ",len);
        }
    }while(i !=1);
    
    return 0;
}