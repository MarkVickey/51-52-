#include <reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit dula=P2^6;
sbit wela=P2^7;
sbit adwr=P3^6;
sbit adrd=P3^7;
uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x76,0xf3,0x38,0x00,0x40};
uchar code loc[]={0x7e,0x7d,0x7b,0xf7,0xef,0xdf,0xc0};

void num_display(uchar,uchar);
void delay_ms(uint);

void main()
{
uchar a,adval;
	while(1)
	{adwr=1;
		_nop_();
		adwr=0;
		_nop_();
		adwr=1;
		
		for(a=10;a>0;a--){
			
num_display(2,adval);}
	
		
		P1=0xff;
		adrd=1;
		_nop_();
		adrd=0;
		_nop_();
	adval=P1;
		adrd=1;
		}
}
void delay_ms(uint a)
{
	uint i;
	uchar j;
	for(i=a;i>0;i--)
	for(j=114;j>0;j--);
}


void num_display(uchar a,uchar b)
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
	if((b>=10)&&(b<100))
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
	if(b>=100)
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
	P0=table[b%100/10];
	dula=0;
	delay_ms(2);
		
	P0=0xff;
	wela=1;
	P0=loc[a-2];
	wela=0;
	P0=0x00;
	dula=1;
	P0=table[b/100];
	dula=0;
	delay_ms(2);
}}