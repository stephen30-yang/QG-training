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
	DataType data;//数据域
	struct LNode* next;//指向下一个节点的指针
}LNode,*LinkedList;

Status InitListHead(LinkedList L);//初始化头节点

LNode* Newnode(int data);//创建新节点

void SListPushBack(LNode** pp, DataType x);//尾插数据 用于初始化

void TraverseList(LinkedList L);//遍历链表

Status InsertList(LNode* p, LNode* q);//插入节点

Status SearchList(LinkedList L, DataType e);//查询链表

Status DeleteList(LNode* p, DataType* e);//删除节点

int JudgeNumberQuantity(LinkedList L);//判断链表元素个数