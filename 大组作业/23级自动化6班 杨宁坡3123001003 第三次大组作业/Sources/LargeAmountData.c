#include"LargeAmountData.h"

//这个c文件用来测试大量数据下不同排序所用时间

//初始化一个数组
void initarr(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 9999 + 1;//随机生成1到9999的数据
	}
} 


int main()
{
	printf("这个c文件用来测试大量数据下不同排序所用时间\n");
	while (1)
	{
		printf("请输入排序的数据量:>>>>>\n");
		int num = 0;
		scanf("%d", &num);
		while (num <= 0)
		{
			printf("数据个数有误!重新输入\n"); 
			scanf("%d", &num); 
		}
		int* arr = (int*)malloc(sizeof(int) * num);
		if (arr == NULL) {
			printf("申请内存失败!");
			goto another;
		}
		initarr(arr, num);
		printf("排序前:>>>>>\n");
		printarr(arr, num);

		menu();
		printf("Tips:数据量大的情况下,插入排序可能有点慢!\n");
		printf("请输入操作\n");
		int option = 0;
		scanf("%d", &option);

		clock_t start = clock();
		switch (option)
		{
		case 1:insertSort(arr, num); printf("排序后:>>>>>\n"); printarr(arr, num); break;
		case 2:
		{
			int* temp = (int*)malloc(sizeof(int) * num);
			if (temp == NULL) {
				printf("申请内存失败!");
				goto another;
			}
			MergeArray(arr, 0, num / 2, num, temp);
			printf("排序后:>>>>>\n");
			printarr(arr, num); free(temp); break;
		}
		case 3:
		{
			int* temp = (int*)malloc(sizeof(int) * num);
			if (temp == NULL) {
				printf("申请内存失败!");
				goto another;
			}
			MergeSort(arr, 0, num, temp);
			printf("排序后:>>>>>\n");
			printarr(arr, num);
			break;
		}
		case 4:QuickSort_Recursion(arr, 0, num - 1); printf("排序后:>>>>>\n"); printarr(arr, num); break;
		case 5:
		{
			//找出数组中最大值
			int max = 0;
			for (int k = 0; k < num; k++) {
				if (arr[k] > max) {
					max = arr[k];
				}
			}
			CountSort(arr, num, max);
			printf("排序后:>>>>>\n"); printarr(arr, num); break;
		}
		case 6:RadixCountSort(arr, num); printf("排序后:>>>>>\n"); printarr(arr, num); break;
		case 0:exit(1); break;
		default:printf("输入错误!请重新输入\n"); goto another;
		}
		clock_t diff = clock() - start;
		printf("%d个数据，%d操作，用时%dms\n", num, option, diff);

	another: system("pause");
		free(arr);
		system("cls");
	}
	return 0;
}