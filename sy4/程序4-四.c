#include<reg52.h>
#define uint unsigned int 
#define uchar unsigned char 
unsigned char flag,a,i,temp,butt;
void init(){
SCON=0x50;//01010000
	TR1=1;
	//SM0=0;
	//SM1=1; 
	TMOD=0X20;	
	//REN=1; 
	TH1=0XFD;
	TL1=0XFD; 
	EA=1;
	ES=1;
}

void delay_ms(uint a)
{
	uint i;
	uchar j;
	for(i=a;i>0;i--)
	for(j=114;j>0;j--);
}

void ser() interrupt 4
{ 
	RI=0;
	a=SBUF;
  butt=1;
flag=1;
}

void main()
{
	init();
	while(1)
	{
		switch(a){
		case 'a':P1=0x00;break;
		case 'b':P1=0xff;break;
		default:
		{P1=0x00;
		delay_ms(500);
		P1=0xff;
		delay_ms(500);
		}}

 	if(flag==1) 
		{
		ES=0; 
		flag=0;
		SBUF=a; 
		while(!TI); 
		TI=0;   
		ES=1;
		}
	}
}