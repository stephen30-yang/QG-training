#include"LQuene.h"
int main()
{
	//��ʼ��
	LQueue quene;
	InitLQueue(&quene);
	printf("��ʼ���ɹ�\n");
    //  

	//���
	printf("�����봴���Ľڵ����\n");
	int num = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		printf("��%d���ڵ������;>",i);
		int data = 0;
		scanf("%d", &data);
		EnLQueue(&quene, data);
		printf("\n");
	}
	printf("��ӳɹ�\n");

	//����
	printf("��������Ӵ���\n");
	int count = 0;
	scanf("%d", &count);
	for (int j = 1; j <= count; j++)
	{
		DeLQueue(&quene);
	}
	//

	//�ж��Ƿ�ն���
	(IsEmptyLQueue(&quene) == TRUE) ? printf("Empty/n") : printf("Not Empty\n");
	//

	//���г���
	int length= LengthLQueue(&quene);
	printf("���г���Ϊ%d\n", length);
	//

	//����
	TraverseLQueue(&quene);
	//

	//�õ���ͷԪ��
	ElemType TopElem = 0;
	GetHeadLQueue(&quene, &TopElem); 
	printf("��ͷԪ��Ϊ%d\n", TopElem);
	//

	//��ն���
	 ClearLQueue(&quene);
	 printf("��ճɹ�\n");
	 printf("%p		%llu		%p",quene.front,quene.length,quene.rear );
	 //

	return 0;
}