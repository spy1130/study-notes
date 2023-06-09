#include <reg52.h>

sbit Wave=P3^3;
unsigned char T0RH,T0RL;
unsigned int count=0;
bit flag1s=0;//标志位，和int char类型一样，只有1和0



//1<=max<=71
void ConfigTimer0(unsigned char ms)
{
	unsigned long tmp;
	
	tmp=11059200/12;		//计数频率
	tmp=(tmp*ms)/1000;
	tmp=65536-tmp;			//初值
	T0RH=(unsigned char)(tmp>>8);
	T0RL=(unsigned char)(tmp);
	
	ET0=1;
	TMOD=0x01;	//配置工作模式
	TH0=T0RH;	//设置定时时间
	TL0=T0RL;
	TR0=1;		//启动定时器
}
void ConfigINT0(void)
{
	IT0=1; //下降沿触发
	EX0=1;
	
}

void main()
{	
	EA=1;
	P1=0x0E; //选中8个LED
	ConfigTimer0(10);	//设定10ms
	ConfigINT0();
	

	while(1)
	{		
		
//			if(tmp!=Wave){
//				count++;
//				tmp=Wave;//更新状态
//			}
//			if(flag1s)
//			{
//				//count=1000  =0000 0011 1110 1000
//			count/=2; 波形上下会计两次
//				count>>=4;  0000 0000 0011 1110 变成8位可读
//				P0=(count>>4);
//				count=0
//			}
	}
}

//T0定时器中断函数
void InterruptTimer0() interrupt 1
{	
	static unsigned int cnt=0;

	TH0=T0RH;
	TL0=T0RL;

	cnt++;
	if(cnt>=100)
	{
		cnt=0;
		P0=(count>>4); 
		count=0;
	}
}
//当出现下降沿的时候单片机自动跳转此中断函数
void InterruptINT0() interrupt 0
{
	count++;
}