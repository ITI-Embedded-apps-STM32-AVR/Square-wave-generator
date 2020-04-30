
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "RCC_interface.h"
#include "Stk_interface.h"
#include "Delay_interface.h"

void Func(void);
void func1(void);


u32 out1=0;
u32 out2=0;
u32 start=0;
u32 freq=100;
void main(void)
{

	RCC_Init();
	RCC_EnablePreiphiralClock(2, 2);
	DIO_SetPinMode('A' , 0, 0b1000);
	DIO_SetPinMode('A' , 1, 0b1000);
	DIO_SetPinValue('A' , 0, 1);
	DIO_SetPinValue('A' , 1, 1);

	STK_voidEnableExtInt();
	DIO_SetPinMode('A' , 3, 0b0010);
	DIO_SetPinValue('A',3,0);

	STK_voidSetCallBack(&Func);


	STK_voidStart(5000);
	func1();




}
void func1(void)
{

	while(1)
	{
		start=(1000000/(2*freq));

		out1=DIO_GetPinVal('A', 0);
		out2=DIO_GetPinVal('A', 1);
		if (out1==0)
		{
			while(!DIO_GetPinVal('A',0)){}
			freq+=10;
			STK_voidStart(start);
			delay_ms(200);
		}
		else if (out2==0)
		{
			while(!DIO_GetPinVal('A',1)){}
			freq-=10;
			STK_voidStart(start);
			delay_ms(200);
		}
	}
}
void Func(void)
{
	static u32 flag=0;
	if(flag==0)
	{
		DIO_SetPinValue('A',3,1);
		flag=1;
	}
	else
	{
		DIO_SetPinValue('A',3,0);
		flag=0;
	}
}
