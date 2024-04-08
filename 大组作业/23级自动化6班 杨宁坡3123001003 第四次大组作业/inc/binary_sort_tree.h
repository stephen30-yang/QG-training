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

//************二叉树*********************
typedef struct Node {
    ElemType value; 
    struct Node* left, * right; 
}Node, * NodePtr;  //树的节点

typedef struct BinarySortTree { 
    NodePtr root;
} BinarySortTree, * BinarySortTreePtr; 

void print(NodePtr N);

Status BST_init(BinarySortTreePtr T);//初始化一个树

Node* NewTreeNode(ElemType x);//创建新的节点

Status BST_insert(BinarySortTreePtr T, ElemType x);//排序二叉树的插入 

Status BST_search(BinarySortTreePtr T, ElemType x);//排序二叉树的查找

Node* BST_searchAddress(BinarySortTreePtr T, ElemType x);//排序二叉树的查找 并且返回该元素所在节点的地址

Status BST_delete(BinarySortTreePtr T, ElemType x);//排序二叉树中节点的删除      

Status BST_preorderR(NodePtr T, void (*visit)(NodePtr N)); //递归先序遍历

Status BST_inorderR(NodePtr T, void (*visit)(NodePtr N));//递归中序遍历

Status BST_postorderR(NodePtr T, void (*visit)(NodePtr N));//递归后序遍历

Status BST_preorderI(BinarySortTreePtr T);//非递归先序遍历   

Status BST_inorderI(BinarySortTreePtr T);//非递归中序遍历

Status BST_postorderI(BinarySortTreePtr T);//非递归后序遍历

Status BST_levelOrder(BinarySortTreePtr T);//层次遍历
//***************************************

//***************栈**********************
typedef enum Statu 
{ 
    ERROR = 0,
    SUCCESS = 1
} Statu; 

typedef  struct StackNode //节点
{
    ElemType data;
    struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
    LinkStackPtr top;//顶栈指针
    int	count;//栈中元素个数
}LinkStack;

Statu initLStack(LinkStack* s);//初始化栈

Statu isEmptyLStack(LinkStack* s);//判断栈是否为空

StackNode* NewStackNode(ElemType data);//创建一个新的链栈的节点 方便push

Statu pushLStack(LinkStack* s, ElemType data);//入栈

Statu popLStack(LinkStack* s, ElemType* data);//出栈

Statu InorderpopLStack(LinkStack* s, ElemType* data);//出栈   

Statu getTopLStack(LinkStack* s, ElemType* e);//得到栈顶元素   
//**************************************

//****************队列******************
typedef struct quenenode
{
    ElemType data;                   //数据域指针
    struct quenenode* next;            //指向当前结点的下一结点
} QueneNode; 

typedef struct Lqueue
{
    QueneNode* front;                   //队头
    QueneNode* rear;                    //队尾
    size_t length;            //队列长度 size_t==long unsigned int x64平台下
} LQueue;

typedef enum
{
    FALSE = 0, TRUE = 1
} Statuses;  

QueneNode* Newnode(ElemType data);//创建新的节点

void InitLQueue(LQueue* Q);//初始化一个队列

Statuses EnLQueue(LQueue* Q, ElemType data);//入队

Statuses DeLQueue(LQueue* Q);//出队 

Statuses IsEmptyLQueue(const LQueue* Q);//判断队列是否为空

Statuses TraverseLQueue(const LQueue* Q);//遍历队列

Statuses GetHeadLQueue(LQueue* Q, ElemType* e);//得到队头元素


