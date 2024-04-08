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


//1.将中缀表达式转化为后缀表达式 
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

Status initcharLStack(charLinkStack* s);//初始化链栈

Status isEmptyLStack(charLinkStack* s);//判断栈是否为空

Status getTopLStack(charLinkStack* s, chartype* e);//得到栈顶元素

Status pushLStack(charLinkStack* s, chartype data);//入栈

Status popLStack(charLinkStack* s, chartype* data);//出栈

charStackNode* NewStackNode(chartype data);//创建新的节点

int compare_opt(char opt1);//计算运算符的优先级

//***************************************************************
//***************************************************************

int calculate (int value_1, int value_2, char opt);//计算栈顶前两个数据

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

Status initintLStack(intLinkStack* s);//初始化链栈

Status isEmptyintLStack(intLinkStack* s);//判断栈是否为空

Status getTopLintStack(intLinkStack* s, ElemType* e);//得到栈顶元素

Status pushLintStack(intLinkStack* s, ElemType data);//入栈

Status popintLStack(intLinkStack* s, ElemType* data);//出栈

intStackNode* NewintStackNode(ElemType data);//创建新的节点

  