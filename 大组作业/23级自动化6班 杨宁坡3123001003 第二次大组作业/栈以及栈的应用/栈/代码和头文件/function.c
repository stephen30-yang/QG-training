#include"LinkedStack.h"

Status initLStack(LinkStack* s)//初始化栈
{
	s->count = 0;
	s->top = NULL;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack* s)//判断栈是否为空
{
	StackNode* p = s->top;
	if ( p == NULL)
	{
		return ERROR;
	}
	if( p!= NULL)
	{
		return SUCCESS;
	}
	return SUCCESS; 
}

StackNode* NewStackNode(ElemType data)//创建新的节点
{
	StackNode* new = (StackNode*)malloc(sizeof(StackNode));
	assert(new != NULL);
	new->data = data;
	new->next = NULL;
	return new;
}

Status pushLStack(LinkStack* s, ElemType data)//入栈
{
	//1.生成新节点
	StackNode* New = NewStackNode(data);
	//此时先判断是否为空栈 如果是空栈 那么top指针直接指向这个一个新节点
	if (isEmptyLStack(s) == ERROR)
	{
		 s->top=New;
		 s->count++;
	}
	else
	{
		//2.新节点的直接后继指向当前的栈顶结点
		New->next = s->top;
		//3.栈顶指针指向新结点
		s->top = New;
		s->count++;
	}
	return SUCCESS;
}

Status getTopLStack(LinkStack* s,ElemType* e)//得到顶栈元素
{
	//先判断是否为空栈
	if (isEmptyLStack(s) == ERROR)
	{
		printf("Empty Stack And no Elements\n");
		return ERROR;
	}
	StackNode* UP = s->top;
	*e = UP->data;
	return SUCCESS;
}

Status LStackLength(LinkStack* s, int* length)
{
	//判断是否为空栈
	if (isEmptyLStack(s) == ERROR)
	{
		printf("Empty Stack\nlength=0");
		return ERROR;
	}
	*length = s->count;
	return SUCCESS;
}

Status popLStack(LinkStack* s, ElemType* data)//出栈
{
	//1.判断是否为空栈
	if (isEmptyLStack(s) == ERROR)
	{
		printf("Empty Stack\n");
		printf("请重新创建一个栈\n");
		return ERROR;
	}
	StackNode* pmove = s->top;
	s->top = (s->top)->next;
	s->count--;
	*data = pmove->data;
	printf("出栈的元素是%d\n", *data);
	free(pmove);
	return SUCCESS;
}

Status clearLStack(LinkStack* s)//清空栈
{
	if (isEmptyLStack(s) == ERROR)
	{
		printf("已经是空栈无需清空\n");
		return ERROR;
	}
	StackNode* p = s->top;
	while (p != NULL)
	{
		StackNode* q = p;
		p = p->next;
		free(q);
	}
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

Status destroyLStack(LinkStack* s)//销毁栈
{
	clearLStack(s);
	return SUCCESS;
}

void menu()
{
	printf("***********************************************************\n");
	printf("1.初始化栈                                2.入栈\n");
	printf("3.出栈                                    4.判断是否为空栈\n");
	printf("5.获得栈顶元素                            6.判断栈长度\n");
	printf("7.清空栈                                  8.销毁栈\n");
	printf("                   0.退出程序\n");
	printf("***********************************************************\n");
}