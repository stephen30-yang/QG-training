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
	printf("1.��������        **************   2.�鲢����ݹ��\n");
	printf("3.�鲢����ǵݹ��**************   4.��������ǵݹ��\n");
	printf("5.��������        **************   6.��������\n");
	printf("**********************0.�˳�***************************\n ");
	printf("*******************************************************\n");
}

//����һ�������� �����Ǽ�λ��
int judge(long long  x)  //�ܳ��Լ���10���Ǽ�λ�� 
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

void insertSort(int* a, int n)//��������  ����ָ�� a, ���鳤�� n
{
	//��Ҫ�����黮��Ϊ����������δ������ 
	int flag = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i < n; i++)//�ӵڶ������ݿ�ʼ�����
	{
		int k = i;
		//�����Ѿ�����õ����� �����������ڴӺ���ǰɨ��
		for (j = flag; j >= 0; j--)
		{
			if (*(a + i) < *(a + j))
			{
				//С�ھͽ���
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

void MergeArray(int* a, int begin, int mid, int end, int* temp)//�鲢���ϲ����飩    
//����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
{
	if (end - begin <= 1) {   //�жϻ��ܷ�������ٽ��в��
		return;
	}
	//�Ȱ�����ֳ�������(�����ɷ���Ԫ�أ���������Ĳ�����൱�ڶ�Ԫ�ط�����Ԫ�����˳�򲻱䣬��Ȼ��a������)
	MergeArray(a, begin, (begin + mid) / 2, mid, temp);
	MergeArray(a, mid, (mid + end) / 2, end, temp);
	//�ϲ�
	//Merge(a, begin, mid, end, temp);
	int i = begin;
	int j = mid;
	int index = 0;
	while (i < mid && j < end) {  //��ʱbegin mid end������ڷ������������������Ե�
		if (a[i] < a[j]) {
			temp[index++] = a[i++];
		}
		else {
			temp[index++] = a[j++];
		}
	}
	//��ʱ������������һ������һ����������Ԫ��
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
	//ÿ��ȡ2�Ĵη���Ԫ�س���  �ֳ�һ�� �����˳���洢�ڳ������鵱�У��ٷ��ظ�ԭ����
	//��ȡԪ�ظ�������ԭ����Ԫ�صĸ�����ʱ�򣬾Ͳ�����ȡԪ��
	int getelem = 1;//����ÿ��ȡ(2^getelem)��Ԫ�� eg����һ�ν�Ԫ����������ȡ �ڶ����ĸ��ĸ���
	int istart = 0;
	for (getelem = 1; getelem < end; getelem = getelem * 2) {
		for (istart = 0; istart < end; istart = istart + getelem * 2) {  //����Ҳ���
			//��ÿһ��С����������� ÿһ��С����ֳɶ��ȷ� ��ʱ����Ҫ���ǲ�������Ӧ�и�����������ô����
			//istart��ÿһ��С��������  getelem*2�����䳤��
			int ilow = istart;//���
			int imid = minnum(ilow + getelem, end);//�е�
			int imax = minnum(ilow + getelem * 2, end);//�յ�
			//ilow��imid-1���� imid��imax-1����
			int index = 0;//�����洢�ڳ�������
			//��ʱ��С�����ֳ���������
			int ibegin1 = ilow;
			int iend1 = imid;
			int ibegin2 = imid;
			int iend2 = imax;//����в���
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

void QuickSort_Recursion(int* a, int begin, int end)//��������ݹ��(����ұ�)
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

void CountSort(int* a, int size, int max)//��������  ����ָ��a�����鳤��size���������ֵmax
{
	int temp[10000] = { 0 };
	/*int* temp = (int*)malloc(sizeof(int) * max);
	if (temp == NULL) {
		printf("�ڴ�����ʧ��!\n");
		return;
	}*/
	//if (max > 999) {
		//printf("����������ֵ��������,����������\n");
		//return;
	//}
	int index = 0;
	for (int i = 0; i < size; i++) {  //ͳ��
		temp[a[i]]++;
	}
	//��ʱ��Ҫ��ԭtemp���� temp�����±����a�����Ԫ�� �±�����õ�Ԫ���Ǹ�Ԫ�س��ֵĴ���
	for (int k = 0; k < max + 1; k++) {
		//�жϴ�ʱtemp[k]�����õ�ֵ�Ƿ�Ϊ0 Ϊ0������
		if (temp[k] != 0)
		{   //kԪ�س��ֵĴ�����Ϊ0
			for (int j = 1; j <= temp[k]; j++) {
				a[index++] = k;
			}
		}
	}
	/*free(temp);*/
}

void RadixCountSort(int* a, int size)//�������� ����ָ��a�����鳤��size
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