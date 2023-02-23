#include<stdio.h>
#include<math.h>
int main()
{
 double a,b,c,x1,x2;
 printf("please input a,b,c\n");
 scanf("%lf,%lf,%lf",&a,&b,&c);

 if(b*b-4*a*c<0)
 {
  printf("this function have no answer\n");
 }
 else
 {
  x1=(-b+sqrt(b*b-4*a*c))/2;
  x2=(-b-sqrt(b*b-4*a*c))/2;
  printf("x1:%.2lf,x2:%.2lf\n",x1,x2);
 }
 return 0;
}
