#include"Double LinkedList.h"
int main()
{


	DuLNode* HEAD = NULL;//����һ��ָ�� ָ��ͷ�ڵ�
	//printf("%p\n", HEAD);
	InitList_DuL(&HEAD);
	assert(HEAD != NULL);
	//printf("%p,%d,%p", HEAD->prior, HEAD->data, HEAD->next);
    //�����ɹ�ͷ�ڵ�


	//ͨ��β����г�ʼ��
	printf("�����ڵ�ĸ���:>\n");
	int num = 0;
	scanf("%d", &num);
	for (int i = 1; i <=num; i++)
	{
		printf("�������%d���ڵ������\n",i);
		int xx = 0;
		scanf("%d",&xx);
		DuLinkedListPushBcak(&HEAD, xx);
	}
	printf("��ʼ���ɹ�\n");
	
	//β��ɹ�
	/*DuLNode* visit = HEAD;
	for (int j =1; j <=num + 1; j++)
	{
		printf("%p,%d,%p\n", visit->prior, visit->data, visit->next);
		visit = visit->next;
	}*/


	//����
	TraverseList_DuL(HEAD);
	//


	//�������
	printf("�������������:>\n");
	int number = 0;
	scanf("%d", &number);
	InsertAfterList_DuL(HEAD, NewNode(number));
	TraverseList_DuL(HEAD);
	//


	//ǰ������
	printf("������ǰ�������:>\n");
	int a = 0;
	scanf("%d", &a);
    InsertBeforeList_DuL(HEAD, NewNode(a));
	TraverseList_DuL(HEAD);
	//


	//ɾ���ڵ�
	printf("������ɾ���Ľڵ��ǰһ���ڵ�ı��ֵ\n");
	int change = 0;
	scanf("%d", &change);
	DeleteList_DuL(HEAD, &change);
	TraverseList_DuL(HEAD);
	return 0;
	//


	//��������
	DestroyList_DuL(&HEAD);
	TraverseList_DuL(HEAD);
	//
}