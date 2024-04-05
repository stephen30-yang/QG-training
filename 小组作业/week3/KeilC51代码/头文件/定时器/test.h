#include"reg51.h"

void inittimer()//16bit  
{
	TMOD=0x01;//0000 0001
	TH0=(65535-50000)/256;    //50ms=50000us ----> 1s==50ms*20  Cycle 20 times for 50ms   
	TL0=(65535-50000)%256;
	ET0=1;
	EA=1;
	TR0=1;//set up
	TF0=0;
}