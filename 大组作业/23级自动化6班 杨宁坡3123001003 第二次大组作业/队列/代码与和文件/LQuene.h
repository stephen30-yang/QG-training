#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;                   //������ָ��
    struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node* front;                   //��ͷ
    Node* rear;                    //��β
    size_t length;            //���г��� size_t==long unsigned int x64ƽ̨��
} LQueue;   

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;  

Node* Newnode(ElemType data);//�����µĽڵ�

void InitLQueue(LQueue* Q);//��ʼ��һ������

Status EnLQueue(LQueue* Q, ElemType data);//���

Status DeLQueue(LQueue* Q);//����

int LengthLQueue(LQueue* Q);//ȷ�����г���

Status IsEmptyLQueue(const LQueue* Q);//�ж϶����Ƿ�Ϊ��

Status TraverseLQueue(const LQueue* Q);//��������

Status GetHeadLQueue(LQueue* Q, ElemType* e);//�õ���ͷԪ��

void ClearLQueue(LQueue* Q);//��ն���