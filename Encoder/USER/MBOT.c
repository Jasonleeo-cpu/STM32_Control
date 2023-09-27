#include "sys.h"

//====================�Լ������ͷ�ļ�===============================
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
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//����JTAG ���� SWD
	
	TIM3_Int_Init(5000,7199);     //=====��ʱ����ʼ�� 5msһ���ж�
	
	//MY_NVIC_PriorityGroupConfig(2);	//=====�����жϷ���
	
	delay_init();	    	        //=====��ʱ������ʼ��
	LED_Init();                     //=====LED��ʼ��    �����	
	
	usart3_init(9600);              //=====����3��ʼ��  ���� ���͵�����Ϣ

	Encoder_Init_TIM3();            //=====��ʼ��������1�ӿ�
	Encoder_Init_TIM4();            //=====��ʼ��������2�ӿ�
	

	
	while(1)
	{
		printf("L=%d,R=%d\r\n",leftSpeedNow,rightSpeedNow);
		delay_ms(15);
	} 
}

//5ms ��ʱ���жϷ�����

void TIM1_UP_IRQHandler(void)                            //TIM3�ж�
{
	if(TIM_GetITStatus(TIM1, TIM_IT_Update) != RESET) //���ָ����TIM�жϷ������:TIM �ж�Դ 
	{
		TIM_ClearITPendingBit(TIM1, TIM_IT_Update);   //���TIMx���жϴ�����λ:TIM �ж�Դ 
		
		Get_Motor_Speed(&leftSpeedNow,&rightSpeedNow);
		Led_Flash(100);
	}
}

