/*
Author: Sara Abdallah 
Version:v1
Date:2/2/2020
*/
/********************************************/
#include "STD_TYPES.h"
#include "BIT_math.h"
#include "STK_register.h"
//#include "STK_register.h"
#include "STK_Interface.h"
void (*SysTick_CallBack)(void);
void STK_voidEnableExtInt(void)
{
	/*Enable Systic  Intrrupt-clock =AHB /8*/
	/*stop systic*/
	STK_CLK=0x00000002;
}
void STK_voidStart(u32 copy_u32Value)
{
	/**load value into load register*/
	STK_LOAD=copy_u32Value;
	/*clear Value register*/
	STK_val=0;
	/*start system timer*/
	SET_BIT(STK_CLK,0);
}
void STK_voidSetCallBack(void (*cpy_ptr)(void))
{
	SysTick_CallBack=cpy_ptr;
}
void SysTick_Handler(void)
{
	SysTick_CallBack();
}
