#include"Single LInkedLIst.h"
int main()
{
	//�˵�
	menu();
	
	//��ʼ��
	LinkedList L;
	LinkedList tmp = (LinkedList)malloc(sizeof(LNode));
	if (tmp == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	L = tmp;
    InitListHead(L);
	//��ʼ��ͷ�ڵ�ɹ�
	//printf("%d %p", L->data, L->next);
	int num = 0;
	printf("������ڵ����(������̫��໣�\n");
	scanf("%d", &num);
;	for (int i = 1; i <= num; i++)
	{
	  printf("�������%d���ڵ������:>",i);
	  int a = 0;
	  scanf("%d", &a);
	  SListPushBack(&L, a);
	}
     printf("��ʼ���ɹ�\n");
	//

	 //��������
	 TraverseList(L);
	 printf("\n");
	

	 //��λ����
	 printf("��������������\n");
	 int xx = 0;
	 scanf("%d", &xx);
	 InsertList(L->next, Newnode(xx));
	 TraverseList(L);
	 //
	 

	 //��ѯ����
	 printf("����������ҵ�Ԫ��:>");
	 int x = 0;
	 scanf("%d", &x);
	 SearchList(L, x);
	 //


	 //ɾ���ڵ�
	 int y = 0;
	 scanf("%d", &y);
	 DeleteList(L->next,&y);
	 TraverseList(L);
	 //


	return 0;
}