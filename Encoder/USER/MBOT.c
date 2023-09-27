#include "sys.h"

//====================自己加入的头文件===============================
#include "delay.h"
#include "led.h"
#include "encoder.h"
#include "usart3.h"
#include "timer.h"
#include <stdio.h>
//===================================================================

int leftSpeedNow  =0;
int rightSpeedNow =0;

int main(void)
{ 

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//禁用JTAG 启用 SWD
	
	TIM3_Int_Init(5000,7199);     //=====定时器初始化 5ms一次中断
	
	//MY_NVIC_PriorityGroupConfig(2);	//=====设置中断分组
	
	delay_init();	    	        //=====延时函数初始化
	LED_Init();                     //=====LED初始化    程序灯	
	
	usart3_init(9600);              //=====串口3初始化  蓝牙 发送调试信息

	Encoder_Init_TIM3();            //=====初始化编码器1接口
	Encoder_Init_TIM4();            //=====初始化编码器2接口
	

	
	while(1)
	{
		printf("L=%d,R=%d\r\n",leftSpeedNow,rightSpeedNow);
		delay_ms(15);
	} 
}

//5ms 定时器中断服务函数

void TIM1_UP_IRQHandler(void)                            //TIM3中断
{
	if(TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET) //检查指定的TIM中断发生与否:TIM 中断源 
	{
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);   //清除TIMx的中断待处理位:TIM 中断源 
		
		Get_Motor_Speed(&leftSpeedNow,&rightSpeedNow);
		Led_Flash(100);
	}
}

