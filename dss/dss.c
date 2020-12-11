#include<reg52.h>
#define uint unsigned int
uint i,j;
void delay(uint a);
void main()
{
while(1)
{
		P1=0xfc;
		delay(200);
		P1=0xf3;
		delay(200);
		P1=0xcf;
		delay(200);
		P1=0x3f;
		delay(200);
//		while(1)
	//	P1=0xff;
}
}

	void delay(uint a)
	{
		for(i=a;i>0;i--)
			for(j=114;j>0;j--);
	}
