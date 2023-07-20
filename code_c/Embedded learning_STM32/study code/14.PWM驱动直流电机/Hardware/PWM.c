#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	//RCC时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//TIM2是APB1的总线外设（时钟函数）
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//开启APB2外设时钟控制

	//重映射端口
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//开启AFIO
//	GPIO_PinRemapConfig(GPIO_PartialRemap1_TIM2,ENABLE);//设置复用端口
//	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE); //关闭默认复用调式端口JTID
	
	//GPIO
	GPIO_InitTypeDef GPIO_Initstructure;//结构体
	GPIO_Initstructure.GPIO_Mode =GPIO_Mode_AF_PP;//设置为复用推挽输出（使引脚控制权交给片上外设，PWM波形才能通过引脚输出）
	GPIO_Initstructure.GPIO_Pin =GPIO_Pin_2;
	GPIO_Initstructure.GPIO_Speed =GPIO_Speed_50MHz;	
	GPIO_Init(GPIOA,&GPIO_Initstructure);
	
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
	
	//TIM2配置
	TIM_InternalClockConfig(TIM2);//选择内部时钟驱动（一般默认，可以不写）
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;//指定时钟分频（输入滤波时，从内部时钟分频）
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;//计数器模式（向上计数）
	//1s一中断
	TIM_TimeBaseInitStruct.TIM_Period=100-1;//ARR自动重装器的周期
	TIM_TimeBaseInitStruct.TIM_Prescaler=36-1;//PSC预分频器的值
	TIM_TimeBaseInitStruct.TIM_RepetitionCounter=0;//重复计数器的值（高级计数器）
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
	
	//PWM配置
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);//给结构体赋初始值，防止bug
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;//设置输出比较模式
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;//设置输出比较极性（高）
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;//设置输出使能
	TIM_OCInitStructure.TIM_Pulse = 0;		//CCR（与ARR和PSC共同决定PWM占空比（50%），频率1KHz和分辨率）
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	
	//启用定时器
	TIM_Cmd(TIM2,ENABLE);
}

void PWM_SetCompare3(uint16_t Compare)
{
	TIM_SetCompare3(TIM2, Compare);
}
