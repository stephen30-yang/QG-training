#include"binary_sort_tree.h"

QueneNode* Newnode(ElemType data)//创建新的节点   传入数据的地址
{
	QueneNode* new = (Node*)malloc(sizeof(QueneNode));
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

Statuses EnLQueue(LQueue* Q, ElemType data)//入队
{
	QueneNode* New = Newnode(data);
	if (Q->front == NULL)
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

Statuses DeLQueue(LQueue* Q)//出队
{
	if (IsEmptyLQueue(Q) == TRUE)
	{
		printf("Empty Quene\n");
		return FALSE;
	}
	QueneNode* pomve = Q->front;
	Q->front = pomve->next;
	Q->length--;
	pomve->next = NULL;
	free(pomve);
	return TRUE;
}

Statuses IsEmptyLQueue(const LQueue* Q)//判断队列是否为空
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

Statuses TraverseLQueue(const LQueue* Q)//遍历队列
{
	if (IsEmptyLQueue(Q) == TRUE)
	{
		printf("empty and cannot be traversed\n");
		return FALSE;
	}
	QueneNode* pmove = Q->front;
	while (pmove->next != NULL)
	{
		printf("%d->", (pmove->data));
		pmove = pmove->next;
	}
	printf("%d\n", (pmove->data));
	return TRUE;
}

Statuses GetHeadLQueue(LQueue* Q, ElemType* e)//查看队头元素
{
	if (IsEmptyLQueue(Q) == TRUE)
	{
		return FALSE;
	}
	*e = (Q->front)->data;
	return TRUE;
}