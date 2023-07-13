#include "reg52.h"

sbit LED8=P2^7;
void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

int main(){

	LED8=0;	//LED8 open
	while(1){
		LED8=0;	//LED8 open
		Delay1000ms();
		LED8=1;	//LED8 close
		Delay1000ms();
	};
}