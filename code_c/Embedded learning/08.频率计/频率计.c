#include <reg52.h>


unsigned char T0RH,T0RL;



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

void main()
{	
	EA=1;
	P1=0X0E;
	
	ConfigTimer0(1);	//设定1ms
	

	while(1)
	{

	}
}

//T0定时器中断函数
void InterruptTimer0() interrupt 1
{	
	static unsigned int cnt=0;

	TH0=T0RH;
	TL0=T0RL;

	cnt++;
	if(cnt>=500)
	{
		cnt=0;
	}
}
