#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>

void menu()
{
	printf("*******************************************************\n");
	printf("1.插入排序        **************   2.归并排序递归版\n");
	printf("3.归并排序非递归版**************   4.快速排序非递归版\n");
	printf("5.计数排序        **************   6.基数排序\n");
	printf("**********************0.退出***************************\n ");
	printf("*******************************************************\n");
}

//给定一个正整数 求他是几位数
int judge(long long  x)  //能除以几次10就是几位数 
{
	for (int i = 1; 1; i++)
	{
		x = x / 10;
		if (x == 0)
		{
			return i;
		}
	}
}

int minnum(int x, int y)
{
	return (x < y) ? x : y;
}

void printarr(int* arr, int x)
{
	for (int i = 0; i < x; i++)
	{
		printf("%d\t", *(arr + i));
	}
	printf("\n");
}

void insertSort(int* a, int n)//插入排序  数组指针 a, 数组长度 n
{
	//需要将数组划分为已排序区和未排序区 
	int flag = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i < n; i++)//从第二个数据开始向后走
	{
		int k = i;
		//插入已经排序好的区域 在已排序区内从后向前扫描
		for (j = flag; j >= 0; j--)
		{
			if (*(a + i) < *(a + j))
			{
				//小于就交换
				int temp = 0;
				temp = *(a + i);
				*(a + i) = *(a + j);
				*(a + j) = temp;
				i--;
			}
			else
			{
				break;
			}
		}
		flag++;
		i = k;
	}
}

void MergeArray(int* a, int begin, int mid, int end, int* temp)//归并（合并数组）    
//数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
{
	if (end - begin <= 1) {   //判断还能否对数组再进行拆分
		return;
	}
	//先把数组分成两部分(看做成分离元素，并不是真的拆掉，相当于对元素分区域，元素相对顺序不变，仍然在a数组中)
	MergeArray(a, begin, (begin + mid) / 2, mid, temp);
	MergeArray(a, mid, (mid + end) / 2, end, temp);
	//合并
	//Merge(a, begin, mid, end, temp);
	int i = begin;
	int j = mid;
	int index = 0;
	while (i < mid && j < end) {  //此时begin mid end是相对于分区后的两数组总体而言的
		if (a[i] < a[j]) {
			temp[index++] = a[i++];
		}
		else {
			temp[index++] = a[j++];
		}
	}
	//此时左右两边数组一定还有一个数组会存在元素
	while (i < mid) {
		temp[index++] = a[i++];
	}
	while (j < end) {
		temp[index++] = a[j++];
	}
	for (int i = 0; i < index; i++) {
		a[begin + i] = temp[i];
	}
}

void MergeSort(int* a, int begin, int end, int* temp)
{
	//每次取2的次方个元素出来  分成一半 排序好顺序后存储在承载数组当中，再返回给原数组
	//索取元素个数大于原数组元素的个数的时候，就不在索取元素
	int getelem = 1;//代表每次取(2^getelem)个元素 eg：第一次将元素两个两个取 第二次四个四个拿
	int istart = 0;
	for (getelem = 1; getelem < end; getelem = getelem * 2) {
		for (istart = 0; istart < end; istart = istart + getelem * 2) {  //左包右不包
			//对每一段小区间进行排序 每一段小区间分成二等分 此时还需要考虑不够区间应有个数的区间怎么操作
			//istart是每一段小区间的起点  getelem*2是区间长度
			int ilow = istart;//起点
			int imid = minnum(ilow + getelem, end);//中点
			int imax = minnum(ilow + getelem * 2, end);//终点
			//ilow到imid-1排序 imid到imax-1排序
			int index = 0;//用来存储在承载数组
			//此时将小区间拆分成两个区间
			int ibegin1 = ilow;
			int iend1 = imid;
			int ibegin2 = imid;
			int iend2 = imax;//左包有不包
			while (ibegin1 < iend1 && ibegin2 < iend2) {
				if (a[ibegin1] < a[ibegin2]) {
					temp[index++] = a[ibegin1++];
				}
				else {
					temp[index++] = a[ibegin2++];
				}
			}
			while (ibegin1 < iend1)
				temp[index++] = a[ibegin1++];
			while (ibegin2 < iend2)
				temp[index++] = a[ibegin2++];
			for (int k = 0; k < index; k++) {
				a[istart + k] = temp[k];
			}
		}
	}
}

void QuickSort_Recursion(int* a, int begin, int end)//快速排序递归版(左闭右闭)
{
	if (begin >= end) {
		return;
	}
	int i = begin;
	int j = end;
	int pivot = a[i];
	while (i < j) {
		while (i < j && a[j] >= pivot) {
			j--;
		}
		a[i] = a[j];
		while (i < j && a[i] <= pivot) {
			i++;
		}
		a[j] = a[i];
	}
	a[i] = pivot;
	QuickSort_Recursion(a, begin, i - 1);
	QuickSort_Recursion(a, i + 1, end);
}

void CountSort(int* a, int size, int max)//计数排序  数组指针a，数组长度size，数组最大值max
{
	int temp[10000] = { 0 };
	/*int* temp = (int*)malloc(sizeof(int) * max);
	if (temp == NULL) {
		printf("内存申请失败!\n");
		return;
	}*/
	//if (max > 999) {
		//printf("您输入的最大值超过上限,请重新输入\n");
		//return;
	//}
	int index = 0;
	for (int i = 0; i < size; i++) {  //统计
		temp[a[i]]++;
	}
	//此时需要还原temp数组 temp数组下标代表a数组的元素 下标解引用的元素是该元素出现的次数
	for (int k = 0; k < max + 1; k++) {
		//判断此时temp[k]解引用的值是否为0 为0则跳过
		if (temp[k] != 0)
		{   //k元素出现的次数不为0
			for (int j = 1; j <= temp[k]; j++) {
				a[index++] = k;
			}
		}
	}
	/*free(temp);*/
}

void RadixCountSort(int* a, int size)//基数排序 数组指针a，数组长度size
{

	int Temp[10][20000] = { 0 };
	int i;
	int j;
	int pos;
	for (int k = 10; k < 100000; k *= 10)
	{
		for (i = 0; i < size; i++)
		{
			j = 0;
			pos = (a[i] % k) / (k / 10);
			while (Temp[pos][j])
			{
				j++;
			}
			Temp[pos][j] = a[i];
		}
		pos = 0;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < size && Temp[i][j] != 0; j++)
			{
				a[pos++] = Temp[i][j];
				Temp[i][j] = 0;
			}
		}
	}
}