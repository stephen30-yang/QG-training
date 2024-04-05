#include"reg51.h"
#include<stdio.h>
unsigned char recdata='0';
unsigned char a[]="Hello World!\r";
unsigned long n=0;

void initscon()//timer 1
{
	SCON=0x50;//0101 0000
	TMOD=0x20;//0010 0000 
	TH1=256-3;
	TL1=256-3;
	TR1=1;
	ES=1;
	EA=1;
}

void senddata(char recdata)
{
  	SBUF=recdata;
		while(!TI);
		TI=0; 
}

void putstrings(char* arr)
{
	unsigned char* parr=arr;
	while((*parr)!='\0')
	{
		senddata(*parr);
		parr++;
	}
}

void main()
{
	initscon();
	while(1)
	{
		putstrings(a);
	  while(1)
	  {
		  while(TF1==0);
		  n++;
		  if(n==33333)
		  {
			  n=0;
			  putstrings(a);
		  }
	  }
	}
}



