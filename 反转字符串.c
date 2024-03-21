#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
//字符串反转 eg "i love kobe" ->"ebok evol i"
int main()
{
	char str[100] = "i love kobe";
	char arr[100] = "aaa";
	for (int i = (strlen(str)-1); i >= 0; i--)
	{
		for (int j = 0; j<strlen(str); j++)       //假设str内有6个字符 那么strlen(str)=6  需要将str[5]赋值给arr[0] str[4]赋值给arr[1] 此时i+j==strlen(str)-1
		{
			if (i + j == (strlen(str)-1))
			{
				arr[j] = str[i];
				printf("%c", arr[j]);
			}
		}
	}
	return 0;
}