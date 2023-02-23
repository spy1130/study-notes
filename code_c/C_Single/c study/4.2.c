#include <stdio.h>

int main()
{
    int i=1;
    int r=1;
    int tenf=0;
    int input=0,numloc=0;
    int digit;
    scanf("%d",&input);
    while (input>0)
    {
        digit = input%10;
        numloc++;
        if(numloc%2 == digit%2)
        {
            r =1;
            while (i++<= numloc-1)
            {
                r *=2;
            }
            i =1;
            tenf+=r;
        }
            
        input /=10;
    }
    printf("%d",tenf);
	return 0;
}