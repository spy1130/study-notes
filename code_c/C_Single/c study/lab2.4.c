#include "stdio.h"
int a[]={21,65,37,1,12,5,}; 
int i, j, temp; 
int len =sizeof(a)/sizeof(a[1]);
void up(){
    for (i = 0; i <len-1 ; i++) 
      { 
            for (j = 0; j < len-1- i; j++) {
            if (a[j] > a[j+1]) 
            { 
                  temp = a[j]; 
                  a[j] = a[j+1]; 
                  a[j+1] = temp; 
            } }
        for (int m = 0; m < len; m++) 
            printf("%d%c",a[m]," \n"[m==len-1]);
      } 
}
void down(){
    for (i = 0; i <len-1 ; i++) 
      { 
            for (j = 0; j < len-1- i; j++) {
            if (a[j] < a[j+1]) 
            { 
                  temp = a[j]; 
                  a[j] = a[j+1]; 
                  a[j+1] = temp; 
            } }
        for (int m = 0; m < len; m++) 
            printf("%d%c",a[m]," \n"[m==len-1]);
}
}
int main()
{ 
    int s;
    printf("Please input 1 or 0(1 is up and 0 is down):");
    scanf("%d",&s);
    if (s){
        up();
    }else{
        down();
    } 
    return 0; 
}