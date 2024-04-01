#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
void menu();

typedef int DataType;

typedef enum Status {
	ERROR,
	SUCCESS
} Status;

typedef struct LNode
{
	DataType data;//������
	struct LNode* next;//ָ����һ���ڵ��ָ��
}LNode,*LinkedList;

Status InitListHead(LinkedList L);//��ʼ��ͷ�ڵ�

LNode* Newnode(int data);//�����½ڵ�

void SListPushBack(LNode** pp, DataType x);//β������ ���ڳ�ʼ��

void TraverseList(LinkedList L);//��������

Status InsertList(LNode* p, LNode* q);//����ڵ�

Status SearchList(LinkedList L, DataType e);//��ѯ����

Status DeleteList(LNode* p, DataType* e);//ɾ���ڵ�

int JudgeNumberQuantity(LinkedList L);//�ж�����Ԫ�ظ���