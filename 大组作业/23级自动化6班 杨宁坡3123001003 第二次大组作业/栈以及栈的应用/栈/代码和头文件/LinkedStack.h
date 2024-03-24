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

typedef  struct StackNode //节点
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;//顶栈指针
	int	count;//栈中元素个数
}LinkStack;

Status initLStack(LinkStack* s);//初始化栈

Status isEmptyLStack(LinkStack* s);//判断栈是否为空

StackNode* NewStackNode(ElemType data);//创建一个新的链栈的节点 方便push

Status pushLStack(LinkStack* s, ElemType data);//入栈

Status popLStack(LinkStack* s, ElemType* data);//出栈

Status getTopLStack(LinkStack* s, ElemType* e);//得到栈顶元素

Status LStackLength(LinkStack* s, int* length);//监测栈长度

Status clearLStack(LinkStack* s);//清空栈  

Status destroyLStack(LinkStack* s);//销毁栈

void menu();