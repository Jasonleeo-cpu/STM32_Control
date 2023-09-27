#include "led.h"

/*===================================================================
程序功能：LED初始化，以及LED闪烁函数
程序编写：公众号：小白学移动机器人
其他    ：如果对代码有任何疑问，可以私信小编，一定会回复的。
=====================================================================
------------------关注公众号，获得更多有趣的分享---------------------
===================================================================*/

/**************************************************************************
函数功能：LED接口初始化
入口参数：无 
返回  值：无
**************************************************************************/
void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC| RCC_APB2Periph_AFIO,ENABLE); //使能端口时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 |GPIO_Pin_14;	          //端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;     //50M
	GPIO_Init(GPIOA, &GPIO_InitStructure);				  //根据设定参数初始化GPIOA 
}

/**************************************************************************
函数功能：LED闪烁
入口参数：闪烁频率 
返回  值：无
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
