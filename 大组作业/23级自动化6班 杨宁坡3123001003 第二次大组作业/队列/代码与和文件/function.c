#include"LQuene.h"

Node* Newnode(ElemType data)//创建新的节点   传入数据的地址
{
	Node* new = (Node*)malloc(sizeof(Node));
	assert(new != NULL);
	new->next = NULL;
	new->data = data;
	return new;
}

void InitLQueue(LQueue* Q)//初始化一个队列
{
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
}

Status EnLQueue(LQueue* Q, ElemType data)//入队
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

Status DeLQueue(LQueue* Q)//出队
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

int LengthLQueue(LQueue* Q)//确定队列长度
{
	return Q->length;
}

Status IsEmptyLQueue(const LQueue* Q)//判断队列是否为空
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

Status TraverseLQueue(const LQueue* Q)//遍历队列
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

Status GetHeadLQueue(LQueue* Q, ElemType* e)//查看对头元素
{
	if (IsEmptyLQueue(Q) == TRUE)
	{
		return FALSE;
	}
	*e = (Q->front)->data;
	return TRUE;
}

void ClearLQueue(LQueue* Q)//清空队列
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
	//跳出循环后front和rear指向同一个节点
	Q->front = NULL;
	Q->rear = NULL;
	Q->length--;
	return;
}

