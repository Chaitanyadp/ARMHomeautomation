#include<lpc214x.h>
#include<string.h>

void adc0_init(void);
void title(void);
void lcd_init(void);
void lcd_cmd(char c);
void uart_result(void);
void uart_init(void);
void lcd(char result);
void uart_display(long int n);
void delay(int count);
void uart(char data);
void led_init(void);
void check(void);
