#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef enum Status {
	ERROR,
	SUCCESS,
} Status;

typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
} DuLNode, * DuLinkedList;

Status InitList_DuL(DuLinkedList* L);

