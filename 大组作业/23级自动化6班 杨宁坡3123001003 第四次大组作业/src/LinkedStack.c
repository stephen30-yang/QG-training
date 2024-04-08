#include"binary_sort_tree.h"

Statu initLStack(LinkStack* s)//��ʼ��ջ
{
	s->count = 0;
	s->top = NULL;
	return SUCCESS;
}

Statu isEmptyLStack(LinkStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	StackNode* p = s->top;
	if (p == NULL)
	{
		return ERROR;
	}
	if (p != NULL)
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

Statu pushLStack(LinkStack* s, ElemType data)//��ջ
{
	//1.�����½ڵ�
	StackNode* New = NewStackNode(data);
	//��ʱ���ж��Ƿ�Ϊ��ջ ����ǿ�ջ ��ôtopָ��ֱ��ָ�����һ���½ڵ�
	if (isEmptyLStack(s) == ERROR)
	{
		s->top = New;
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

Statu getTopLStack(LinkStack* s, ElemType* e)//�õ���ջԪ��
{
	//���ж��Ƿ�Ϊ��ջ
	if (isEmptyLStack(s) == ERROR)
	{
		//printf("Empty Stack And no Elements\n");
		return ERROR;
	}
	StackNode* UP = s->top;
	*e = UP->data;
	return SUCCESS;
}

Statu popLStack(LinkStack* s, ElemType* data)//��ջ
{
	//1.�ж��Ƿ�Ϊ��ջ
	if (isEmptyLStack(s) == ERROR)
	{
		return ERROR;
	}
	StackNode* pmove = s->top;
	s->top = (s->top)->next;
	s->count--;
	*data = pmove->data;
	/*printf("%d ", *data);*/
	free(pmove);
	return SUCCESS;
}

Statu InorderpopLStack(LinkStack* s, ElemType* data)//��ջ
{
	//1.�ж��Ƿ�Ϊ��ջ
	if (isEmptyLStack(s) == ERROR)
	{
		return ERROR;
	}
	StackNode* pmove = s->top;
	s->top = (s->top)->next;
	s->count--;
	*data = pmove->data;
	printf("%d ", *data);
	free(pmove);
	return SUCCESS;
}