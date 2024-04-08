#include"LinkedStack.h"

Status initLStack(LinkStack* s)//��ʼ��ջ
{
	s->count = 0;
	s->top = NULL;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack* s)//�ж�ջ�Ƿ�Ϊ��
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

StackNode* NewStackNode(ElemType data)//�����µĽڵ�
{
	StackNode* new = (StackNode*)malloc(sizeof(StackNode));
	assert(new != NULL);
	new->data = data;
	new->next = NULL;
	return new;
}

Status pushLStack(LinkStack* s, ElemType data)//��ջ
{
	//1.�����½ڵ�
	StackNode* New = NewStackNode(data);
	//��ʱ���ж��Ƿ�Ϊ��ջ ����ǿ�ջ ��ôtopָ��ֱ��ָ�����һ���½ڵ�
	if (isEmptyLStack(s) == ERROR)
	{
		 s->top=New;
		 s->count++;
	}
	else
	{
		//2.�½ڵ��ֱ�Ӻ��ָ��ǰ��ջ�����
		New->next = s->top;
		//3.ջ��ָ��ָ���½��
		s->top = New;
		s->count++;
	}
	return SUCCESS;
}

Status getTopLStack(LinkStack* s,ElemType* e)//�õ���ջԪ��
{
	//���ж��Ƿ�Ϊ��ջ
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
	//�ж��Ƿ�Ϊ��ջ
	if (isEmptyLStack(s) == ERROR)
	{
		printf("Empty Stack\nlength=0");
		return ERROR;
	}
	*length = s->count;
	return SUCCESS;
}

Status popLStack(LinkStack* s, ElemType* data)//��ջ
{
	//1.�ж��Ƿ�Ϊ��ջ
	if (isEmptyLStack(s) == ERROR)
	{
		printf("Empty Stack\n");
		printf("�����´���һ��ջ\n");
		return ERROR;
	}
	StackNode* pmove = s->top;
	s->top = (s->top)->next;
	s->count--;
	*data = pmove->data;
	printf("��ջ��Ԫ����%d\n", *data);
	free(pmove);
	return SUCCESS;
}

Status clearLStack(LinkStack* s)//���ջ
{
	if (isEmptyLStack(s) == ERROR)
	{
		printf("�Ѿ��ǿ�ջ�������\n");
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

Status destroyLStack(LinkStack* s)//����ջ
{
	clearLStack(s);
	return SUCCESS;
}

void menu()
{
	printf("***********************************************************\n");
	printf("1.��ʼ��ջ                                2.��ջ\n");
	printf("3.��ջ                                    4.�ж��Ƿ�Ϊ��ջ\n");
	printf("5.���ջ��Ԫ��                            6.�ж�ջ����\n");
	printf("7.���ջ                                  8.����ջ\n");
	printf("                   0.�˳�����\n");
	printf("***********************************************************\n");
}