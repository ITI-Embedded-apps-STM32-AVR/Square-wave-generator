/*
Author: Sara Abdallah 
Version:v1
Date:4/2/2020
systic driver for the timer 
*/
/********************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void STK_voidEnableExtInt(void);
void STK_voidStart(u32 copy_u32Value);
void STK_voidSetCallBack(void (*cpy_ptr)(void));


#endif
