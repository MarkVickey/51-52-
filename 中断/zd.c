#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit dula = P2^6;
sbit wela = P2^7;
uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x76,0xf3,0x38,0x00,0x40};
uchar code loc[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xc0};
void num_display(uint,uint);
void display(uint,uint);
void delay_ms(uint);
uchar num;
uchar num1;
uchar sec;
uchar sec1;
uchar min;
void main()
{ 
	num=0;
	num1=0;
	sec=0;
	sec1=0;
	min=0;	
 TH1=(65536-46080)/256;
 TL1=(65536-46080)%256;
 TMOD=0x11;
 EA=1;
 ET0=1;
 ET1=1;
 TR0=1;
 TR1=1;
 while(1)
 {
	 if(min)
	{
	num_display(1,min);
	display(2,20);	
	}
	num_display(4,sec);
	num_display(5,sec1);
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
	sec++;
	if(sec==60)
{sec=0;
min++;
if(min==60)min=0;
}
 }
}

void T0_time()interrupt 1
{
	
 TH0=(65536-46080)/256;
 TL0=(65536-46080)%256;
	num1++;
	if(num1==2)
	{
	sec1++;
	if(sec1==10)sec1=0;
	num1=0;
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

void num_display(uint a,uint b)
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
