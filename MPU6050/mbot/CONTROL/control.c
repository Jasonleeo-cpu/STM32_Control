#include "control.h"	
#include "led.h"

float yaw              =0;           //ת��������
float yaw_acc_error    =0;           //yaw�ۻ����
#define FIVE_MS_ERROR   0.00002115   //yawÿ5ms������Ư�ƵĶ���������������ԣ�����������Сʱƫ1�ȣ�ÿ���˵����ֵ����������ͬ���������м���

/**************************************************************************
�������ܣ����еĿ��ƴ��붼��������
          5ms��ʱ�ж���MPU6050��INT���Ŵ���		
**************************************************************************/
void EXTI15_10_IRQHandler(void) 
{                                                         
	EXTI_ClearITPendingBit(EXTI_Line12);                            //===���LINE12��·����λ
	
	yaw_acc_error += FIVE_MS_ERROR;								    //===yawƯ������ۼ�
	
	Led_Flash(200);                                                 //===LED��˸��֤��������������	
		
} 







