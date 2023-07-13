#include "reg52.h"
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
			KeyNum=Matrixkey();
			if(KeyNum)
			{
				LCD_ShowNum(2,1,KeyNum,2);
			}
	}
}