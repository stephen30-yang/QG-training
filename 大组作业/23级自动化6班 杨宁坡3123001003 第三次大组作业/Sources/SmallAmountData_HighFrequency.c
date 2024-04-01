#include"SmallAmountData_HighFrequency.h"

void initarr(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 9999 + 1;//随机生成1到9999的数据
	}
}


//这个c文件用来测试小量数据的情况下 不同排序方法多次排序的时间
int main()
{
	printf("这个c文件用来测试小量数据的情况下 不同排序方法多次排序的时间\n");
	while (1)
	{
		printf("请输入每次排序数据的数量(1到200):>>>>\n");
		int num = 0;
		scanf("%d", &num);
		while (num <= 0 || num > 200) {
			printf("输入数据有误!请重新输入\n");
			scanf("%d", &num);
		}
		
		printf("请输入排序次数:>>>>\n");
		int count = 0;
		scanf("%d", &count);
		

		menu();
		printf("请输入操作:>>>>.\n");
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
					printf("申请内存失败!"); 
					goto another;  
				}
				initarr(arr, num); 
				printf("第%d次排序:>>>>\n", i);
				insertSort(arr, num);
				printarr(arr, num);
				free(arr);
			}
			clock_t diff = clock() - start;
			printf("%d个数据,排序%d次,用时%dms\n",num,count,diff); 
			break;
		}
		case 2:
		{
			clock_t start = clock();
			for (int i = 1; i <= count; i++)
			{
				int* arr = (int*)malloc(sizeof(int) * num);
				if (arr == NULL) {
					printf("申请内存失败!");
					goto another;
				}
				int* temp = (int*)malloc(sizeof(int) * num);
				if (temp == NULL) {
					printf("申请内存失败!");
					goto another;
				}
				initarr(arr, num);
				printf("第%d次排序:>>>>\n", i);
				MergeArray(arr, 0, num / 2, num, temp);
				printarr(arr, num); 
				free(arr); 
				free(temp); 
			}
			clock_t diff = clock() - start; 
			printf("%d个数据,排序%d次,用时%dms\n", num, count, diff); 
			break;
		}
		case 3:
		{
			clock_t start = clock();    
			for (int i = 1; i <= count; i++)
			{
				int* arr = (int*)malloc(sizeof(int) * num); 
				if (arr == NULL) { 
					printf("申请内存失败!"); 
					goto another; 
				}
				int* temp = (int*)malloc(sizeof(int) * num); 
				if (temp == NULL) { 
					printf("申请内存失败!"); 
					goto another; 
				}
				initarr(arr, num); 
				printf("第%d次排序:>>>>\n", i); 
				MergeSort(arr, 0, num, temp);
				printarr(arr, num); 
				free(arr); 
				free(temp); 
			}
			clock_t diff = clock() - start; 
			printf("%d个数据,排序%d次,用时%dms\n", num, count, diff); 
			break; 
		}
		case 4:
		{
			clock_t start = clock(); 
			for (int i = 1; i <= count; i++) 
			{
				int* arr = (int*)malloc(sizeof(int) * num); 
				if (arr == NULL) {  
					printf("申请内存失败!"); 
					goto another; 
				}
				initarr(arr, num); 
				printf("第%d次排序:>>>>\n", i);  
				QuickSort_Recursion(arr, 0, num - 1);
				printarr(arr, num); 
				free(arr); 
			}
			clock_t diff = clock() - start; 
			printf("%d个数据,排序%d次,用时%dms\n", num, count, diff);   
			break;
		}
		case 5:
		{
			clock_t start = clock();
			for (int i = 1; i <= count; i++) 
			{ 
				int* arr = (int*)malloc(sizeof(int) * num); 
				if (arr == NULL) { 
					printf("申请内存失败!"); 
					goto another; 
				}
				initarr(arr, num); 
				//找出数组中最大值
				int max = 0;
 				for (int k = 0; k < num; k++) {
 					if (arr[k] > max) {
 						max = arr[k];
					}
 				}
				//
				printf("第%d次排序:>>>>\n", i); 
				CountSort(arr, num, max);
				printarr(arr, num); 
				free(arr); 
			}
			clock_t diff = clock() - start; 
			printf("%d个数据,排序%d次,用时%dms\n", num, count, diff);  
			break;
		} 
		case 6:
		{
			clock_t start = clock(); 
			for (int i = 1; i <= count; i++)
			{
				int* arr = (int*)malloc(sizeof(int) * num);
				if (arr == NULL) {
					printf("申请内存失败!");
			 		goto another;
				}
				initarr(arr, num);
				printf("第%d次排序:>>>>\n", i);
				RadixCountSort(arr, num);
				printarr(arr, num); 
				free(arr);
			}
			clock_t diff = clock() - start; 
			printf("%d个数据,排序%d次,用时%dms\n", num, count, diff);  
			break; 
		}
		case 0:exit(1); break;
		default:printf("输入错误!请重新输入\n"); goto another; 
		}
	another:system("pause");
		system("cls");
	}





















	return 0;
}

