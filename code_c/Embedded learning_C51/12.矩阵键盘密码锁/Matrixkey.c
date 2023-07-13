#include "reg52.h"
#include "Delay.h"

/**
  * @brief 矩阵键盘读取按键键码
  * @param  无
  * @retval KeyNumber 按下按键的键码值
  */

unsigned char Matrixkey()
{
	unsigned char KeyNumber=0;
	
	P1=0xFF;
	P1^3=0;
	if(P1^7==0){Delay(20);while(P1^7==0);Delay(20);KeyNumber=1;}
	if(P1^6==0){Delay(20);while(P1^6==0);Delay(20);KeyNumber=5;}
	if(P1^5==0){Delay(20);while(P1^5==0);Delay(20);KeyNumber=9;}
	if(P1^4==0){Delay(20);while(P1^4==0);Delay(20);KeyNumber=13;}
	
	P1=0xFF;
	P1^2=0;
	if(P1^7==0){Delay(20);while(P1^7==0);Delay(20);KeyNumber=2;}
	if(P1^6==0){Delay(20);while(P1^6==0);Delay(20);KeyNumber=6;}
	if(P1^5==0){Delay(20);while(P1^5==0);Delay(20);KeyNumber=10;}
	if(P1^4==0){Delay(20);while(P1^4==0);Delay(20);KeyNumber=14;}
	
	P1=0xFF;
	P1^1=0;
	if(P1^7==0){Delay(20);while(P1^7==0);Delay(20);KeyNumber=3;}
	if(P1^6==0){Delay(20);while(P1^6==0);Delay(20);KeyNumber=7;}
	if(P1^5==0){Delay(20);while(P1^5==0);Delay(20);KeyNumber=11;}
	if(P1^4==0){Delay(20);while(P1^4==0);Delay(20);KeyNumber=15;}
	
	P1=0xFF;
	P1^0 = 0 ;
	if(P1^7==0){Delay(20);while(P1^7==0);Delay(20);KeyNumber=4;}
	if(P1^6==0){Delay(20);while(P1^6==0);Delay(20);KeyNumber=8;}
	if(P1^5==0){Delay(20);while(P1^5==0);Delay(20);KeyNumber=12;}
	if(P1^4==0){Delay(20);while(P1^4==0);Delay(20);KeyNumber=16;}
	
	return KeyNumber;
}
	