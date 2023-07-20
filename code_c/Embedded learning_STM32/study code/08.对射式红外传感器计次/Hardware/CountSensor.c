#include "stm32f10x.h"                  // Device header

uint16_t CountSensor_Count;

void CountSensor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//开启APB2外设时钟控制
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//开启AFIO中断引脚选择器
	//EXIT边缘检测及控制不需要。NVIC是内核的外设，RCC管不到
	
	//GPIO
	GPIO_InitTypeDef GPIO_Initstructure;//结构体高电平输入
	GPIO_Initstructure.GPIO_Mode =GPIO_Mode_IPU;//上拉输入（）
	GPIO_Initstructure.GPIO_Pin =GPIO_Pin_14;
	GPIO_Initstructure.GPIO_Speed =GPIO_Speed_50MHz;	
	GPIO_Init(GPIOB,&GPIO_Initstructure);
	
	//AFIO
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);//外部中断引脚选择配置
	
	//EXTI
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line = EXTI_Line14;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;//开启
	EXTI_InitStructure.EXTI_Mode= EXTI_Mode_Interrupt;//中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发(移开时+1)
	EXTI_Init(&EXTI_InitStructure);
	
	//NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断分组 pre-emption priority and subpriority（先占（抢占）和从占（响应））
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=EXTI15_10_IRQn ;//10-15的合并通道
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//开启
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;//指定抢占优先级（先）
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;//指定响应优先级（抢占优先级相等后）
	NVIC_Init(&NVIC_InitStructure);
}

uint16_t CountSensor_Get(void)
{
	return CountSensor_Count;
}

void EXTI15_10_IRQHandler(void)//中断的名字已经取好了（自动执行，不需要申明）
{
	if(EXTI_GetITStatus(EXTI_Line14)== SET)//看一下EXTI14的中断标志位是不是1(SET)
	{	
		CountSensor_Count++;
		EXTI_ClearITPendingBit(EXTI_Line14);//将中断标志位清除（不清会卡在中断）
	}
}
