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

Status InitList_DuL(DuLinkedList* L);//����ͷ�ڵ㣨��ʼ����

DuLNode* NewNode(int data);//����һ���µĽڵ� ������������

void DuLinkedListPushBcak(DuLNode** ppHEAD,ElemType data);//β��

void TraverseList_DuL(DuLinkedList L);//��������б�����

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q);//��ĳ���ڵ�֮���������

Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q);//ĳ���ڵ�֮ǰ��������

Status DeleteList_DuL(DuLNode* p, ElemType* e);//ɾ��p��ĵ�һ���ڵ� ���ҽ�p�ڵ��������ĳ�e

void DestroyList_DuL(DuLinkedList* L);//������������




