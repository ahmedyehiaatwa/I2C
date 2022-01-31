/*
 * I2C.c
 *
 *  Author: Ahmed
 */ 

#include "I2C.h"

void I2C_Master_Init(void)
{
	TWBR= 0x07; // CLK I2C 400 Khz  
	
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
	
	SET_BIT(TWCR,2); // Enable I2C
}

void I2C_Slave_Init(void)
{
	TWAR= (0x01 << 1); // Slave address 0x01
	SET_BIT(TWCR,2); // Enable I2C
}

void I2C_Start_Condition(void)
{
	TWCR |= 0x04; //Start Condition CLR flag enable I2C
	
	while(GET_BIT(TWCR,7) ==0); // Blocking on flag
	
	while((TWSR & 0xf8) != START_ACK); // Blocking on operation status
}

void I2C_RepeatedStart(void)
{
		TWCR |= 0x04; //Start Condition CLR flag enable I2C
		
		while(GET_BIT(TWCR,7) ==0); // Blocking on flag
		
		while((TWSR & 0xf8) != REP_START_ACK); // Blocking on operation status
}

void I2C_Send_SlaveAddr_Write_Operation(uint8_t addr)
{
	TWDR = (addr <<1 );  // Slave address with write operation
	TWCR = 0x84; // Clear flag enable I2C
	
	while(GET_BIT(TWCR,7) ==0); // Blocking on flag
		
	while((TWSR & 0xf8) != SLAVE_ADD_AND_WR_ACK); // Blocking on operation status
	
}

void I2C_Send_SlaveAddr_Read_Operation(uint8_t addr)
{
		TWDR = ((addr <<1) | 0x01 );  // Slave address with read operation
		TWCR = 0x84; // Clear flag enable I2C
		
		while(GET_BIT(TWCR,7) ==0); // Blocking on flag
		
		while((TWSR & 0xf8) != SLAVE_ADD_AND_RD_ACK); // Blocking on operation status
}

void I2C_Send_DataByte(uint8_t Data)
{
			TWDR = Data;  // Send Databyte
			TWCR = 0x84; // Clear flag enable I2C
			
			while(GET_BIT(TWCR,7) ==0); // Blocking on flag
			
			while((TWSR & 0xf8) != WR_BYTE_ACK); // Blocking on operation status
}

uint8_t I2C_Read_DataByte(void)
{

				TWCR = 0x84; // Clear flag enable I2C
				
				while(GET_BIT(TWCR,7) ==0); // Blocking on flag
				
				while((TWSR & 0xf8) != RD_BYTE_WITH_ACK); // Blocking on operation status
				
				return TWDR;
}

void I2C_Stop_Condition(void)
{
	TWCR = 0x94; // Stop condition CLR FLAG ENABLE I2C
	
	
}