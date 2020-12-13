#include<reg52.h>
#define uint unsigned int
void delay(uint a);
void main()
	{
		while(1)
		{
		P1=0xf0;
		delay(1000);
		P1=0xff;
		delay(2000);
		}
	}

void delay(uint a)
{
		uint i,j;
		for(i=a;i>0;i--)
			for(j=114;j>0;j--);
}