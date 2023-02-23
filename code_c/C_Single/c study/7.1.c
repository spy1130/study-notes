#include <stdio.h>

int main() {
    int a,b,i,frist,number,z;//次幂，系数
    int x[100]={0,};
    number = 0;
    while (number <2)
    {
        scanf("%d %d",&a,&b);
        x[a] +=b;
        if(a==0){
           number++;
        }
    }
    frist = 1;
    z = 0;
    for(i=99;i>=0;i--){
        if(x[i] !=0){
            z =1;
            if(frist>1){
                if(x[i]>0)
                printf("+");
                
            }
            if(x[i] !=1 ||  i==0){
                printf("%d",x[i]);
            }
            if(i==1){
                printf("x");
            }
            if(i>1){
                printf("x%d",i);
            }
            frist++;
        }
    }
    if(!z)
        printf("0");
    return 0;
}