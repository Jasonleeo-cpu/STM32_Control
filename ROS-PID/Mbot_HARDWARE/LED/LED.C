#include "led.h"

/*===================================================================
�����ܣ�LED��ʼ�����Լ�LED��˸����
�����д�����ںţ�С��ѧ�ƶ�������
����    ������Դ������κ����ʣ�����˽��С�࣬һ����ظ��ġ�
=====================================================================
------------------��ע���ںţ���ø�����Ȥ�ķ���---------------------
===================================================================*/

/**************************************************************************
�������ܣ�LED�ӿڳ�ʼ��
��ڲ������� 
����  ֵ����
**************************************************************************/
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC| RCC_APB2Periph_AFIO,ENABLE); //ʹ�ܶ˿�ʱ��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 |GPIO_Pin_14;	          //�˿�����
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
	GPIO_Init(GPIOA, &GPIO_InitStructure);				  //�����趨������ʼ��GPIOA 
}

/**************************************************************************
�������ܣ�LED��˸
��ڲ�������˸Ƶ�� 
����  ֵ����
**************************************************************************/
void Led_Flash(uint16_t time)
{
	static int temp = 0;
	if(++temp == time)
	{
		if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13|GPIO_Pin_14)==0)
			GPIO_SetBits(GPIOC, GPIO_Pin_13|GPIO_Pin_14);
		else
			GPIO_ResetBits(GPIOC, GPIO_Pin_13|GPIO_Pin_14);
		temp=0;
	}
}