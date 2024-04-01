#include"head.h"

//1.*********************************************************
Status initcharLStack(charLinkStack* s)//��ʼ��ջ
{
	s->count = 0;
	s->top = NULL;
}

Status isEmptyLStack(charLinkStack* s)//�ж��Ƿ�Ϊ��ջ
{
	charStackNode* p = s->top;
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

charStackNode* NewStackNode(chartype data)//�����µĽڵ�
{
	charStackNode* new = (charStackNode*)malloc(sizeof(charStackNode));
	assert(new != NULL);
	new->data = data;
	new->next = NULL;
	return new;
}



Status pushLStack(charLinkStack* s, chartype data)//��ջ
{

	//1.�����½ڵ�
	charStackNode* New = NewStackNode(data);
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


Status popLStack(charLinkStack* s, chartype* data)//��ջ
{
	//1.�ж��Ƿ�Ϊ��ջ
	if (isEmptyLStack(s) == ERROR)
	{
		//printf("Empty Stack\n");
		//printf("�����´���һ��ջ\n");
		return ERROR;
	}
	charStackNode* pmove = s->top;
	s->top = (s->top)->next;
	s->count--;
	*data = pmove->data;
	//printf("��ջ��Ԫ����%d\n", *data);
	free(pmove);
	return SUCCESS;
}

Status getTopLStack(charLinkStack* s, chartype* e)//�õ�ջ��Ԫ��
{
	//���ж��Ƿ�Ϊ��ջ
	if (isEmptyLStack(s) == ERROR)
	{
		//printf("Empty Stack And no Elements\n");
		return ERROR;
	}
	charStackNode* UP = s->top;
	*e = UP->data;
	return SUCCESS;
}

int compare_opt (char opt)//��������������ȼ�
{
	if (opt == '+' || opt == '-')
	{
		return 1;
	}
	else if (opt == '*' || opt == '/')
	{
		return 2;
	}
	
}
//********************************************************************

int calculate(int value_1, int value_2, char opt)//����ջ��ǰ��������
{
	if (opt == '+')
	{
		return value_1 + value_2;
	}
	if (opt == '-')
	{
		return value_1 - value_2; //�ȳ�����Ԫ����Ϊvalue_2
	}
	if (opt == '*')
	{
		return value_1 * value_2;
	}
	if (opt == '/')
	{
		return value_1 / value_2;
	}
}

Status initintLStack(intLinkStack* s)//��ʼ����ջ
{
	s->head = NULL;
	s->size = 0;
}

Status isEmptyintLStack(intLinkStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	intStackNode* p = s->head;
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

intStackNode* NewintStackNode(ElemType data)//�����µĽڵ�
{
	intStackNode* new = (intStackNode*)malloc(sizeof(intStackNode));
	assert(new != NULL);
	new->data = data;
	new->nnext = NULL;
	return new;
}

Status pushLintStack(intLinkStack* s, ElemType data)//��ջ
{
	//1.�����½ڵ�
	intStackNode* NNew = NewintStackNode(data);
	//��ʱ���ж��Ƿ�Ϊ��ջ ����ǿ�ջ ��ôtopָ��ֱ��ָ�����һ���½ڵ�
	if (isEmptyintLStack(s) == ERROR)
	{
		s->head = NNew; 
		s->size++;
	}
	else
	{
		//2.�½ڵ��ֱ�Ӻ��ָ��ǰ��ջ�����
		NNew->nnext = s->head;
		//3.ջ��ָ��ָ���½��
		s->head = NNew;
		s->size++;
	}
	return SUCCESS;
}

Status popintLStack(intLinkStack* s, ElemType* data)//��ջ
{

	//1.�ж��Ƿ�Ϊ��ջ
	if (isEmptyintLStack(s) == ERROR)
	{
		/*printf("Empty Stack\n");
		printf("�����´���һ��ջ\n");*/
		return ERROR;
	}
	intStackNode* pmove = s->head;
	s->head = (s->head)->nnext;
	s->size--;
	*data = pmove->data;
	/*printf("��ջ��Ԫ����%d\n", *data);*/
	free(pmove);
	return SUCCESS;
}

Status getTopLintStack(intLinkStack* s, ElemType* e)//�õ�ջ��Ԫ��
{
	//���ж��Ƿ�Ϊ��ջ
	if (isEmptyintLStack(s) == ERROR)
	{
		//printf("Empty Stack And no Elements\n");
	   	return ERROR; 
	}
	intStackNode* UP = s->head;
	*e = UP->data;
	return SUCCESS; 
}