#include"reg51.h"

void delay(unsigned int n)// delay time/ ms/
{
	unsigned int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<124;j++);
	}
}

