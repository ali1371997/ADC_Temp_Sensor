#include"STD_TYPES.h"
#include"Utils.h"
#include"RegMap.h"
#include "GPIO_DRV.h"


/*Function to initialize port and select direction and current*/
void GPIO_PORT_INIT(GPIOPortID_t port, GPIODirection_t dir,
                    GPIOCurrent_t current)
{
    switch (port)
    {
    case PA:
        //enable clock for the GPIO_Port
        SET_BIT(GPIO_RCGC, CTL_PA);
      //enable high bus
        SET_BIT(GPIO_HBCTL, CTL_PA);

        GPIO_PortADEN = 0xFF;
        switch (dir)
        {
        case Out:
            GPIO_PortADIR = 0xFF;
            if (current == I_2mA)
            {
                GPIO_PortADR2R = 0xFF;
            }
            else if (current == I_4mA)
            {
                GPIO_PortADR4R = 0xFF;
            }
            else
            {
                GPIO_PortADR8R = 0xFF;
            }
            break;

        case InFree:
            GPIO_PortADIR = 0x00;
            break;

        case InOpenDrain:
            GPIO_PortADIR = 0x00;
            GPIO_PortBODR = 0xFF;
            break;
        case InPullUp:
            GPIO_PortADIR = 0x00;
            GPIO_PortAPUR = 0xFF;
            break;

        case InPullDown:
            GPIO_PortADIR = 0x00;
            GPIO_PortAPDR = 0xFF;
            break;

        }
        break;

    case PB:
        SET_BIT(GPIO_RCGC, CTL_PB);
        //enable high bus
        SET_BIT(GPIO_HBCTL, CTL_PB);

        GPIO_PortBDEN = 0xFF;

        switch (dir)
        {
        case Out:
            GPIO_PortBDIR = 0xFF;
            if (current == I_2mA)
            {
                GPIO_PortBDR2R = 0xFF;
            }
            else if (current == I_4mA)
            {
                GPIO_PortBDR4R = 0xFF;
            }
            else
            {
                GPIO_PortBDR8R = 0xFF;
            }
            break;

        case InFree:
            GPIO_PortBDIR = 0x00;
            break;

        case InOpenDrain:
            GPIO_PortBDIR = 0x00;
            GPIO_PortBODR = 0xFF;
            break;
        case InPullUp:
            GPIO_PortBDIR = 0x00;
            GPIO_PortBPUR = 0xFF;
            break;

        case InPullDown:
            GPIO_PortBDIR = 0x00;
            GPIO_PortBPDR = 0xFF;
            break;

        }
        break;

    case PC:
        SET_BIT(GPIO_RCGC, CTL_PC);
        //enable high bus
        SET_BIT(GPIO_HBCTL, CTL_PC);

        //unlock pin 0,1,3
        GPIO_PortCLOCK = 0x4C4F434B;
        GPIO_PortCCR = 0xFF; //(1) | (1 << 1) | (1 << 2) | (1 << 3);

        GPIO_PortCDEN = 0xFF;
        switch (dir)
        {
        case Out:
            GPIO_PortCDIR = 0xFF;
            if (current == I_2mA)
            {
                GPIO_PortCDR2R = 0xFF;
            }
            else if (current == I_4mA)
            {
                GPIO_PortCDR4R = 0xFF;
            }
            else
            {
                GPIO_PortCDR8R = 0xFF;
            }
            break;
            /*Port C Pins 0 ,1,2,and 3 will be always pulled up becuase of Jtag*/
        case InFree:
            GPIO_PortCDIR = 0x00;
            break;

        case InOpenDrain:
            GPIO_PortCDIR = 0x00;
            GPIO_PortCODR = 0xF0;
            break;
        case InPullUp:
            GPIO_PortCDIR = 0x00;
            GPIO_PortCPUR = 0xFF;
            break;

        case InPullDown:
            GPIO_PortCDIR = 0x00;
            GPIO_PortCPDR = 0xF0;
            break;

        }
        break;

    case PD:
        SET_BIT(GPIO_RCGC, CTL_PD);
        //enable high bus
          SET_BIT(GPIO_HBCTL, CTL_PD);

        //unlock pin 7
        GPIO_PortDLOCK = 0x4C4F434B;
        SET_BIT(GPIO_PortDCR, 7);
        GPIO_PortDDEN = 0xFF;

        switch (dir)
        {
        case Out:
            GPIO_PortDDIR = 0xFF;
            if (current == I_2mA)
            {
                GPIO_PortDDR2R = 0xFF;
            }
            else if (current == I_4mA)
            {
                GPIO_PortDDR4R = 0xFF;
            }
            else
            {
                GPIO_PortDDR8R = 0xFF;
            }
            break;

        case InFree:
            GPIO_PortDDIR = 0x00;
            break;

        case InOpenDrain:
            GPIO_PortDDIR = 0x00;
            GPIO_PortDODR = 0xFF;
            break;
        case InPullUp:
            GPIO_PortDDIR = 0x00;
            GPIO_PortDPUR = 0xFF;
            break;

        case InPullDown:
            GPIO_PortDDIR = 0x00;
            GPIO_PortDPDR = 0xFF;
            break;

        }
        break;
    case PE:
        SET_BIT(GPIO_RCGC, CTL_PE);
        //enable high bus
          SET_BIT(GPIO_HBCTL, CTL_PE);

        GPIO_PortEDEN = 0xFF;

        switch (dir)
        {
        case Out:
            GPIO_PortEDIR = 0xFF;
            if (current == I_2mA)
            {
                GPIO_PortEDR2R = 0xFF;
            }
            else if (current == I_4mA)
            {
                GPIO_PortEDR4R = 0xFF;
            }
            else
            {
                GPIO_PortEDR8R = 0xFF;
            }
            break;

        case InFree:
            GPIO_PortEDIR = 0x00;
            break;

        case InOpenDrain:
            GPIO_PortEDIR = 0x00;
            GPIO_PortEODR = 0xFF;
            break;
        case InPullUp:
            GPIO_PortEDIR = 0x00;
            GPIO_PortEPUR = 0xFF;
            break;

        case InPullDown:
            GPIO_PortEDIR = 0x00;
            GPIO_PortEPDR = 0xFF;
            break;

        }
        break;

    case PF:

        SET_BIT(GPIO_RCGC, CTL_PF);
        //enable high bus
          SET_BIT(GPIO_HBCTL, CTL_PF);


        //unlock pin 0
        GPIO_PortFLOCK = 0x4C4F434B;
        SET_BIT(GPIO_PortFCR, 0);
        GPIO_PortFDEN = 0xFF;
        switch (dir)
        {
        case Out:
            GPIO_PortFDIR = 0xFF;
            if (current == I_2mA)
            {
                GPIO_PortFDR2R = 0xFF;
            }
            else if (current == I_4mA)
            {
                GPIO_PortFDR4R = 0xFF;
            }
            else
            {
                GPIO_PortFDR8R = 0xFF;
            }
            break;

        case InFree:
            GPIO_PortFDIR = 0x00;
            break;

        case InOpenDrain:
            GPIO_PortFDIR = 0x00;
            GPIO_PortFODR = 0xFF;
            break;
        case InPullUp:
            GPIO_PortFDIR = 0x00;
            GPIO_PortFPUR = 0xFF;
            break;

        case InPullDown:
            GPIO_PortFDIR = 0x00;
            GPIO_PortFPDR = 0xFF;
            break;

        }
        break;

    }

}




/*Function to initialize pin and select direction and current*/
void GPIO_PIN_INIT(GPIOPortID_t port, GPIOPinID_t pin, GPIODirection_t dir,
                   GPIOCurrent_t current)
{
    switch (port)
    {
    case PA:
        //enable clock for the GPIO_Port
        SET_BIT(GPIO_RCGC, CTL_PA);
        //enable high bus
          SET_BIT(GPIO_HBCTL, CTL_PA);

        SET_BIT(GPIO_PortADEN, pin);
        switch (dir)
        {
        case Out:
            SET_BIT(GPIO_PortADIR, pin);
            if (current == I_2mA)
            {
                SET_BIT(GPIO_PortADR2R, pin);
            }
            else if (current == I_4mA)
            {
                SET_BIT(GPIO_PortADR4R, pin);

            }
            else
            {
                SET_BIT(GPIO_PortADR8R, pin);
            }
            break;

        case InFree:
            CLR_BIT(GPIO_PortADIR, pin);
            break;

        case InOpenDrain:
            CLR_BIT(GPIO_PortADIR, pin);
            SET_BIT(GPIO_PortAODR, pin);
            break;
        case InPullUp:
            CLR_BIT(GPIO_PortADIR, pin);
            SET_BIT(GPIO_PortAPUR, pin);
            break;
        case InPullDown:
            CLR_BIT(GPIO_PortADIR, pin);
            SET_BIT(GPIO_PortAPDR, pin);

            break;
        }
        break;
    case PB:
        //enable clock for the GPIO_Port
        SET_BIT(GPIO_RCGC, CTL_PB);
        //enable high bus
          SET_BIT(GPIO_HBCTL, CTL_PB);

        SET_BIT(GPIO_PortBDEN, pin);
        switch (dir)
        {
        case Out:
            SET_BIT(GPIO_PortBDIR, pin);
            if (current == I_2mA)
            {
                SET_BIT(GPIO_PortBDR2R, pin);
            }
            else if (current == I_4mA)
            {
                SET_BIT(GPIO_PortBDR4R, pin);

            }
            else
            {
                SET_BIT(GPIO_PortBDR8R, pin);
            }
            break;

        case InFree:
            CLR_BIT(GPIO_PortBDIR, pin);
            break;

        case InOpenDrain:
            CLR_BIT(GPIO_PortBDIR, pin);
            SET_BIT(GPIO_PortBODR, pin);
            break;
        case InPullUp:
            CLR_BIT(GPIO_PortBDIR, pin);
            SET_BIT(GPIO_PortBPUR, pin);
            break;
        case InPullDown:
            CLR_BIT(GPIO_PortBDIR, pin);
            SET_BIT(GPIO_PortBPDR, pin);

            break;
        }
        break;

    case PC:
        //enable clock for the GPIO_Port
        SET_BIT(GPIO_RCGC, CTL_PC);
        //enable high bus
          SET_BIT(GPIO_HBCTL, CTL_PC);


        if (pin == 0 | pin == 1 | pin == 2 | pin == 3)
        {
            GPIO_PortCLOCK = 0x4C4F434B;
            GPIO_PortCCR = 0XFF;  //(1) | (1 << 1) | (1 << 2) | (1 << 3);

        }
        SET_BIT(GPIO_PortCDEN, pin);

        switch (dir)
        {
        case Out:
            SET_BIT(GPIO_PortCDIR, pin);
            if (current == I_2mA)
            {
                SET_BIT(GPIO_PortCDR2R, pin);
            }
            else if (current == I_4mA)
            {
                SET_BIT(GPIO_PortCDR4R, pin);

            }
            else
            {
                SET_BIT(GPIO_PortCDR8R, pin);
            }
            break;

        case InFree:
            CLR_BIT(GPIO_PortCDIR, pin);
            break;

        case InOpenDrain:
            CLR_BIT(GPIO_PortCDIR, pin);

            if (pin == 0 | pin == 1 | pin == 2 | pin == 3)
            {

            }
            else
            {
                SET_BIT(GPIO_PortCODR, pin);
            }
            break;

        case InPullUp:
            CLR_BIT(GPIO_PortCDIR, pin);
            SET_BIT(GPIO_PortCPUR, pin);
            break;

        case InPullDown:
            CLR_BIT(GPIO_PortCDIR, pin);

            if (pin == 0 | pin == 1 | pin == 2 | pin == 3)
            {

            }
            else
            {
                SET_BIT(GPIO_PortCPDR, pin);
            }
            break;
        }
        break;

    case PD:
        //enable clock for the GPIO_Port
        SET_BIT(GPIO_RCGC, CTL_PD);
        //enable high bus
          SET_BIT(GPIO_HBCTL, CTL_PD);


        if (pin == 7)
        {

            GPIO_PortDLOCK = 0x4C4F434B;
            SET_BIT(GPIO_PortDCR, 7);
        }

        SET_BIT(GPIO_PortDDEN, pin);
        switch (dir)
        {
        case Out:
            SET_BIT(GPIO_PortDDIR, pin);
            if (current == I_2mA)
            {
                SET_BIT(GPIO_PortDDR2R, pin);
            }
            else if (current == I_4mA)
            {
                SET_BIT(GPIO_PortDDR4R, pin);

            }
            else
            {
                SET_BIT(GPIO_PortDDR8R, pin);
            }
            break;

        case InFree:
            CLR_BIT(GPIO_PortDDIR, pin);
            break;

        case InOpenDrain:
            CLR_BIT(GPIO_PortDDIR, pin);
            SET_BIT(GPIO_PortDODR, pin);
            break;
        case InPullUp:
            CLR_BIT(GPIO_PortDDIR, pin);
            SET_BIT(GPIO_PortDPUR, pin);
            break;
        case InPullDown:
            CLR_BIT(GPIO_PortDDIR, pin);
            SET_BIT(GPIO_PortDPDR, pin);

            break;
        }
        break;

    case PE:
        //enable clock for the GPIO_Port
        SET_BIT(GPIO_RCGC, CTL_PE);
        //enable high bus
          SET_BIT(GPIO_HBCTL, CTL_PE);

        SET_BIT(GPIO_PortEDEN, pin);
        switch (dir)
        {
        case Out:
            SET_BIT(GPIO_PortEDIR, pin);
            if (current == I_2mA)
            {
                SET_BIT(GPIO_PortEDR2R, pin);
            }
            else if (current == I_4mA)
            {
                SET_BIT(GPIO_PortEDR4R, pin);

            }
            else
            {
                SET_BIT(GPIO_PortEDR8R, pin);
            }
            break;

        case InFree:
            CLR_BIT(GPIO_PortEDIR, pin);
            break;

        case InOpenDrain:
            CLR_BIT(GPIO_PortEDIR, pin);
            SET_BIT(GPIO_PortEODR, pin);
            break;
        case InPullUp:
            CLR_BIT(GPIO_PortEDIR, pin);
            SET_BIT(GPIO_PortEPUR, pin);
            break;
        case InPullDown:
            CLR_BIT(GPIO_PortEDIR, pin);
            SET_BIT(GPIO_PortEPDR, pin);

            break;
        }
        break;

    case PF:
        //enable clock for the GPIO_Port
        SET_BIT(GPIO_RCGC, CTL_PF);
        //enable high bus
          SET_BIT(GPIO_HBCTL, CTL_PF);


        if (pin == 0)
        {

            GPIO_PortFLOCK = 0x4C4F434B;
            SET_BIT(GPIO_PortFCR, 0);
        }
        SET_BIT(GPIO_PortFDEN, pin);
        switch (dir)
        {
        case Out:
            SET_BIT(GPIO_PortFDIR, pin);
            if (current == I_2mA)
            {
                SET_BIT(GPIO_PortFDR2R, pin);
            }
            else if (current == I_4mA)
            {
                SET_BIT(GPIO_PortFDR4R, pin);

            }
            else
            {
                SET_BIT(GPIO_PortFDR8R, pin);
            }
            break;
        case InFree:
            CLR_BIT(GPIO_PortFDIR, pin);
            break;

        case InOpenDrain:
            CLR_BIT(GPIO_PortFDIR, pin);
            SET_BIT(GPIO_PortFODR, pin);
            break;
        case InPullUp:
            CLR_BIT(GPIO_PortFDIR, pin);
            SET_BIT(GPIO_PortFPUR, pin);
            break;
        case InPullDown:
            CLR_BIT(GPIO_PortFDIR, pin);
            SET_BIT(GPIO_PortFPDR, pin);

            break;
        }
        break;

    }

}

void GPIO_WRITE_PORT(GPIOPortID_t port, uint8 value)
{
    switch (port)
    {
    case PA:
        GPIO_PortAData = value;
        break;
    case PB:
        GPIO_PortBData = value;
        break;
    case PC:
        GPIO_PortCData = value;
        break;
    case PD:
        GPIO_PortDData = value;
        break;

    case PE:
        GPIO_PortEData = value;
        break;

    case PF:
        GPIO_PortFData = value;
        break;
    }
}

void GPIO_WRITE_PIN(GPIOPortID_t port, GPIOPinID_t pin, uint8 value)

{

    switch (port)
    {
    case PA:
        if (value == 1)
        {
            (*((volatile uint32*) (0x40004000 + (1 << (pin + 2))))) = 0XFF;
        }
        else
        {
            (*((volatile uint32*) (0x40004000 + (1 << (pin + 2))))) = 0X00;
        }
        break;

    case PB:
        if (value == 1)
        {

            (*((volatile uint32*) (0x40005000 + (1 << (pin + 2))))) = 0xFF;
        }
        else
        {
            (*((volatile uint32*) (0x40005000 + (1 << (pin + 2))))) = 0X00;
        }
        break;

    case PC:
        if (value == 1)
        {
            (*((volatile uint32*) (0x40006000 + (1 << (pin + 2))))) = 0xFF;
        }
        else
        {
            (*((volatile uint32*) (0x40006000 + (1 << (pin + 2))))) = 0x00;
        }
        break;

    case PD:
        if (value == 1)
        {

            (*((volatile uint32*) (0x40007000 + (1 << (pin + 2))))) = 0XFF;

        }
        else
        {
            (*((volatile uint32*) (0x40007000 + (1 << (pin + 2))))) = 0X00;
        }
        break;

    case PE:
        if (value == 1)
        {
            (*((volatile uint32*) (0x40024000 + (1 << (pin + 2))))) = 0XFF;
        }
        else
        {
            (*((volatile uint32*) (0x40024000 + (1 << (pin + 2))))) = 0X00;
        }
        break;
    case PF:
        if (value == 1)
        {
            (*((volatile uint32*) (0x40025000 + (1 << (pin + 2))))) = 0XFF;
        }
        else
        {
            (*((volatile uint32*) (0x40025000 + (1 << (pin + 2))))) = 0X00;
        }
        break;

    }

}

uint8 GPIO_READ_PORT(GPIOPortID_t port)
{
    uint8 value = 0;
    switch (port)
    {
    case PA:
        value = GPIO_PortAData;
        break;
    case PB:
        value = GPIO_PortBData;
        break;
    case PC:
        value = GPIO_PortCData;
        break;
    case PD:
        value = GPIO_PortDData;
        break;

    case PE:
        value = GPIO_PortEData;
        break;

    case PF:
        value = GPIO_PortFData;
        break;
    }

    return value;
}

uint8 GPIO_READ_PIN(GPIOPortID_t port, GPIOPinID_t pin)
{

    uint8 value = 0;

    switch (port)
    {
    case PA:
        value = GET_BIT(GPIO_PortAData, pin);
        break;

    case PB:
        value = GET_BIT(GPIO_PortBData, pin);
        break;

    case PC:
        value = GET_BIT(GPIO_PortCData, pin);
        break;

    case PD:
        value = GET_BIT(GPIO_PortDData, pin);
        break;
    case PE:
        value = GET_BIT(GPIO_PortEData, pin);
        break;
    case PF:
        value = GET_BIT(GPIO_PortFData, pin);
        break;
    }

    return value;

}
