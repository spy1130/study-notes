#include "reg52.h"

sbit LED = P2^0;

unsigned char T0RH, T0RL;

// 1<=max<=71
void ConfigTime0(unsigned int ms)
{
	unsigned long temp;
	temp = 11059200 / 12; // 计数频率 65536
	temp = (temp * ms) / 1000;
	temp = 65536 - temp;			   // 初值
	T0RH = (unsigned char)(temp >> 8); // 保留高八位
	T0RL = (unsigned char)(temp);		   // 保留低八位

	TMOD = 0X01; // 设置特殊功能寄存器TMOD，配置好工作模式

	TH0 = T0RH;
	TL0 = T0RL;
	TF0 = 0; // 清除TF0标志
	TR0 = 1; // 启动(打开)定时器
}
int main()
{

	ConfigTime0(10000); // 延时时间
	while (1)
	{
		if (TF0 == 1)
		{
			TF0 = 0; // 计时清零
			TH0 = T0RH;
			TL0 = T0RL; // 重新计时
			LED = !LED;
		}
	}
}
