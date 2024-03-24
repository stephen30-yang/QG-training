#include"LQuene.h"

Node* Newnode(ElemType data)//�����µĽڵ�   �������ݵĵ�ַ
{
	Node* new = (Node*)malloc(sizeof(Node));
	assert(new != NULL);
	new->next = NULL;
	new->data = data;
	return new;
}

void InitLQueue(LQueue* Q)//��ʼ��һ������
{
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

Status EnLQueue(LQueue* Q, ElemType data)//���
{
	Node* New = Newnode(data); 
	if (Q->front == NULL )
	{
		Q->front = New;
		Q->rear = New;
		Q->length++;
		return TRUE;
	}
	Q->rear->next = New; 
	Q->rear = New;
	Q->length++;
	return TRUE;
}

Status DeLQueue(LQueue* Q)//����
{
	if (IsEmptyLQueue(Q) == TRUE)
	{
		printf("Empty Quene\n");
		return FALSE; 
	}
	Node* pomve = Q->front;
	Q->front = pomve->next;
	Q->length--;
	pomve->next = NULL;
	free(pomve);
	return TRUE;
}

int LengthLQueue(LQueue* Q)//ȷ�����г���
{
	return Q->length;
}

Status IsEmptyLQueue(const LQueue* Q)//�ж϶����Ƿ�Ϊ��
{
	if (Q->length == 0)
	{
		return TRUE;
	}
	if (Q->length > 0)
	{
		return FALSE;
	}
	return FALSE;
}

Status TraverseLQueue(const LQueue* Q)//��������
{
	if (IsEmptyLQueue(Q) == TRUE)
	{
		printf("empty and cannot be traversed\n");
		return FALSE;
	}
	Node* pmove = Q->front;
	while (pmove->next!=NULL) 
	{
		printf("%d->", (pmove->data));
		pmove = pmove->next; 
	}
	printf("%d\n", (pmove->data));
	return TRUE;
}

Status GetHeadLQueue(LQueue* Q, ElemType* e)//�鿴��ͷԪ��
{
	if (IsEmptyLQueue(Q) == TRUE)
	{
		return FALSE;
	}
	*e = (Q->front)->data;
	return TRUE;
}

void ClearLQueue(LQueue* Q)//��ն���
{
	if (IsEmptyLQueue(Q) == TRUE)
	{
		printf("Already Empty\n");
		return;
	}
	while (Q->front != Q->rear)
	{
		Node* pomve = Q->front; 
		Q->front = pomve->next;  
		Q->length--;     
		pomve->next = NULL;  
		free(pomve); 
	}
	//����ѭ����front��rearָ��ͬһ���ڵ�
	Q->front = NULL;
	Q->rear = NULL;
	Q->length--;
	return;
}

