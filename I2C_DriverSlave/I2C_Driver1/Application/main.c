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
    I2C_Slave_Init();
	I2C_Start_Condition();
	DIO_SetPortDir(PORTB, DIO_PORT_OUTPUT);
	uint8_t data;
	
	
	
    while (1) 
    {
		data = I2C_Read_DataByte();
		DIO_SetPortValue(PORTB, data);
    }
}

