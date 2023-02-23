#include<stdio.h>

int main(){
 int a,b ;
 scanf("%d:%d",&a,&b);
 if(a>12 && a<24){
  printf("%d:%d PM",a-12,b);
 }
 else if(a<12 && a>=0){
  printf("%d:%d AM",a,b);
 }
 else if(a==12){
    printf("%d:%d AM",a,b);
 }
 else if(a==24){
    printf("%d:%d AM",a-24,b);
 }	
}