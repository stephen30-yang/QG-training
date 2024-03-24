#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
 
typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode //�ڵ�
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;//��ջָ��
	int	count;//ջ��Ԫ�ظ���
}LinkStack;

Status initLStack(LinkStack* s);//��ʼ��ջ

Status isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��

StackNode* NewStackNode(ElemType data);//����һ���µ���ջ�Ľڵ� ����push

Status pushLStack(LinkStack* s, ElemType data);//��ջ

Status popLStack(LinkStack* s, ElemType* data);//��ջ

Status getTopLStack(LinkStack* s, ElemType* e);//�õ�ջ��Ԫ��

Status LStackLength(LinkStack* s, int* length);//���ջ����

Status clearLStack(LinkStack* s);//���ջ  

Status destroyLStack(LinkStack* s);//����ջ

void menu();