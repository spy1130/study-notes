#include <stdio.h>
int main()
{
	int l,p,h,m;
	scanf("%d%d",&l,&p);
	h=l/100;
	m=l%100;
	int mt =h*60 + m;
	int mtn =mt+p;
	l = mtn/60*100+mtn%60;
	printf("%d",l);
	return 0;
		
	 
} 
