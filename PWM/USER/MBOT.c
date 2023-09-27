#include "sys.h"

//====================自己加入的头文件===============================
#include "delay.h"
#include "led.h"
#include "pwm.h"
#include "motor.h"
#include <stdio.h>
//===================================================================

int main(void)
{ 

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//禁用JTAG 启用 SWD
	
	MY_NVIC_PriorityGroupConfig(2);	//=====设置中断分组
	
	delay_init();	    	        //=====延时函数初始化
	LED_Init();                     //=====LED初始化    程序灯
	
	Motor_Init(999,0);             //=====初始化PWM 10KHZ，用于驱动电机 如需初始化驱动器接口
	
	while(1)
	{
		Set_Pwm(1000,-1000);
		Led_Flash(30);
		delay_ms(15);
	} 
}


