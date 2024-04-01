#include"reg51.h"
#include"delay.h"

sbit Sound =P3^7;

void main()
{
	while(1)
	{
		unsigned int i;
		for(i=0;i<100;i++)
		{
		  Sound=~Sound;
		  delay(20);
		}
		
		for(i=0;i<80;i++)
		{
		  Sound=~Sound;
		  delay(50);
		}
		
		
	}
}