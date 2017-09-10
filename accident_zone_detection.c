#include<stdio.h>
#include<string.h>

#include<lpc214x.h>
lcd_display(char b);
	 
int main()
{
     char str1[10]="12345678";
	 char str2[10];
	 if(strncmp(str1,str2,10)==0)
	 {
	 lcd_display(str1);
	 
	   
	 }
	 else
	   lcd_display(str2);
	   
	 
}



lcd_display(char result)
{

void delay(int count);
void lcd_com(char c);
void lcd_data(char c);

{
	IODIR0 |=(1<<12);
	IODIR0 |=(1<<10);
	IODIR0 |=(1<<13);
	IODIR0 |=(0xFF<<15);
	
	
lcd_com(0X38);
lcd_com(0X0e);
lcd_com(0X80);
lcd_com(0X01);

}


void lcd_com(char c)
{
IOPIN0=(result << 15);
IOCLR0 = (1<<13);
IOCLR0=(1<<12);
IOSET0=(1<<10);
delay(50);
IOCLR0=(1<<10);
}
void lcd_data(char c)
{
IOPIN0=(result << 15);
IOSET0 = (1<<13);
IOCLR0=(1<<12);
IOSET0=(1<<10);
delay(50);
IOCLR0=(1<<10);
}
void delay(int count)
{
	int i,j;
	for(i=0;i<count;i++)
	for(j=0;j<500;j++);
}
}