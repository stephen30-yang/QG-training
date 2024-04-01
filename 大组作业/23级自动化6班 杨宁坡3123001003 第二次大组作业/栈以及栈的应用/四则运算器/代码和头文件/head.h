#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<math.h>

typedef char chartype;

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;


//1.����׺���ʽת��Ϊ��׺���ʽ 
typedef  struct charStackNode
{
	chartype data;
	struct charStackNode* next;
}charStackNode, * charLinkStackPtr;

typedef  struct  charLinkStack
{
	charLinkStackPtr top;
	int	count; 
}charLinkStack;

Status initcharLStack(charLinkStack* s);//��ʼ����ջ

Status isEmptyLStack(charLinkStack* s);//�ж�ջ�Ƿ�Ϊ��

Status getTopLStack(charLinkStack* s, chartype* e);//�õ�ջ��Ԫ��

Status pushLStack(charLinkStack* s, chartype data);//��ջ

Status popLStack(charLinkStack* s, chartype* data);//��ջ

charStackNode* NewStackNode(chartype data);//�����µĽڵ�

int compare_opt(char opt1);//��������������ȼ�

//***************************************************************
//***************************************************************

int calculate (int value_1, int value_2, char opt);//����ջ��ǰ��������

typedef int ElemType;

typedef struct intStackNode
{
	ElemType data;
	struct intStackNode* nnext;
}intStackNode,* intLinkStackPtr;

typedef struct intLinkStack
{
	intLinkStackPtr head;
	int size;  
}intLinkStack; 

Status initintLStack(intLinkStack* s);//��ʼ����ջ

Status isEmptyintLStack(intLinkStack* s);//�ж�ջ�Ƿ�Ϊ��

Status getTopLintStack(intLinkStack* s, ElemType* e);//�õ�ջ��Ԫ��

Status pushLintStack(intLinkStack* s, ElemType data);//��ջ

Status popintLStack(intLinkStack* s, ElemType* data);//��ջ

intStackNode* NewintStackNode(ElemType data);//�����µĽڵ�

  