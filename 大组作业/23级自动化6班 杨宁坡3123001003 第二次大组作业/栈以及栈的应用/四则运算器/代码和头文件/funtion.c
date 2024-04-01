#include"head.h"

//1.*********************************************************
Status initcharLStack(charLinkStack* s)//初始化栈
{
	s->count = 0;
	s->top = NULL;
}

Status isEmptyLStack(charLinkStack* s)//判断是否为空栈
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

charStackNode* NewStackNode(chartype data)//创建新的节点
{
	charStackNode* new = (charStackNode*)malloc(sizeof(charStackNode));
	assert(new != NULL);
	new->data = data;
	new->next = NULL;
	return new;
}



Status pushLStack(charLinkStack* s, chartype data)//入栈
{

	//1.生成新节点
	charStackNode* New = NewStackNode(data);
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


Status popLStack(charLinkStack* s, chartype* data)//出栈
{
	//1.判断是否为空栈
	if (isEmptyLStack(s) == ERROR)
	{
		//printf("Empty Stack\n");
		//printf("请重新创建一个栈\n");
		return ERROR;
	}
	charStackNode* pmove = s->top;
	s->top = (s->top)->next;
	s->count--;
	*data = pmove->data;
	//printf("出栈的元素是%d\n", *data);
	free(pmove);
	return SUCCESS;
}

Status getTopLStack(charLinkStack* s, chartype* e)//得到栈顶元素
{
	//先判断是否为空栈
	if (isEmptyLStack(s) == ERROR)
	{
		//printf("Empty Stack And no Elements\n");
		return ERROR;
	}
	charStackNode* UP = s->top;
	*e = UP->data;
	return SUCCESS;
}

int compare_opt (char opt)//计算运算符的优先级
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

int calculate(int value_1, int value_2, char opt)//计算栈顶前两个数据
{
	if (opt == '+')
	{
		return value_1 + value_2;
	}
	if (opt == '-')
	{
		return value_1 - value_2; //先出来的元素作为value_2
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

Status initintLStack(intLinkStack* s)//初始化链栈
{
	s->head = NULL;
	s->size = 0;
}

Status isEmptyintLStack(intLinkStack* s)//判断栈是否为空
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

intStackNode* NewintStackNode(ElemType data)//创建新的节点
{
	intStackNode* new = (intStackNode*)malloc(sizeof(intStackNode));
	assert(new != NULL);
	new->data = data;
	new->nnext = NULL;
	return new;
}

Status pushLintStack(intLinkStack* s, ElemType data)//入栈
{
	//1.生成新节点
	intStackNode* NNew = NewintStackNode(data);
	//此时先判断是否为空栈 如果是空栈 那么top指针直接指向这个一个新节点
	if (isEmptyintLStack(s) == ERROR)
	{
		s->head = NNew; 
		s->size++;
	}
	else
	{
		//2.新节点的直接后继指向当前的栈顶结点
		NNew->nnext = s->head;
		//3.栈顶指针指向新结点
		s->head = NNew;
		s->size++;
	}
	return SUCCESS;
}

Status popintLStack(intLinkStack* s, ElemType* data)//出栈
{

	//1.判断是否为空栈
	if (isEmptyintLStack(s) == ERROR)
	{
		/*printf("Empty Stack\n");
		printf("请重新创建一个栈\n");*/
		return ERROR;
	}
	intStackNode* pmove = s->head;
	s->head = (s->head)->nnext;
	s->size--;
	*data = pmove->data;
	/*printf("出栈的元素是%d\n", *data);*/
	free(pmove);
	return SUCCESS;
}

Status getTopLintStack(intLinkStack* s, ElemType* e)//得到栈顶元素
{
	//先判断是否为空栈
	if (isEmptyintLStack(s) == ERROR)
	{
		//printf("Empty Stack And no Elements\n");
	   	return ERROR; 
	}
	intStackNode* UP = s->head;
	*e = UP->data;
	return SUCCESS; 
}