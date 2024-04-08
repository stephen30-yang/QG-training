#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int ElemType;

typedef enum Status {
	ERROR,
	SUCCESS,
} Status;

typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
} DuLNode, * DuLinkedList; 

Status InitList_DuL(DuLinkedList* L);//创建头节点（初始化）

DuLNode* NewNode(int data);//创建一个新的节点 可以用作插入

void DuLinkedListPushBcak(DuLNode** ppHEAD,ElemType data);//尾插

void TraverseList_DuL(DuLinkedList L);//对链表进行遍历；

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q);//在某个节点之后插入数据

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q);//某个节点之前插入数据

Status DeleteList_DuL(DuLNode* p, ElemType* e);//删除p后的第一个节点 并且将p节点的数据域改成e

void DestroyList_DuL(DuLinkedList* L);//销毁整个链表




