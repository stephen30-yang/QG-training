#include"test.h"
unsigned char ledata[]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; 
unsigned int count=0;
unsigned char s[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//0~9
unsigned int num=0;
unsigned int N=0;
unsigned int i=0;
unsigned int j=0;




void display()
{
	P2=s[num];
	if(num==10)
	{
		num=0;
	}
}


void main()
{
	inittimer();  
	while(1)
	{
		display();
		while(TF0==0)
		;
			N++;
		if(N==20)
		{
			P0=~ledata[j++]; 
			N=0; 
		}
		if(j==8)
			j=0;
	}	
 }

void timer_isr() interrupt 1
{
	TH0=(65535-50000)/256;    //50ms=50000us ----> 1s==50ms*20  Cycle 20 times for 50ms   
	TL0=(65535-50000)%256;
	count++;
	if(count==20)
	{
		num++;
		count=0;
	}
}