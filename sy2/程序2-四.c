#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit dula = P2^6;
sbit wela = P2^7;
uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x76,0xf3,0x38,0x00};
uchar code loc[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xc0};
uchar code l[]={5,4,3,2,1,0};
void delay_ms(uint);
void L(uint,uint);


void main()
{	
	//uchar i;
  uchar j;
  uchar k;
	uchar speed_wt;
	uchar speed;
	//uchar sh=0;
	while(1)
	{	
		for(j=60,k=0;j>0;j--,k++)
		{
		for(speed=238;speed>0;speed--)
		{
		L(5,k);
	}
		for(speed_wt=240;speed_wt>0;speed_wt--);
}
	}
	}
	


void delay_ms(uint a)
{
	uint i;
	uint j;
	for(i=a;i>0;i--)
	for(j=114;j>0;j--);
}

void L(uint a,uint b)
{
	
	if(b<10)
	{
	P0=0xff;
	wela=1;
	P0=loc[a+1];
	wela=0;
	P0=0x00;
	dula=1;
	P0=table[19];
	dula=0;
	delay_ms(2);	
		
	P0=0xff;
	wela=1;
	P0=loc[a];
	wela=0;
	P0=0x00;
	dula=1;
	P0=table[b];
	dula=0;
	delay_ms(2);
	}
	if(b>=10)
	{
	P0=0xff;
	wela=1;
	P0=loc[a];
	wela=0;
	P0=0x00;
	dula=1;
	P0=table[b%10];
	dula=0;
	delay_ms(2);
		
	P0=0xff;
	wela=1;
	P0=loc[a-1];
	wela=0;
	P0=0x00;
	dula=1;
	P0=table[b/10];
	dula=0;
	delay_ms(2);
	}
}
