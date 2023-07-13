#include <reg52.h>


void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
int main(){
	unsigned char i=0;
    while(1){
				P2=~i;
				i++;
				Delay500ms();
    }
}