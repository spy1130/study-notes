#include <reg52.h>


unsigned char T0RH,T0RL;
unsigned long count=0; //记录单位时间内总脉冲数
unsigned long spill=0 //记录溢出次数
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
	TMOD &= 0xF0;
	Tmod |= 0x01;
	TMOD=0x01;	//配置工作模式
	TH0=T0RH;	//设置定时时间
	TL0=T0RL;
	TR0=1;		//启动定时器
}

void Configcount1(void)
{	
	ET1=1; //保证溢出后产生中断
	TMOD &= 0xF0;
	TMOD |= 0x50;
	TH1=0;
	TL1=0；
	TR1=1;		//启动计数器
}

void main()
{	
	EA=1;
	P1=0x0E; //选中8个LED
	ConfigTimer0(10);	//设定10ms
	Configcount1();
	while(1)
	{		

	}
}

//T0定时器中断函数
void InterruptTimer0() interrupt 1
{	
	static unsigned int cnt=0;
	unsigned int tmp=0;
	
	TH0=T0RH;
	TL0=T0RL;

	cnt++;
	if(cnt>=100)
	{
		cnt=0;
		count=spill*65535;
		tmp=(TH1<<8)|TL1 //多余的
		count+=tmp; //最终的溢出次数
		TH1=0;
	  TL1=0；
		spill=0;
		P0=(count>>4); 
	}
}
void InterruptCount1() interrupt 3
{
	//计数到65535
	spill++;
}