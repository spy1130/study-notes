#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void myPrint(void * data,void(*mp)(void*)){
    mp(data);
}
void printInt(void *data){
    int * num =data;
    printf("%d\n",*num);
}
int main(){
    int a =10;
    myPrint(&a,printInt);
    system("pause");
    return 0;
}