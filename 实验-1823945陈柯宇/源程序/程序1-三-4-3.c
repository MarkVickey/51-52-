#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
uchar temp;
void delay(uint a);
void main()
	{char m;
		while(1)
		{
		
		for(m=0;m<8;m++)
		{
			temp=0xfe;
			delay(200);
			temp=_crol_(temp,m);
			
			P1=temp;
		}
		
		for(m=7;m>0;m--)
		{
			temp=0xfe;
			delay(200);
			temp=_crol_(temp,m);
			
			P1=temp;
		}
	}
}
void delay(uint a)
{
		uint i,j;
		for(i=a;i>0;i--)
			for(j=114;j>0;j--);
}
