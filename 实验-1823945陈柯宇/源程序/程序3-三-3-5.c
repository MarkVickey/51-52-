#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula = P2^6;
sbit wela = P2^7;
uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x76,0xf3,0x38,0x00};
uchar code loc[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xc0};
void display(uint,uint);
void delay_ms(uint);
uchar num,num0;
uchar j;
sbit led1=P1^0;
void main()
{
	num=0;
 TMOD=0x11;
 EA=1;
 ET1=1;
 TR1=1;
 ET0=1;
 TR0=1;
 while(1)
 {
	display(1,j);
 } 
}
void T0_time()interrupt 1
{
 TH0=(65536-46080)/256;
 TL0=(65536-46080)%256;
	
 num0++;
 if(num0==20)
 {
  num0=0;
  led1=~led1;
 }

}
void T1_time()interrupt 3
{
	
 TH1=(65536-46080)/256;
 TL1=(65536-46080)%256;
	num++;
	if(num==20)
	{
	num=0;
	j++;
	if(j==60)j=0;
 }
}



void delay_ms(uint a)
{
	uint i;
	uint j;
	for(i=a;i>0;i--)
	for(j=114;j>0;j--);
}


void display(uint a,uint b)
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
