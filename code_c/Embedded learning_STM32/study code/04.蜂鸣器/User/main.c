#include "stm32f10x.h"                  // Device header
#include "Delay.h"


int main(void)
{	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//开启APB2外设时钟控制
	
	GPIO_InitTypeDef GPIO_Initstructure;//结构体
	GPIO_Initstructure.GPIO_Mode =GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin =GPIO_Pin_12;
	GPIO_Initstructure.GPIO_Speed =GPIO_Speed_50MHz;	
	GPIO_Init(GPIOB,&GPIO_Initstructure);
	
	
	while(1)
	{	
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(100);
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(100);
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(100);
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(700);
	}
}
