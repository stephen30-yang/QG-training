#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
//�ַ�����ת eg "i love kobe" ->"ebok evol i"
int main()
{
	char str[100] = "i love kobe";
	char arr[100] = "aaa";
	for (int i = (strlen(str)-1); i >= 0; i--)
	{
		for (int j = 0; j<strlen(str); j++)       //����str����6���ַ� ��ôstrlen(str)=6  ��Ҫ��str[5]��ֵ��arr[0] str[4]��ֵ��arr[1] ��ʱi+j==strlen(str)-1
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