#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;                   //数据域指针
    struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node* front;                   //队头
    Node* rear;                    //队尾
    size_t length;            //队列长度 size_t==long unsigned int x64平台下
} LQueue;   

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;  

Node* Newnode(ElemType data);//创建新的节点

void InitLQueue(LQueue* Q);//初始化一个队列

Status EnLQueue(LQueue* Q, ElemType data);//入队

Status DeLQueue(LQueue* Q);//出队

int LengthLQueue(LQueue* Q);//确定队列长度

Status IsEmptyLQueue(const LQueue* Q);//判断队列是否为空

Status TraverseLQueue(const LQueue* Q);//遍历队列

Status GetHeadLQueue(LQueue* Q, ElemType* e);//得到队头元素

void ClearLQueue(LQueue* Q);//清空队列