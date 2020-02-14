/*
 * DIO_DRV.h
 *
 *  Created on: Oct 23, 2019
 *      Author: ali zewail
 */

#ifndef GPIO_DRV_H_
#define GPIO_DRV_H_




#define HIGHV 1
#define LOWV 0

typedef enum
{
    CTL_PA=0,
    CTL_PB,
    CTL_PC,
    CTL_PD,
    CTL_PE,
    CTL_PF
}GPIOCTL_t;

typedef enum
{
    PA=0,
    PB,
    PC,
    PD,
    PE,
    PF
}GPIOPortID_t;

typedef enum
{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7

}GPIOPinID_t;

typedef enum
{
    Out=0,
    InOpenDrain,
    InPullUp,
    InPullDown,
    InFree
}GPIODirection_t;

typedef enum
{
    I_2mA=0,
    I_4mA,
    I_8mA


}GPIOCurrent_t;

void GPIO_PORT_INIT(GPIOPortID_t port,GPIODirection_t dir ,GPIOCurrent_t current);

void GPIO_PIN_INIT(GPIOPortID_t port,GPIOPinID_t pin,GPIODirection_t dir,GPIOCurrent_t current);

void GPIO_WRITE_PORT(GPIOPortID_t port,uint8 value);

void GPIO_WRITE_PIN(GPIOPortID_t port,GPIOPinID_t pin,uint8 value);

uint8 GPIO_READ_PORT(GPIOPortID_t port);

uint8 GPIO_READ_PIN(GPIOPortID_t port,GPIOPinID_t pin);


#endif /* GPIO_DRV_H_ */
