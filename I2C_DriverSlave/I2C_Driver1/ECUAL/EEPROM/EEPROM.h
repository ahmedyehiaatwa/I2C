/*
 * EEPROM.h
 *
 *  Author: Ahmed
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "../../MCAL/I2C/I2C.h"

void EEPROM_Init(void);

void EEPROM_WriteData(uint8_t data, uint8_t Loc);

uint8_t EEPROM_ReadData(uint8_t Loc);

void EEPROM_WriteMultipleData (uint8_t* data, uint8_t s , uint8_t Loc);









#endif /* EEPROM_H_ */