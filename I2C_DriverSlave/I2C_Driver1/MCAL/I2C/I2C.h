/*
 * I2C.h
 *
 *  Author: Ahmed
 */ 

#include "../DIO/DIO.h"

#ifndef I2C_H_
#define I2C_H_

#define START_ACK              0x08 // start has been sent
#define REP_START_ACK          0x10 // repeated start
#define SLAVE_ADD_AND_WR_ACK   0x18 // Master transmit ( slave address + Write request ) ACK
#define SLAVE_ADD_AND_RD_ACK   0x40 // Master transmit ( slave address + Read request ) ACK
#define WR_BYTE_ACK            0x28 // Master transmit data ACK
#define RD_BYTE_WITH_ACK      0x58 // Master received data with not ACK
#define SLAVE_ADD_RCVD_RD_REQ  0xA8 // means that slave address is received with write req
#define SLAVE_ADD_RCVD_WR_REQ  0x60 // means that slave address is received with read req
#define SLAVE_DATA_RECEIVED    0x80 // means that read byte req is received
#define SLAVE_BYTE_TRANSMITTED 0xC0 // means that write byte req is received


void I2C_Master_Init(void);

void I2C_Slave_Init(void);

void I2C_Start_Condition(void);

void I2C_RepeatedStart(void);

void I2C_Send_SlaveAddr_Write_Operation(uint8_t addr);

void I2C_Send_SlaveAddr_Read_Operation(uint8_t addr);

void I2C_Send_DataByte(uint8_t Data);

uint8_t I2C_Read_DataByte(void);

void I2C_Stop_Condition(void);





#endif /* I2C_H_ */