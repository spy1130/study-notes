#include "stm32f10x.h"                  // Device header
#include "Delay.h"


int main(void)
{	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//开启APB2外设时钟控制
	
	GPIO_InitTypeDef GPIO_Initstructure;//结构体
	GPIO_Initstructure.GPIO_Mode =GPIO_Mode_Out_PP;
	GPIO_Initstructure.GPIO_Pin =GPIO_Pin_All;//GPIO_Pin_0 | GPIO_Pin_1 | ...这里可以用按位或写法相当于都选上
	GPIO_Initstructure.GPIO_Speed =GPIO_Speed_50MHz;	
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	
	
	while(1)
	{	
		GPIO_Write(GPIOA,~0X0001);//0000 0000 0000 0001,低电平点亮，按位取反
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0002);//0000 0000 0000 0010,低电平点亮，按位取反
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0004);//0000 0000 0000 0100,低电平点亮，按位取反
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0008);//0000 0000 0000 1000,低电平点亮，按位取反
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0010);//0000 0000 0001 0000,低电平点亮，按位取反
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0020);//0000 0000 0010 0000,低电平点亮，按位取反
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0040);//0000 0000 0100 0000,低电平点亮，按位取反
		Delay_ms(100);
		GPIO_Write(GPIOA,~0X0080);//0000 0000 1000 0000,低电平点亮，按位取反
		Delay_ms(100);
	}
}
