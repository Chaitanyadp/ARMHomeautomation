#include "proto.h"
extern long int t;
extern int k;
char c;
extern char s[];
long int n;

void title(void)
{
	char *str="   -- HOME --";
	char *str1="AUTOMATION ";
	
	for(k=0; str[k] != '\0'; k++)
	{
	lcd(str[k]);
	}
	lcd_cmd(0xc3);
	for(k=0; str1[k] != '\0'; k++)
	{
	lcd(str1[k]);
	}
}

void adc0_init(void)
{
	PINSEL1 = (PINSEL1 & (~(3<<28)))|(1<<28);
	AD0CR = (1<<3)|(3<<8)|(1<<16)|(1<<21);
}

void uart_result(void)
{
	while(!(AD0GDR & (1<<31)));
	n = AD0GDR & (0x3ff<<6);
	n >>= 6;
	uart_display(n/3);
}

void uart_init(void)
{
	 PINSEL0 = (1<<0)|(0<<1)|(1<<2)|(0<<3);
   U0LCR = 1<<7;
   U0DLL = 97;
   U0LCR = (0<<7)|3;
}

void uart(char data)
{  
  	c = data;
	 while(!(U0LSR & (1<<5)));
	 U0THR = c;
}

void uart_display(long int n)
{ 
	long int result=0;
	
	while(n)
	{
		result =(10*result +(n%10));
		n=n/10;
	}

	while(result)
	{
		uart((result%10)+0x30);
		result=result/10;
	}
}

void delay(int count)
{
	int j,k;

	for(j=0; j< count; j++)
	for(k=0; k<5000; k++);
}

void lcd_init(void)
{ 
	IODIR0 |= (0xff<<15);
	IODIR0 |= (1<<12);
	IODIR0 |= (1<<10);
	IODIR0 |= (1<<13);
	
  lcd_cmd(0x38);
	lcd_cmd(0x0e);
	lcd_cmd(0x80);
	lcd_cmd(0x01);
}

void lcd_cmd(char c)
{
    IOPIN0 = (c<<15);
	IOCLR0 = (1<<13);//selecting cmd reg
	IOCLR0 = (1<<12);//write
	IOSET0 = (1<<10);//enable
	delay(50);
	IOCLR0 = (1<<10);
}

void lcd(char c)
{
  IOPIN0 = (c<<15);
	IOSET0 = (1<<13);//selecting data reg
	IOCLR0 = (1<<12);//write
	IOSET0 = (1<<10);//enable
	delay(50);
	IOCLR0 = (1<<10); 
}

void led_init(void)
{
	IODIR0 = (0xf<<4)|(0xf<<10);
  IOCLR0 =(0xf<<4)|(0xf<<10);
}

void check(void)
{
	long int result=0;
	 k=0;
	t=0;
	while(!(AD0GDR & (1<<31)));
	n = AD0GDR & (0x3ff<<6);
	n >>= 6;
	n=n/3;
	
	
	while(n)
	{
		result =(10*result +(n%10));
		n=n/10;
	}

	while(result)
	{ 
		s[k]=(result%10)+0x30;
		result=result/10;
		k++;
	}
}
