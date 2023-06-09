#include <reg52.h>

unsigned char NixieTable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

//定义独立按键控制脚
sbit KEY1=P3^1;
sbit KEY2=P3^0;

void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--){
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
	}
}
void Nixie(unsigned char Location,Number)
{
	switch(Location)		
	{
		case 1:LSA=0;LSB=0;LSC=0;break;
		case 2:LSA=1;LSB=0;LSC=0;break;
		case 3:LSA=0;LSB=1;LSC=0;break;
		case 4:LSA=1;LSB=1;LSC=0;break;
		case 5:LSA=0;LSB=0;LSC=1;break;
		case 6:LSA=1;LSB=0;LSC=1;break;
		case 7:LSA=0;LSB=1;LSC=1;break;
		case 8:LSA=1;LSB=1;LSC=1;break;
	}
	P0=NixieTable[Number];	
	Delay(1);//稳定一下
	P0=0x00;//清零
}
//一键切换
void main()
{	
	
	while(1)
	{
		if(KEY1==0)			//如果K1按键按下
		{
			Delay(2);
			Nixie(8,2);
			Nixie(7,0);
			Nixie(6,0);;
			Nixie(5,3);
			Delay(2);
		}
		if(KEY2==0)			//如果K2按键按下
		{
			Delay(2);
			Nixie(4,1);;
			Nixie(3,1);
			Nixie(2,3);
			Nixie(1,0);
			Delay(2);
		}
}
}


