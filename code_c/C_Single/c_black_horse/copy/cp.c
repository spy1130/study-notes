#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    //打开文件
    FILE *fp=fopen("./1.txt","r");
    if(NULL==fp){
        perror("");
        return -1;
    }
    FILE *det = fopen("2.txt","w");
    if(NULL==det){
        perror("");
        return -1;
    }
    char ch = 0;
    while (1)
    {
        ch =fgetc(fp);
        if(feof(fp))
            break;
        fputc(ch,det);
    }
    fclose(fp);
    fclose(det);
    return 0;
}