#include <stdio.h>

int main()
{
  double cm;
  scanf("%lf",&cm);
  int foot = cm /30.48;
  double inch = (cm/30.48-foot)*12;
  printf("%d %f",foot,inch);
  return 0;
  	
}
