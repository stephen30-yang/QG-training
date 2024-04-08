#include"binary_sort_tree.h"

Statu initLStack(LinkStack* s)//初始化栈
{
	s->count = 0;
	s->top = NULL;
	return SUCCESS;
}

Statu isEmptyLStack(LinkStack* s)//判断栈是否为空
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

StackNode* NewStackNode(ElemType data)//创建新的节点
{
	StackNode* new = (StackNode*)malloc(sizeof(StackNode));
	assert(new != NULL);
	new->data = data;
	new->next = NULL;
	return new;
}

Statu pushLStack(LinkStack* s, ElemType data)//入栈
{
	//1.生成新节点
	StackNode* New = NewStackNode(data);
	//此时先判断是否为空栈 如果是空栈 那么top指针直接指向这个一个新节点
	if (isEmptyLStack(s) == ERROR)
	{
		s->top = New;
		s->count++;
	}
	else
	{
		//2.新节点的直接后继指向当前的栈顶结点
		New->next = s->top;
		//3.栈顶指针指向新结点
		s->top = New;
		s->count++;
	}
	return SUCCESS;
}

Statu getTopLStack(LinkStack* s, ElemType* e)//得到顶栈元素
{
	//先判断是否为空栈
	if (isEmptyLStack(s) == ERROR)
	{
		//printf("Empty Stack And no Elements\n");
		return ERROR;
	}
	StackNode* UP = s->top;
	*e = UP->data;
	return SUCCESS;
}

Statu popLStack(LinkStack* s, ElemType* data)//出栈
{
	//1.判断是否为空栈
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

Statu InorderpopLStack(LinkStack* s, ElemType* data)//出栈
{
	//1.判断是否为空栈
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