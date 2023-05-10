#include "reg52.h"

sbit LED=P2^7;

int main(){
	unsigned int cnt=0;
	
	TMOD=0X01;//设置特殊功能寄存器TMOD，配置好工作模式
	
	TH0=0xFC;
	TL0=0x6E;
	TR0=1;//启动(打开)定时器
    while(1){
			if(TF0==1){
				TF0=0;//计时清零
				TH0=0xFC;
				TL0=0x6E;//重新计时
				cnt++;
				if(cnt>=500){
				LED=~LED;}}
    }
}