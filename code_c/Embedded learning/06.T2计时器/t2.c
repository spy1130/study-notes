#include "reg52.h"

sbit LED = P2 ^ 0;

unsigned char T2RH, T2RL;


// 1<=max<=277us
void ConfigTime0Mode2(unsigned int us)
{
	unsigned long temp;
	if(us>277) us=277;
	temp = 11059200 / 12; // 计数频率 65536
	temp = (temp * us) / 1000000;
	temp = 256 - temp;			   // 初值
	TH0 = temp;
	TL0 = temp;//8位自动重装模式
	TMOD &= 0XF0;					   // 与操作符，把后面清0（1111 0000）1/0->0
	TMOD |= 0X02;					   // 设置特殊功能寄存器TMOD\模式2，配置好工作模式,或操作符可以防止影响已设置的值 1/0->1

	
	TF0 = 0; // 清除TF0标志
	TR0 = 1; // 启动(打开)定时器
}

int main()
{
	unsigned int cnt0;

	ConfigTime0Mode2(2000); // 设定2000us时间
	while (1)
	{ // 判断T0，是否到了时间（溢出）
		if (TF0 == 1)
		{
			cnt0++;
			if (cnt0 >= 5000)
			{
				cnt0 = 0;
				LED = !LED;
			}
			TF0 = 0; // 计时清零
		}
		
		}
	}
