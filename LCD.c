#include"Std_Types.h"
#include"GPIO_DRV.h"
#include"LCD.h"
#include"LCD_config.h"

void _delay_ms(uint32 n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < 3180; j++)
        {
        } /* do nothing for 1 ms */
}

void _delay_us(uint32 n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < 3; j++)
        {
        } /* do nothing for 1 us */
}

LCD_status LCD_init(void)
{

    LCD_status status = NOKAY;

//set directions output for data pins

    GPIO_PIN_INIT(DATA_PORT, PIN4, Out, I_2mA);
    GPIO_PIN_INIT(DATA_PORT, PIN5, Out, I_2mA);
    GPIO_PIN_INIT(DATA_PORT, PIN6, Out, I_2mA);
    GPIO_PIN_INIT(DATA_PORT, PIN7, Out, I_2mA);

    GPIO_PIN_INIT(LCD_CONTROL_PORT, LCD_EN, Out, I_2mA);
    GPIO_PIN_INIT(LCD_CONTROL_PORT, LCD_RS, Out, I_2mA);
    GPIO_PIN_INIT(LCD_CONTROL_PORT, LCD_RW, Out, I_2mA);

    /* initialization sequence */
    _delay_ms(20);
    LCD_Write_Nibble(0x30, 0);
    _delay_ms(5);
    LCD_Write_Nibble(0x30, 0);
    _delay_us(100);
    LCD_Write_Nibble(0x30, 0);
    _delay_us(40);
    LCD_Write_Nibble(0x20, 0); /* use 4-bit data mode */
    _delay_us(40);

    LCD_Send_Command(0x28); /* set 4-bit data, 2-line, 5x7 font */
    _delay_us(40);
    LCD_Send_Command(0x06); /* move cursor right */
    _delay_us(40);
    LCD_Send_Command(0x01);/* clear screen, move cursor to home */
    _delay_ms(2);
    LCD_Send_Command(0x0F);
    _delay_us(40);

    return status;
}

LCD_status LCD_Write_Nibble(uint8 data, uint8 control)
{

    LCD_status status = NOKAY;

    data &= 0xF0;
    if (control == 0)
    {

        GPIO_WRITE_PIN(LCD_CONTROL_PORT, LCD_RS, LOWV);
        GPIO_WRITE_PIN(LCD_CONTROL_PORT, LCD_RW, LOWV);

    }
    else
    {
        GPIO_WRITE_PIN(LCD_CONTROL_PORT, LCD_RS, HIGHV);
        GPIO_WRITE_PIN(LCD_CONTROL_PORT, LCD_RW, LOWV);
    }

    switch (DATA_PORT)
    {
    case PA:
        LCD_DATA_PORTA = data;
        break;
    case PB:
        LCD_DATA_PORTB = data;
        break;
    case PC:
        LCD_DATA_PORTC = data;
        break;
    case PD:
        LCD_DATA_PORTD = data;
        break;
    case PE:
        LCD_DATA_PORTE = data;
        break;
    case PF:
        LCD_DATA_PORTF = data;
        break;

    }

    GPIO_WRITE_PIN(LCD_CONTROL_PORT, LCD_EN, HIGHV);
    _delay_ms(1);
    GPIO_WRITE_PIN(LCD_CONTROL_PORT, LCD_EN, LOWV);

    status = OKAY;
    return status;
}

LCD_status LCD_Send_Command(uint8 cmnd)
{
    LCD_status status = NOKAY;

    LCD_Write_Nibble(cmnd & 0xF0, 0); // upper nibble first
    LCD_Write_Nibble(cmnd << 4, 0); //lower nibble

    status = OKAY;

    return status;
}

LCD_status LCD_Send_Char(uint8 data)
{

    LCD_status status = NOKAY;

    LCD_Write_Nibble(data & 0xF0, 1); /* upper nibble first */
    LCD_Write_Nibble(data << 4, 1);
    status = OKAY;

    return status;
}

