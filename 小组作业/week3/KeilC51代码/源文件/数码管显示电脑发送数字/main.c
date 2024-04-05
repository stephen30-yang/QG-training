#include"reg51.h"
#include<stdio.h>
unsigned char a=0;
unsigned char flag=0;
unsigned char table2[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};//7seg 0~9

void initscon()
{
	SCON=0x50;//0101 0000
	TMOD=0x20;//0010 0000 
	TH1=0xFD;
	TL1=0xFD;
	TR1=1;
	EA=1;                      
  ES=1;       
}


void main()
{
	initscon();
	P2=0xFF;
	while(1)
	{
		if(flag==1)
		 {
			flag=0;
      ES=0;                          
      SBUF=a;                         
      while(!TI);
      TI=0;                          
      ES=1;
		 }
	 switch(a)    
	 {
		 case '0':P2=table2[0];break;
     case '1':P2=table2[1];break;
     case '2':P2=table2[2];break;
     case '3':P2=table2[3];break;
     case '4':P2=table2[4];break;
     case '5':P2=table2[5];break;
     case '6':P2=table2[6];break;
     case '7':P2=table2[7];break;
     case '8':P2=table2[8];break;
     case '9':P2=table2[9];break;
	 }
 }
}

void scon_isr() interrupt 4
{
        flag=1;
        RI=0;
        a=SBUF;

}
