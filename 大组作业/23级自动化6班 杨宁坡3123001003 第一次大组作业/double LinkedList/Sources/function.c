#include"Double LinkedList.h"

Status InitList_DuL(DuLinkedList* L)//��ʼ��һ��˫����ı�ͷ  Ҳ���Ǵ���һ��ͷ�ڵ�
{
	DuLNode* HeadNode = (DuLNode*)malloc(sizeof(DuLNode));
	assert(HeadNode != NULL);
	HeadNode->next = NULL;
	HeadNode->prior = NULL;
	HeadNode->data = 0;//ͷ�ڵ��ֵ����Ҫ�� ����һ��
	*L = HeadNode;
	return SUCCESS;
}

DuLNode* NewNode(int data)//�����µĽڵ�
{
	 DuLNode* newnode = (DuLNode*)malloc(sizeof(DuLNode));
	 if (newnode == NULL)
	 {
		 printf("�����ڴ�ʧ��\n");
		 exit(-1);
	 }
	 newnode->data = data;
	 newnode->next = NULL;
	 newnode->prior = NULL;
	 return newnode;
}


void DuLinkedListPushBcak(DuLNode** ppHEAD,ElemType data)//˫�����β��  ��ʱ*ppHEAD==HEAD
{
	DuLNode* pushbacknode = NewNode(data);
	assert(pushbacknode != NULL);
	//�ҵ����һ���ڵ�
	if (*ppHEAD == NULL)
	{
		*ppHEAD = pushbacknode;
	}
	DuLNode* tail_1 = *ppHEAD;
	DuLNode* tail_2 = *ppHEAD;
	while ( tail_1->next != NULL )
	{
		tail_1 = tail_1->next;
		tail_2 = tail_2->next;
	}
	tail_2 = tail_2->next;
	tail_2 = pushbacknode;
	tail_1->next = pushbacknode;
	tail_2->prior = tail_1;
}


void TraverseList_DuL(DuLinkedList L)//����˫���� ���Ǻܻ��ú���ָ�����Ծ�û��
{
	if (L == NULL)
	{
		printf("������\n");
		exit(-1);
	}
	DuLNode* pmove = L->next;
	while (pmove != NULL)
	{
		printf("%d ", pmove->data);
		pmove = pmove->next;
	}
	printf("NULL\n");
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)//p�ڵ�����q�ڵ�    q�����¼���Ľڵ� ʹ��NewNode��������
{
	printf("��������Ҫ�ڵڼ����ڵ���������:>");
	int num = 0;
	scanf("%d", &num);
	if (num == 0)//��0λ����������ͷ�ڵ�����
	{
		DuLNode* ppnext = p->next;
		p->next = q;
		ppnext->prior = q;
		q->next = ppnext;
		q->prior = p;
	}
	p = p->next;
	int count = 1;
	while (count < num)
	{
		p = p->next;
		count++;
	}
	//����ǲ������һ�� ��ô��ʱp->nextΪNULL
	//�������λ��Ҫ�ж�p->next�Ƿ�Ϊ��
	if (p->next == NULL)
	{
		p->next = q;
		q->prior = p;
		return SUCCESS;

	}
	else
	{
		DuLNode* pnext = p->next;
		p->next = q;
		pnext->prior = q;
		q->next = pnext;
		q->prior = p;
		return SUCCESS;
	}
}

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)//p�ڵ�֮ǰ�������� 
//����������� ֻ����Ҫ�����ڵ�һ���ڵ�֮ǰ�������� 
{
	p = p->next; 
	printf("��������Ҫ�ڵڼ����ڵ�ǰ��������:>");
	int num = 0;
	scanf("%d", &num);
	while (num == 0)
	{
		printf("����������\n");
		scanf("%d", &num);
	}
	int count = 1;
	while (count < num) 
	{
		p = p->next; 
		count++; 
	} 
	//if(p->next==NULL)

	DuLNode* pprior = p->prior;
	p->prior = q;
	pprior->next = q;
	q->next = p;
	q->prior = pprior;
	return SUCCESS;
}


Status DeleteList_DuL(DuLNode* p, ElemType* e)
{
	printf("������ڼ����ڵ��ɾ���ڵ�:>");
	int num = 0;
	scanf("%d", &num);
	p = p->next;
	int count = 1;
    while (count < num)
	{
	    p = p->next;
		count++;
	}
	DuLNode* pnext = p->next;
	if (pnext == NULL)
	{
		printf("û�нڵ�->�޷�ɾ��\n");
		return ERROR;
	}
	DuLNode* ppnext = pnext->next;
	if (ppnext == NULL)
	{
		p->next = NULL;
		free(pnext);
		p->data = *e;
		return SUCCESS;
	}
	p->next = ppnext;
	ppnext->prior = p;
	free(pnext);
	p->data= *e;
	return SUCCESS;
}


void DestroyList_DuL(DuLinkedList* L)//*L��ʵ��HEADָ�� ָ��ͷ�ڵ� 
{
	DuLNode* pmove = *L;
	while (pmove->next!=NULL)
	{
		pmove = pmove->next;
	}
	//��ʱpmoveָ��ָ�����һ���ڵ�
	pmove = pmove->prior;//��pomveָ�����ڶ����ڵ�
	while (1)
	{
		DuLNode* pnext=pmove->next;
		pmove->next = NULL;
		free(pnext);
		if (pmove != L)
		{
			pmove = pmove->next;
		}
		if (pmove == *L)
		{
			*L = NULL;
			free(pmove);
			break;
		}
	}
	printf("����λ��%p", *L);
	printf("��ʱΪ������\n");
}