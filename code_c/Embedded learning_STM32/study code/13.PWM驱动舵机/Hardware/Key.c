#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//开启APB2外设时钟控制
	
	GPIO_InitTypeDef GPIO_Initstructure;//结构体
	GPIO_Initstructure.GPIO_Mode =GPIO_Mode_IPU;
	GPIO_Initstructure.GPIO_Pin =GPIO_Pin_1 ;
	GPIO_Initstructure.GPIO_Speed =GPIO_Speed_50MHz;	
	GPIO_Init(GPIOB,&GPIO_Initstructure);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0)//返回输入寄存器某一位的值，0低，1高
	{//按下按键
		Delay_ms(20);//消抖
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) == 0);
		Delay_ms(20);//消抖
		KeyNum =1;
	}
	return KeyNum;
}
