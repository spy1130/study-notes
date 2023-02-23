#include <stdio.h>
int main(){
    int SD=0,SS=0,i=0;
    while (i<100)
    {
        i+=1;
        if (i%2==0){
            SD+=i;
        }
        else{
            SS+=i;
        }
    }
    printf("%d,%d",SD,SS);
    return 0;
}