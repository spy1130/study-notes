#include "reg52.h"

sbit LED = P2 ^ 0;
sbit LED2 = P2 ^ 1;

unsigned char T0RH, T0RL;
unsigned char T1RH, T1RL;

// 1<=max<=71
void ConfigTime0(unsigned int ms)
{
	unsigned long temp;
	temp = 11059200 / 12; // 计数频率 65536
	temp = (temp * ms) / 1000;
	temp = 65536 - temp;			   // 初值
	T0RH = (unsigned char)(temp >> 8); // 保留高八位
	T0RL = (unsigned char)(temp);	   // 保留低八位
	TMOD &= 0XF0;					   // 与操作符，把后面清0（1111 0000）1/0->0
	TMOD |= 0X01;					   // 设置特殊功能寄存器TMOD\T0，配置好工作模式,或操作符可以防止影响已设置的值 1/0->1

	TH0 = T0RH;
	TL0 = T0RL;
	TF0 = 0; // 清除TF0标志
	TR0 = 1; // 启动(打开)定时器
}
void ConfigTime1(unsigned int ms)
{
	unsigned long temp;
	temp = 11059200 / 12; // 计数频率 65536
	temp = (temp * ms) / 1000;
	temp = 65536 - temp;			   // 初值
	T1RH = (unsigned char)(temp >> 8); // 保留高八位
	T1RL = (unsigned char)(temp);	   // 保留低八位
	TMOD &= 0X0F;					   // 与操作符，把前面清0（0000 1111）1/0->0
	TMOD |= 0X10;					   // 设置特殊功能寄存器TMOD\T1，配置好工作模式

	TH1 = T1RH;
	TL1 = T1RL;
	TF1 = 0; // 清除TF1标志
	TR1 = 1; // 启动(打开)定时器
}
int main()
{
	unsigned int cnt0, cnt1;

	ConfigTime0(2); // 设定2ms时间
	ConfigTime1(4); // 设定4ms时间
	while (1)
	{ // 轮询模式
		// 判断T0，是否到了时间（溢出）
		if (TF0 == 1)
		{
			TF0 = 0; // 计时清零
			TH0 = T0RH;
			TL0 = T0RL; // 重新计时
			cnt0++;
			if (cnt0 >= 500)
			{
				cnt0 = 0;
				LED = !LED;
			}
		}
		// 判断T1，是否到了时间（溢出）
		if (TF1 == 1)
		{
			TF1 = 0; // 计时清零
			TH1 = T1RH;
			TL1 = T1RL; // 重新计时
			cnt1++;
			if (cnt1 >= 500)
			{
				cnt1 = 0;
				LED2 = !LED2;
			}
		}
	}
}