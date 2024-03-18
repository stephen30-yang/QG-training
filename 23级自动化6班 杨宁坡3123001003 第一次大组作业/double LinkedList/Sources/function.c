#include"Double LinkedList.h"

Status InitList_DuL(DuLinkedList* L)//初始化一个双链表的表头  也就是创建一个头节点
{
	DuLNode* HeadNode = (DuLNode*)malloc(sizeof(DuLNode));
	assert(HeadNode != NULL);
	HeadNode->next = NULL;
	HeadNode->prior = NULL;
	HeadNode->data = 0;//头节点的值不作要求 随便给一个
	*L = HeadNode;
	return SUCCESS;
}

DuLNode* NewNode(int data)//创建新的节点
{
	 DuLNode* newnode = (DuLNode*)malloc(sizeof(DuLNode));
	 if (newnode == NULL)
	 {
		 printf("申请内存失败\n");
		 exit(-1);
	 }
	 newnode->data = data;
	 newnode->next = NULL;
	 newnode->prior = NULL;
	 return newnode;
}


void DuLinkedListPushBcak(DuLNode** ppHEAD,ElemType data)//双链表的尾插  此时*ppHEAD==HEAD
{
	DuLNode* pushbacknode = NewNode(data);
	assert(pushbacknode != NULL);
	//找到最后一个节点
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


void TraverseList_DuL(DuLinkedList L)//遍历双链表 不是很会用函数指针所以就没用
{
	if (L == NULL)
	{
		printf("空链表\n");
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

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q)//p节点后插入q节点    q就是新加入的节点 使用NewNode函数即可
{
	printf("请输入想要在第几个节点后插入数据:>");
	int num = 0;
	scanf("%d", &num);
	if (num == 0)//第0位后插入就是在头节点后插入
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
	//如果是插在最后一个 那么此时p->next为NULL
	//所以这个位置要判断p->next是否为空
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

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q)//p节点之前插入数据 
//与后插情况类似 只不过要考虑在第一个节点之前插入的情况 
{
	p = p->next; 
	printf("请输入想要在第几个节点前插入数据:>");
	int num = 0;
	scanf("%d", &num);
	while (num == 0)
	{
		printf("请重新输入\n");
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
	printf("请输入第几个节点后删除节点:>");
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
		printf("没有节点->无法删除\n");
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


void DestroyList_DuL(DuLinkedList* L)//*L其实是HEAD指针 指向头节点 
{
	DuLNode* pmove = *L;
	while (pmove->next!=NULL)
	{
		pmove = pmove->next;
	}
	//此时pmove指针指向最后一个节点
	pmove = pmove->prior;//让pomve指向倒数第二个节点
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
	printf("链表位置%p", *L);
	printf("此时为空链表\n");
}