#include <reg52.h>    		
#define uchar unsigned char
#define uint unsigned int 
sbit dula=P2^6;		
sbit wela=P2^7;		
sbit button=P3^6; 
uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
uchar num,temp;

void delayms(uint);

void main()
	EA=1;		  
	EX0=1;		 
	EX1=1;
	wela=1;
	P0=0xaa;
	wela=0;
button=0; 
temp=0xff;
	while(1)
  {
		for(num=0;num<16;num++)
		{
		dula=1;
		P0=table[num];
		dula=0;
		delayms(1000);
		}
	}
  }
  void extre0() interrupt 0         
  {
		temp=0x00;
		P1=temp;
  }

  void extre1() interrupt 2 
  {
		temp=0xff;
		P1=temp;
  }
  void delayms(uint xms)				
{
	uint i,j;
	for(i=xms;i>0;i--)		      
		for(j=110;j>0;j--);
}

