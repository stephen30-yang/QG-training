#include"Single LInkedLIst.h"
void menu()
{
	printf("********************************             ********************************\n");
	printf("                                ��ѡ����Ĳ���                               \n");
	printf("                         1.��ʼ������  2.�����½ڵ�\n");
	printf("                         3.�������    4.ɾ���ڵ�\n");
	printf("                         5.��ѯ����    6.�˳�ϵͳ\n");
}

Status InitListHead(LinkedList L)//ͷ�ڵ�
{
	L->data = 0;
	L->next = NULL;
	return SUCCESS;
}

LNode* Newnode(DataType data)//�����µĽڵ�
{
	LNode* new = (LNode*)malloc(sizeof(LNode));
	if (new == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	new->data = data;
	new->next = NULL;
	return new;
}

void SListPushBack(LNode** pp, DataType x)//β������(��ĩβ�� 
{
	LNode* newnode = Newnode(x);
	if (*pp == NULL)
	{
		*pp = newnode;
	}
	else
	{
	//�ҵ�β�ڵ����
		LNode* tail = *pp;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

 void TraverseList(LinkedList L)//��������
{
	LNode* visit = L->next;
	while (visit)
	{
		printf("%d->", visit->data);
		visit = visit->next;
	}
	printf("NULL\n");
}


Status InsertList(LNode* p, LNode* q)//��pΪ��һ���ڵ㿪ʼ�� p����Ϊ��һ���ڵ�ĵ�ַҲ����L->next qΪnewnode
{
	//p�������һ��q  q��ʵ�������ɵ�һ���ڵ� -> �ҵ�p�ڵ�
	printf("�������ڵڼ����ڵ���������\n");
	int x = 0;
	scanf("%d", &x);
	int count = 1;
	while (count < x)
	{
		p =p->next;
		count++;
	}
	//����ѭ����Findָ��ָ��p�ڵ�
	//q�ڵ�Ϊnewnode
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

Status SearchList(LinkedList L, DataType e)//��ѯ����
{
	LNode* Find = L->next;
	while (1)
	{
		//�ж��Ƿ�Ϊ���ҵ�Ԫ��
		if (Find->data == e)
		{
			printf("��Ԫ�ش���\n");
			break;
		}
		Find = Find->next;
		if (Find == NULL)
		{
			printf("��Ԫ�ز�����\n");
			break;
		}
	}
	return SUCCESS;
}

Status DeleteList(LNode* p, DataType* e)//LNode*p =L->next �ҵ���Ҫɾ����λ����ǰһλ
{
	printf("������ɾ����Ԫ�ص�λ��:>");
	int x = 0;
	scanf("%d", &x);
	int count = 1;
	while (count < x - 1)
	{
		p = p->next;
		count++;
	}
	LNode* q = p->next;
	p->next = q->next;
	free(q);
	p->data = *e;
	return SUCCESS;
}

int JudgeNumberQuantity(LinkedList L)//�ж�����Ԫ�ظ���
{
	int count = 0;
	LNode* Quantity = L->next;
	while (Quantity != NULL)
	{
		count++;
		Quantity = Quantity->next;
		if (Quantity == NULL)
		{
			return count;
			break;
		}
	}
}
