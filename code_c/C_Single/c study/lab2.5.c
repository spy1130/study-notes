#include "stdio.h"
int a[]={21,47,24,3,11,9,}; 
int i, j, temp,index; 
int len =sizeof(a)/sizeof(a[1]);
void up(){
    for(i = 0; i < len-1; i++){
            index=i;
        for(j = i + 1;j < len; j++){ 
            if(a[index]>a[j]) 
                index=j;        
        }
        if(index !=i)    
        {
            temp=a[i];
            a[i]=a[index];
            a[index]= temp; 
        }
        for (int m = 0; m < len; m++) 
            printf("%d%c",a[m]," \n"[m==len-1]);
    }
} 
void down(){
    for(i = 0; i < len-1; i++){
            index=i;
        for(j = i + 1;j < len; j++){ 
            if(a[index]<a[j]) 
                index=j;        
        }
        if(index !=i)    
        {
            temp=a[i];
            a[i]=a[index];
            a[index]= temp; 
        }

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