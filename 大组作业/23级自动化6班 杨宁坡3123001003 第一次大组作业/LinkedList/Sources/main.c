#include"Single LInkedLIst.h"
int main()
{
	//菜单
	menu();
	
	//初始化
	LinkedList L;
	LinkedList tmp = (LinkedList)malloc(sizeof(LNode));
	if (tmp == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);
	}
	L = tmp;
    InitListHead(L);
	//初始化头节点成功
	//printf("%d %p", L->data, L->next);
	int num = 0;
	printf("请输入节点个数(数量别太多嗷）\n");
	scanf("%d", &num);
;	for (int i = 1; i <= num; i++)
	{
	  printf("请输入第%d个节点的数据:>",i);
	  int a = 0;
	  scanf("%d", &a);
	  SListPushBack(&L, a);
	}
     printf("初始化成功\n");
	//

	 //遍历链表
	 TraverseList(L);
	 printf("\n");
	

	 //按位插入
	 printf("请输入插入的数据\n");
	 int xx = 0;
	 scanf("%d", &xx);
	 InsertList(L->next, Newnode(xx));
	 TraverseList(L);
	 //
	 

	 //查询链表
	 printf("请输入想查找的元素:>");
	 int x = 0;
	 scanf("%d", &x);
	 SearchList(L, x);
	 //


	 //删除节点
	 int y = 0;
	 scanf("%d", &y);
	 DeleteList(L->next,&y);
	 TraverseList(L);
	 //


	return 0;
}