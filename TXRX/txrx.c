#include "reg52.h"

#include<intrins.h>

typedef unsigned int u16; 

typedef unsigned char u8;

void delayms(u16); 

void main()

{

u8 i;

P1=0x01;                                      

delayms(300); 

while(1)

{

for(i=0;i<7;i++) 

{

P1=_crol_(P1,1);                                 

delayms(300);

}

for(i=0;i<7;i++)

{

P1=_cror_(P1,1);                                 

delayms(300); 

}

}

}



void delayms(u16 x)

{

u16 i,j; 

for(i=x;i>0;i--)                           

for(j=110;j>0;j--);

}