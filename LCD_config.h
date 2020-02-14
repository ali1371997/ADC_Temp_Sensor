
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define FUNCTION_SET 0x28
#define DISPLAY_ON 0x0c
#define DISPLAY_CLR 0x01
#define ENTRY_MODE_SET 0x06



#define LCD_CONTROL_PORT PA
#define LCD_RS PIN2
#define LCD_RW PIN3
#define LCD_EN PIN4


#define DATA_PORT PB    //from pin 4 to pin 7




#endif /* LCD_CONFIG_H_ */
