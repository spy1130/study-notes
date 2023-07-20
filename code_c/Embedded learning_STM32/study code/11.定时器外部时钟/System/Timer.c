#include "stm32f10x.h"                  // Device header

extern uint16_t Num;//提前声明，让编译器在别的文件自己找（main.c里的）

void Timer_Init(void)
{	//RCC时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//TIM2是APB1的总线外设（时钟函数）
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//开启APB2外设时钟控制
	
	//GPIO
	GPIO_InitTypeDef GPIO_Initstructure;//结构体高电平输入
	GPIO_Initstructure.GPIO_Mode =GPIO_Mode_IPU;//上拉输入
	GPIO_Initstructure.GPIO_Pin =GPIO_Pin_0;
	GPIO_Initstructure.GPIO_Speed =GPIO_Speed_50MHz;	
	GPIO_Init(GPIOB,&GPIO_Initstructure);
	
	//TIM2通用定时器配置
	TIM_ETRClockMode2Config(TIM2,TIM_ExtTRGPSC_OFF,TIM_ExtTRGPolarity_NonInverted,0x00);//配置外部时钟模式2
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;//指定时钟分频（输入滤波时，从内部时钟分频）
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;//计数器模式（向上计数）
	
	//1s一中断
	TIM_TimeBaseInitStruct.TIM_Period=10-1;//ARR自动重装器的周期
	TIM_TimeBaseInitStruct.TIM_Prescaler=1-1;//PSC预分频器的值
	
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter=0;//重复计数器的值（高级计数器）
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
	
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);//手动清除更新标志位，避免刚初始化就进中断
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);//开启使能中断（更新中断到NVIC的通路）
	
	//NVIC中断
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断分组 pre-emption priority and subpriority（先占（抢占）和从占（响应））
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn ;//TIM2在NVIC里的通道
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;//开启
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//指定抢占优先级（先）
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;//指定响应优先级（抢占优先级相等后）
	NVIC_Init(&NVIC_InitStructure);
	
	//启用定时器
	TIM_Cmd(TIM2,ENABLE);
}

uint16_t Timer_GetCounter(void)
{
	return TIM_GetCounter(TIM2);
}

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)== SET)//看一下TIM2的中断标志位是不是1(SET)
	{	
		Num++;
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);//将中断标志位清除（不清会卡在中断）
	}
}	
