#include"LargeAmountData.h"

//���c�ļ��������Դ��������²�ͬ��������ʱ��

//��ʼ��һ������
void initarr(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 9999 + 1;//�������1��9999������
	}
} 


int main()
{
	printf("���c�ļ��������Դ��������²�ͬ��������ʱ��\n");
	while (1)
	{
		printf("�����������������:>>>>>\n");
		int num = 0;
		scanf("%d", &num);
		while (num <= 0)
		{
			printf("���ݸ�������!��������\n"); 
			scanf("%d", &num); 
		}
		int* arr = (int*)malloc(sizeof(int) * num);
		if (arr == NULL) {
			printf("�����ڴ�ʧ��!");
			goto another;
		}
		initarr(arr, num);
		printf("����ǰ:>>>>>\n");
		printarr(arr, num);

		menu();
		printf("Tips:��������������,������������е���!\n");
		printf("���������\n");
		int option = 0;
		scanf("%d", &option);

		clock_t start = clock();
		switch (option)
		{
		case 1:insertSort(arr, num); printf("�����:>>>>>\n"); printarr(arr, num); break;
		case 2:
		{
			int* temp = (int*)malloc(sizeof(int) * num);
			if (temp == NULL) {
				printf("�����ڴ�ʧ��!");
				goto another;
			}
			MergeArray(arr, 0, num / 2, num, temp);
			printf("�����:>>>>>\n");
			printarr(arr, num); free(temp); break;
		}
		case 3:
		{
			int* temp = (int*)malloc(sizeof(int) * num);
			if (temp == NULL) {
				printf("�����ڴ�ʧ��!");
				goto another;
			}
			MergeSort(arr, 0, num, temp);
			printf("�����:>>>>>\n");
			printarr(arr, num);
			break;
		}
		case 4:QuickSort_Recursion(arr, 0, num - 1); printf("�����:>>>>>\n"); printarr(arr, num); break;
		case 5:
		{
			//�ҳ����������ֵ
			int max = 0;
			for (int k = 0; k < num; k++) {
				if (arr[k] > max) {
					max = arr[k];
				}
			}
			CountSort(arr, num, max);
			printf("�����:>>>>>\n"); printarr(arr, num); break;
		}
		case 6:RadixCountSort(arr, num); printf("�����:>>>>>\n"); printarr(arr, num); break;
		case 0:exit(1); break;
		default:printf("�������!����������\n"); goto another;
		}
		clock_t diff = clock() - start;
		printf("%d�����ݣ�%d��������ʱ%dms\n", num, option, diff);

	another: system("pause");
		free(arr);
		system("cls");
	}
	return 0;
}