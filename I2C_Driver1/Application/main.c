/*
 * I2C_Driver1.c
 *
 * Author : Ahmed
 */ 

#include "../MCAL/I2C/I2C.h"
#include "../ECUAL/LCD/LCD.h"

#define F_CPU 16000000




int main(void)
{
    ;
	LCD_Init();
	I2C_Master_Init();
	I2C_Start_Condition();
	I2C_Send_SlaveAddr_Write_Operation(0x01);
	
	
	
    while (1) 
    {
		I2C_Send_DataByte(0xf0);
		/*LCD_WriteChar(data);*/
    }
}

