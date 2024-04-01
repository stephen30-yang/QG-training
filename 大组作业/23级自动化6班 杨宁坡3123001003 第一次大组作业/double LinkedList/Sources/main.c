#include"Double LinkedList.h"
int main()
{


	DuLNode* HEAD = NULL;//创建一个指针 指向头节点
	//printf("%p\n", HEAD);
	InitList_DuL(&HEAD);
	assert(HEAD != NULL);
	//printf("%p,%d,%p", HEAD->prior, HEAD->data, HEAD->next);
    //创建成功头节点


	//通过尾插进行初始化
	printf("创建节点的个数:>\n");
	int num = 0;
	scanf("%d", &num);
	for (int i = 1; i <=num; i++)
	{
		printf("请输入第%d个节点的数据\n",i);
		int xx = 0;
		scanf("%d",&xx);
		DuLinkedListPushBcak(&HEAD, xx);
	}
	printf("初始化成功\n");
	
	//尾插成功
	/*DuLNode* visit = HEAD;
	for (int j =1; j <=num + 1; j++)
	{
		printf("%p,%d,%p\n", visit->prior, visit->data, visit->next);
		visit = visit->next;
	}*/


	//遍历
	TraverseList_DuL(HEAD);
	//


	//后插数据
	printf("请输入后插的数据:>\n");
	int number = 0;
	scanf("%d", &number);
	InsertAfterList_DuL(HEAD, NewNode(number));
	TraverseList_DuL(HEAD);
	//


	//前插数据
	printf("请输入前插的数据:>\n");
	int a = 0;
	scanf("%d", &a);
    InsertBeforeList_DuL(HEAD, NewNode(a));
	TraverseList_DuL(HEAD);
	//


	//删除节点
	printf("请输入删除的节点的前一个节点改变的值\n");
	int change = 0;
	scanf("%d", &change);
	DeleteList_DuL(HEAD, &change);
	TraverseList_DuL(HEAD);
	return 0;
	//


	//销毁链表
	DestroyList_DuL(&HEAD);
	TraverseList_DuL(HEAD);
	//
}