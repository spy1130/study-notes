#include "reg52.h"

sbit LED =P2^0;
sbit LED1=P2^1;

unsigned char T3RH, T3RL;


// 1<=max<=277us
void ConfigTime0Mode3(unsigned int usl,unsigned int ush)
{
	unsigned long temp;
	if(usl>277) usl=277;
	if(ush>277) ush=277;
	
	//配置第一个定时器
	temp = 11059200 / 12; // 计数频率 65536
	temp = (temp * usl) / 1000000;
	temp = 256 - temp;			   // 初值
	T3RL = temp;
	
	//配置第二个定时器
	temp = 11059200 / 12; // 计数频率 65536
	temp = (temp * ush) / 1000000;
	temp = 256 - temp;			   // 初值
	T3RH = temp;
	
	TMOD &= 0XF0;					   // 与操作符，把后面清0（1111 0000）1/0->0
	TMOD |= 0X03;					   // 设置特殊功能寄存器TMOD\模式3，配置好工作模式,或操作符可以防止影响已设置的值 1/0->1
	
	TL0=T3RL;
	TH0=T3RH;
	
	TF0 = 0; // 清除TF0标志
	TR0 = 1; // 启动(打开)第一个有关TL0的定时器
	TR1 = 1; // 启动(打开)第二个有关TH0的定时器
}

int main()
{
	unsigned int cntL,cntH;

	ConfigTime0Mode3(2000,1000); // 设定2000us时间
	while (1)
	{ // 第一个计时器是否溢出
		if (TF0 == 1)
		{
			cntL++;
			if (cntL >= 5000)
			{
				cntL = 0;
				LED = !LED;
			}
			TF0 = 0; // 计时清零
			TL0=T3RL;
		}
		// 第二个计时器是否溢出
		if (TF1 == 1)
		{
			cntH++;
			if (cntH >= 5000)
			{
				cntH = 0;
				LED1 = !LED1;
			}
			TF1 = 0; // 计时清零
			TL0=T3RH;
		}
		
		}
	}
