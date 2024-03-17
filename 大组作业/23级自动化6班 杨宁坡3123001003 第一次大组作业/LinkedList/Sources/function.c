#include"Single LInkedLIst.h"
void menu()
{
	printf("********************************             ********************************\n");
	printf("                                请选择你的操作                               \n");
	printf("                         1.初始化链表  2.插入新节点\n");
	printf("                         3.输出链表    4.删除节点\n");
	printf("                         5.查询链表    6.退出系统\n");
}

Status InitListHead(LinkedList L)//头节点
{
	L->data = 0;
	L->next = NULL;
	return SUCCESS;
}

LNode* Newnode(DataType data)//创建新的节点
{
	LNode* new = (LNode*)malloc(sizeof(LNode));
	if (new == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	new->data = data;
	new->next = NULL;
	return new;
}

void SListPushBack(LNode** pp, DataType x)//尾插数据(最末尾） 
{
	LNode* newnode = Newnode(x);
	if (*pp == NULL)
	{
		*pp = newnode;
	}
	else
	{
	//找到尾节点插入
		LNode* tail = *pp;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

 void TraverseList(LinkedList L)//遍历链表
{
	LNode* visit = L->next;
	while (visit)
	{
		printf("%d->", visit->data);
		visit = visit->next;
	}
	printf("NULL\n");
}


Status InsertList(LNode* p, LNode* q)//让p为第一个节点开始找 p接受为第一个节点的地址也就是L->next q为newnode
{
	//p后面插入一个q  q其实是新生成的一个节点 -> 找到p节点
	printf("请输入在第几个节点后插入数据\n");
	int x = 0;
	scanf("%d", &x);
	int count = 1;
	while (count < x)
	{
		p =p->next;
		count++;
	}
	//跳出循环后Find指针指向p节点
	//q节点为newnode
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

Status SearchList(LinkedList L, DataType e)//查询链表
{
	LNode* Find = L->next;
	while (1)
	{
		//判断是否为想找的元素
		if (Find->data == e)
		{
			printf("该元素存在\n");
			break;
		}
		Find = Find->next;
		if (Find == NULL)
		{
			printf("该元素不存在\n");
			break;
		}
	}
	return SUCCESS;
}

Status DeleteList(LNode* p, DataType* e)//LNode*p =L->next 找到想要删除的位数的前一位
{
	printf("请输入删除的元素的位数:>");
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

int JudgeNumberQuantity(LinkedList L)//判断链表元素个数
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
