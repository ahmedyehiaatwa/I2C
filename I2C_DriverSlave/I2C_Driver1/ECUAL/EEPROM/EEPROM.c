/*
 * EEPROM.c
 *
 *  Author: Ahmed
 */ 


#include "EEPROM.h"


void EEPROM_Init(void)
{
	I2C_Master_Init();
}
void EEPROM_WriteData(uint8_t data, uint8_t Loc)
{
	I2C_Start_Condition();
	
	I2C_Send_SlaveAddr_Write_Operation(0b0101000);
	
	I2C_Send_DataByte(Loc);
	
	I2C_Send_DataByte(data);
	
	I2C_Stop_Condition();
	
}

uint8_t EEPROM_ReadData(uint8_t Loc)
{
	uint8_t data;
	
	I2C_Start_Condition();
	I2C_Send_SlaveAddr_Write_Operation(0b0101000);
	I2C_Send_DataByte(Loc);
	I2C_RepeatedStart();
	I2C_Send_SlaveAddr_Read_Operation(0b0101000);
	
	data = I2C_Read_DataByte();
	
	I2C_Stop_Condition();
	
	return data;
}

void EEPROM_WriteMultipleData (uint8_t* data, uint8_t s , uint8_t Loc)
{
	uint8_t i=0;
	
		I2C_Start_Condition();
		
		I2C_Send_SlaveAddr_Write_Operation(0b0101000);
		
		I2C_Send_DataByte(Loc);
		
		while(i< s)
		{
			I2C_Send_DataByte(data[i]);
			i++;
		}
		
		
		I2C_Stop_Condition();
}