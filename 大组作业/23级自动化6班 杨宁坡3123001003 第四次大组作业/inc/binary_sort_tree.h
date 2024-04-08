#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define Status int

typedef int ElemType;

//************������*********************
typedef struct Node {
    ElemType value; 
    struct Node* left, * right; 
}Node, * NodePtr;  //���Ľڵ�

typedef struct BinarySortTree { 
    NodePtr root;
} BinarySortTree, * BinarySortTreePtr; 

void print(NodePtr N);

Status BST_init(BinarySortTreePtr T);//��ʼ��һ����

Node* NewTreeNode(ElemType x);//�����µĽڵ�

Status BST_insert(BinarySortTreePtr T, ElemType x);//����������Ĳ��� 

Status BST_search(BinarySortTreePtr T, ElemType x);//����������Ĳ���

Node* BST_searchAddress(BinarySortTreePtr T, ElemType x);//����������Ĳ��� ���ҷ��ظ�Ԫ�����ڽڵ�ĵ�ַ

Status BST_delete(BinarySortTreePtr T, ElemType x);//����������нڵ��ɾ��      

Status BST_preorderR(NodePtr T, void (*visit)(NodePtr N)); //�ݹ��������

Status BST_inorderR(NodePtr T, void (*visit)(NodePtr N));//�ݹ��������

Status BST_postorderR(NodePtr T, void (*visit)(NodePtr N));//�ݹ�������

Status BST_preorderI(BinarySortTreePtr T);//�ǵݹ��������   

Status BST_inorderI(BinarySortTreePtr T);//�ǵݹ��������

Status BST_postorderI(BinarySortTreePtr T);//�ǵݹ�������

Status BST_levelOrder(BinarySortTreePtr T);//��α���
//***************************************

//***************ջ**********************
typedef enum Statu 
{ 
    ERROR = 0,
    SUCCESS = 1
} Statu; 

typedef  struct StackNode //�ڵ�
{
    ElemType data;
    struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
    LinkStackPtr top;//��ջָ��
    int	count;//ջ��Ԫ�ظ���
}LinkStack;

Statu initLStack(LinkStack* s);//��ʼ��ջ

Statu isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��

StackNode* NewStackNode(ElemType data);//����һ���µ���ջ�Ľڵ� ����push

Statu pushLStack(LinkStack* s, ElemType data);//��ջ

Statu popLStack(LinkStack* s, ElemType* data);//��ջ

Statu InorderpopLStack(LinkStack* s, ElemType* data);//��ջ   

Statu getTopLStack(LinkStack* s, ElemType* e);//�õ�ջ��Ԫ��   
//**************************************

//****************����******************
typedef struct quenenode
{
    ElemType data;                   //������ָ��
    struct quenenode* next;            //ָ��ǰ������һ���
} QueneNode; 

typedef struct Lqueue
{
    QueneNode* front;                   //��ͷ
    QueneNode* rear;                    //��β
    size_t length;            //���г��� size_t==long unsigned int x64ƽ̨��
} LQueue;

typedef enum
{
    FALSE = 0, TRUE = 1
} Statuses;  

QueneNode* Newnode(ElemType data);//�����µĽڵ�

void InitLQueue(LQueue* Q);//��ʼ��һ������

Statuses EnLQueue(LQueue* Q, ElemType data);//���

Statuses DeLQueue(LQueue* Q);//���� 

Statuses IsEmptyLQueue(const LQueue* Q);//�ж϶����Ƿ�Ϊ��

Statuses TraverseLQueue(const LQueue* Q);//��������

Statuses GetHeadLQueue(LQueue* Q, ElemType* e);//�õ���ͷԪ��


