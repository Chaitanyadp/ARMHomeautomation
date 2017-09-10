#include "proto.h"
#include "sentence.h"
long int h;
int l=0,b=0,q;
char *H,p=0;

int main()
{   
	  
	  int count;
	
	  adc0_init();
	  uart_init();
	  lcd_init();
    title();
	  led_init();		
	
	  while(1)
		{   
			  k=0;
			  count=0;
			
				while(k>=0)
			{
				while(!(U0LSR & (1<<0)));
				d = U0RBR;
        m[k] =d;
				count++;
				k++;
				  if(d=='\n')
					break;
		}
			
		 l=count-2;
			
		if (((strncmp(m,msg1,l))&&(strncmp(m,msg8,l)))==0)
			{
				if(l<4)
					goto e;
				else
				uart_result();
				for(k=0; msg7[k] != '\0'; k++)
				uart(msg7[k]);
			}
			
			else if (((strncmp(m,msg2,l))&&(strncmp(m,msg9,l)))==0)
			{
				if(l<2)
					goto e;
				else
				IOSET0 =(1<<4);
				for(k=0; msg4[k] != '\0'; k++)
				uart(msg4[k]);
				
			}
			else if (((strncmp(m,msg3,l))&&(strncmp(m,msg10,l)))==0)
			{
				if(l<3)
					goto e;
				else
				IOCLR0 =(1<<4);
				for(k=0; msg5[k] != '\0'; k++)
				uart(msg5[k]);
			}
			
			
			else if (((strncmp(m,msg11,l))&&(strncmp(m,msg12,l)))==0)
			{
				k=0;
			  count=0;
			
				while(k>=0)
			{
				while(!(U0LSR & (1<<0)));
				d = U0RBR;
        t[k] =d;
				count++;
				k++;
				 b=count-2;
				  if(d=='\n')
						break;  
		}
			for(k=0; msg13[k] != '\0'; k++)
		{
				uart(msg13[k]);
		}
		for(k=0; t[k] != '\0'; k++)
				uart(t[k]);
		
			}
			else
			{ uart('\r');
		e:	for(k=0; msg6[k] != '\0'; k++)
				uart(msg6[k]);
			}
			
			
//			check();
//			if ((strncmp(t,s,b))==0)
//			{ q = IOSET0 & (1<<4);
//				if(q)
//				{
//				IOCLR0 =(1<<4);
//				for(k=0; msg5[k] != '\0'; k++)
//				uart(msg5[k]);
//				
//				for(k=0; msg14[k] != '\0'; k++)
//				uart(msg14[k]);
//				uart_result();
//				}
//				
//			}
				
			

			
		}
}
