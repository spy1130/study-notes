#include "reg52.h"
#include "intrins.h"
void Delay100us(unsigned int us);
void Hz(unsigned int hz);
sbit BUZZ=P2^5;

void main(){
	while(1)
	{
		BUZZ=1;
		Hz(5000);
		BUZZ=0;
		Hz(5000);
	}
}

void Hz(unsigned int hz)
{
	unsigned char i;
	i=10000/hz/2;
	Delay100us(2);
}

void Delay100us(unsigned int  us)		//@11.0592MHz
{
	unsigned char i;
	while(us--)
		{
	_nop_();
	i = 43;
	while (--i);
	}
}
