#include "reg52.h"

sbit LED = P2^0;
sbit LED1 = P2^1;

unsigned char T0RH, T0RL;
unsigned char T1RH, T1RL;

void Delay1ms()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}



// 1<=max<=71
void ConfigTime0(unsigned int ms)
{
	unsigned long temp;
	temp = 11059200 / 12; // 计数频率 65536
	temp = (temp * ms) / 1000;
	temp = 65536 - temp;			   // 初值
	T0RH = (unsigned char)(temp >> 8); // 保留高八位
	T0RL = (unsigned char)(temp);		   // 保留低八位
	ET0=1//1000 0010中断允许寄存器 IE=0x82  等效于 EA=1 ET0=1  ET0是开启在定时器溢出的时候就会进入中断
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
	T1RL = (unsigned char)(temp);		   // 保留低八位
	
	ET1=1; //打开T1中断
	PT1=1;//设置优先级1
	TMOD &= 0X0F;					   // 与操作符，把前面清0（0000 1111）1/0->0
	TMOD |= 0X10;					   // 设置特殊功能寄存器TMOD\T1，配置好工作模式
	IE=0x82 //1000 0010中断允许寄存器 等效于 EA=1 ET0=1  ET0是开启在定时器溢出的时候就会进入中断
	TH1 = T1RH;
	TL1 = T1RL;
	TF1 = 0; // 清除TF0标志
	TR1 = 1; // 启动(打开)定时器
}
int main()
{
	EA=1;
	ConfigTime0(10); // 延时时间10ms
	ConfigTime1(3); // 延时时间3ms
	while (1);
}

void InterruptTimer0() interrput 1//7次反转后持平1ms时间
{	
//	static unsigned int cnt=0; 静态变量
//	TF0 = 0;  计时清零，相应中断后硬件清0
	unsigned char i=7;
	TH0 = T0RH;
	TL0 = T0RL; // 重新计时
	
	while(i--){
	LED = !LED;
	Delay1ms();
	}
}
void InterruptTimer1() interrput 3//3ms反转一次
{	
	TH1 = T1RH;
	TL1 = T1RL; // 重新计时
	LED1 = !LED1;
}