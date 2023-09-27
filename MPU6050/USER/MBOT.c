#include "sys.h"

//====================�Լ������ͷ�ļ�===============================
#include "delay.h"
#include "led.h"
#include "usart3.h"

#include "ioi2c.h"
#include "mpu6050.h"

#include "control.h"
#include "myexti.h"
#include <stdio.h>
//===================================================================

/*===================================================================
�����ܣ�MPU6050 DMP���ݶ�ȡ
�����д�����ںţ�С��ѧ�ƶ�������
����    ������Դ������κ����ʣ�����˽��С�࣬һ����ظ��ġ�
=====================================================================
------------------��ע���ںţ���ø�����Ȥ�ķ���---------------------
===================================================================*/

int main(void)
{ 

	GPIO_PinRemapConfig(GPIO_Remap_SWJ_Disable,ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);//����JTAG ���� SWD
	
	//MY_NVIC_PriorityGroupConfig(2);	//=====�����жϷ���
	
	delay_init();	    	        //=====��ʱ������ʼ��
	LED_Init();                     //=====LED��ʼ��    �����
	usart3_init(9600);              //=====����3��ʼ��  ����

  IIC_Init();                     //=====IIC��ʼ��    ��ȡMPU6050����
	MPU6050_initialize();           //=====MPU6050��ʼ��	
	DMP_Init();                     //=====��ʼ��DMP 
	
	MBOT_EXTI_Init();               //=====MPU6050 5ms��ʱ�жϳ�ʼ��
	
	
	while(1)
	{
		getAngle(&yaw,&yaw_acc_error);  
		
		printf("%d\r\n",(int)yaw);
	} 
}


