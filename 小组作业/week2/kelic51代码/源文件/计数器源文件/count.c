#include"reg51.h"
unsigned char s[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char num=0;

void initcounter()
{
	TMOD=0x06;//0x00 0110
	TH0=256-3;
	TL0=256-3;
	ET0=1;
	EA=1;
	TR0=1;
}

void display()
{
	if(num==10)
	{
		num=0;
	}
		P2=s[num]; 
}

void main()
{
	unsigned int num=0;
	initcounter();
	while(1)
	{
		display();
	}
}
	
void counter_isr() interrupt 1
{
	num++;
}
	