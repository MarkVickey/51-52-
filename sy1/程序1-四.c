#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
void delay(uint a);
void main()
	{
		
		unsigned char i;
		while(1)
		{
			for(i=0;i<8;i++)
		{
			P1=(0x01<<i);	 
			delay(300); 
		}	
		for(i=7;i>0;i--)
		{
			P1=(0x01<<i);	 
			delay(300); 
		}

			}
		}

void delay(uint a)
{
		uint i,j;
		for(i=a;i>0;i--)
			for(j=114;j>0;j--);
}
