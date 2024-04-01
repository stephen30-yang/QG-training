#include"SmallAmountData_HighFrequency.h"

void initarr(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 9999 + 1;//�������1��9999������
	}
}


//���c�ļ���������С�����ݵ������ ��ͬ���򷽷���������ʱ��
int main()
{
	printf("���c�ļ���������С�����ݵ������ ��ͬ���򷽷���������ʱ��\n");
	while (1)
	{
		printf("������ÿ���������ݵ�����(1��200):>>>>\n");
		int num = 0;
		scanf("%d", &num);
		while (num <= 0 || num > 200) {
			printf("������������!����������\n");
			scanf("%d", &num);
		}
		
		printf("�������������:>>>>\n");
		int count = 0;
		scanf("%d", &count);
		

		menu();
		printf("���������:>>>>.\n");
		int option = 0;
		scanf("%d", &option); 
		switch (option)
		{
		case 1:
		{
			clock_t start = clock();//
			for (int i = 1; i <= count; i++)
			{
				int* arr = (int*)malloc(sizeof(int) * num); 
				if (arr == NULL) { 
					printf("�����ڴ�ʧ��!"); 
					goto another;  
				}
				initarr(arr, num); 
				printf("��%d������:>>>>\n", i);
				insertSort(arr, num);
				printarr(arr, num);
				free(arr);
			}
			clock_t diff = clock() - start;
			printf("%d������,����%d��,��ʱ%dms\n",num,count,diff); 
			break;
		}
		case 2:
		{
			clock_t start = clock();
			for (int i = 1; i <= count; i++)
			{
				int* arr = (int*)malloc(sizeof(int) * num);
				if (arr == NULL) {
					printf("�����ڴ�ʧ��!");
					goto another;
				}
				int* temp = (int*)malloc(sizeof(int) * num);
				if (temp == NULL) {
					printf("�����ڴ�ʧ��!");
					goto another;
				}
				initarr(arr, num);
				printf("��%d������:>>>>\n", i);
				MergeArray(arr, 0, num / 2, num, temp);
				printarr(arr, num); 
				free(arr); 
				free(temp); 
			}
			clock_t diff = clock() - start; 
			printf("%d������,����%d��,��ʱ%dms\n", num, count, diff); 
			break;
		}
		case 3:
		{
			clock_t start = clock();    
			for (int i = 1; i <= count; i++)
			{
				int* arr = (int*)malloc(sizeof(int) * num); 
				if (arr == NULL) { 
					printf("�����ڴ�ʧ��!"); 
					goto another; 
				}
				int* temp = (int*)malloc(sizeof(int) * num); 
				if (temp == NULL) { 
					printf("�����ڴ�ʧ��!"); 
					goto another; 
				}
				initarr(arr, num); 
				printf("��%d������:>>>>\n", i); 
				MergeSort(arr, 0, num, temp);
				printarr(arr, num); 
				free(arr); 
				free(temp); 
			}
			clock_t diff = clock() - start; 
			printf("%d������,����%d��,��ʱ%dms\n", num, count, diff); 
			break; 
		}
		case 4:
		{
			clock_t start = clock(); 
			for (int i = 1; i <= count; i++) 
			{
				int* arr = (int*)malloc(sizeof(int) * num); 
				if (arr == NULL) {  
					printf("�����ڴ�ʧ��!"); 
					goto another; 
				}
				initarr(arr, num); 
				printf("��%d������:>>>>\n", i);  
				QuickSort_Recursion(arr, 0, num - 1);
				printarr(arr, num); 
				free(arr); 
			}
			clock_t diff = clock() - start; 
			printf("%d������,����%d��,��ʱ%dms\n", num, count, diff);   
			break;
		}
		case 5:
		{
			clock_t start = clock();
			for (int i = 1; i <= count; i++) 
			{ 
				int* arr = (int*)malloc(sizeof(int) * num); 
				if (arr == NULL) { 
					printf("�����ڴ�ʧ��!"); 
					goto another; 
				}
				initarr(arr, num); 
				//�ҳ����������ֵ
				int max = 0;
 				for (int k = 0; k < num; k++) {
 					if (arr[k] > max) {
 						max = arr[k];
					}
 				}
				//
				printf("��%d������:>>>>\n", i); 
				CountSort(arr, num, max);
				printarr(arr, num); 
				free(arr); 
			}
			clock_t diff = clock() - start; 
			printf("%d������,����%d��,��ʱ%dms\n", num, count, diff);  
			break;
		} 
		case 6:
		{
			clock_t start = clock(); 
			for (int i = 1; i <= count; i++)
			{
				int* arr = (int*)malloc(sizeof(int) * num);
				if (arr == NULL) {
					printf("�����ڴ�ʧ��!");
			 		goto another;
				}
				initarr(arr, num);
				printf("��%d������:>>>>\n", i);
				RadixCountSort(arr, num);
				printarr(arr, num); 
				free(arr);
			}
			clock_t diff = clock() - start; 
			printf("%d������,����%d��,��ʱ%dms\n", num, count, diff);  
			break; 
		}
		case 0:exit(1); break;
		default:printf("�������!����������\n"); goto another; 
		}
	another:system("pause");
		system("cls");
	}





















	return 0;
}

