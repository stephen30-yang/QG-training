#include"binary_sort_tree.h"

Status BST_init(BinarySortTreePtr TT)
{
	TT->root = NULL;
	return succeed; 
}

void print(NodePtr N)
{
    printf("%d ", N->value);
}

Node* NewTreeNode(ElemType x)//创建新的节点
{
	Node* newtreenode = (Node*)malloc(sizeof(Node));
	assert(newtreenode!=NULL);
	newtreenode->left = NULL;
	newtreenode->right = NULL;
	newtreenode->value = x; 
	return newtreenode; 
} 

Status BST_insert(BinarySortTreePtr T, ElemType x)//排序二叉树的插入
{
    if (T->root == NULL)
    {
        T->root = NewTreeNode(x);
        return succeed;
    }
    else
    {
        Node* pmove = T->root;
        assert(pmove != NULL); 
        while (1)
        {
            if (x == (pmove->value)) {
                printf("插入失败\n");
                return failed;
            }

            else if (x > (pmove->value)) {
                if (pmove->right == NULL)
                {
                    pmove->right = NewTreeNode(x);
                    return succeed;
                }
                else
                {
                    pmove = pmove->right;
                }
            }

            else {
                if (pmove->left == NULL)
                {
                    pmove->left = NewTreeNode(x);
                    return succeed;
                }
                else
                {
                    pmove = pmove->left;
                }
            }

        }
    }
}

Status BST_search(BinarySortTreePtr T, ElemType x)//排序二叉树的查找
{
    Node* Search = T->root;
    while (Search!=NULL){
        if (x == Search->value)
        {
            printf("%d元素存在\n", x);
            return succeed; 
        }

        else if (x > Search->value) 
        {
            Search = Search->right;
        }

        else
        {
            Search = Search->left; 
        }
    }
    //若能够出来循环 那么此时Search指针指向NULL 元素不存在
    if (Search == NULL) {
        printf("%d元素不存在\n", x);
        return failed;
    }
}

Node* BST_searchAddress(BinarySortTreePtr T, ElemType x)//排序二叉树的查找 并且返回该元素所在节点的地址
{
    Node* Search = T->root;    
    while (Search != NULL) {
        if (x == Search->value)
        {
            return Search;
        }

        else if (x > Search->value)
        {
            Search = Search->right;
        }

        else
        {
            Search = Search->left;
        }
    }
    //若能够出来循环 那么此时Search指针指向NULL 元素不存在
    if (Search == NULL) {
        printf("%d元素不存在\n", x);
        return NULL;   
    }
}

Status BST_delete(BinarySortTreePtr T, ElemType x)//排序二叉树中节点的删除 找前继替换
{
    //1.先判断想要删除的元素是否存在
    Status JudgeExist = BST_search(T, x);
    if (JudgeExist == failed){
        printf("%d元素不存在,无法删除\n",x);
        return failed;
    }
    //存在->进行删除 
    //如果删除的是第一个根节点  
    if (x == (T->root)->value) { 
        Node* pdelete = T->root;     
        //找前继
        if (pdelete->left != NULL) {
            pdelete = pdelete->left;
            Node* prior = T->root;
            while (pdelete->right != NULL)
            {
                prior = pdelete; 
                pdelete = pdelete->right;
            }
            ElemType swapdata = 0;
            swapdata=T->root->value; 
            T->root->value = pdelete->value;
            pdelete->value = swapdata; 
            prior->right = NULL;
            free(pdelete);
            return succeed;
        }
        //找后继
        if (pdelete->right != NULL) {
            pdelete = pdelete->right;     
            Node* prior = T->root; 
            while (pdelete->left != NULL)
            {
                prior = pdelete; 
                pdelete = pdelete->left;  
            }
            ElemType swapdata = 0; 
            swapdata = T->root->value; 
            T->root->value = pdelete->value; 
            pdelete->value = swapdata; 
            prior->left = NULL;
            free(pdelete); 
            return succeed; 
        }
        if (pdelete->left == NULL && pdelete->right == NULL)
        {
            free(pdelete);
            T->root = NULL;
            return succeed; 
        }
    }

    //不是第一个根节点的情况
    Node* pdelete = T->root; 
    Node* prev = T->root;

    //找删除的节点pdelete和最近的一个根节点prev
    if (x > prev->value) {
        pdelete = pdelete->right;
        if (pdelete == NULL) {
            printf("not exist\n");
            return failed; 
        }
    }
    if (x < prev->value) { 
        pdelete = pdelete->left; 
        if (pdelete == NULL) { 
            printf("not exist\n"); 
            return failed; 
        }
    }
    while (pdelete != NULL) {
        if (pdelete->value == x)
            break;
        else if (x > pdelete->value){
            prev = pdelete;
            pdelete = pdelete->right;
        }
        else {
            prev = pdelete;
            pdelete = pdelete->left;
        }
    }
    //**********************************************
    
    //1.删除叶子节点 也就是该节点的左右孩子都是空
    if (pdelete->left == NULL && pdelete->right == NULL)
    {
        if (pdelete->value > prev->value) {
            prev->right = NULL;
        }
        if (pdelete->value < prev->value) {
            prev->left = NULL;
        }
        free(pdelete); 
        return succeed; 
    }
    //2.节点只有一个左孩子或者右孩子的时候
    if (pdelete->left != NULL && pdelete->right == NULL)
    {
        if (pdelete->value > prev->value) {
            (prev->right) = pdelete->left;
        }
        if (pdelete->value < prev->value) {
            prev->left = pdelete->left;
        }
        free(pdelete);
        return succeed;
    }
    if (pdelete->left == NULL && pdelete->right != NULL) 
    {
        if (pdelete->value > prev->value) { 
            (prev->right) = pdelete->right; 
        }
        if (pdelete->value < prev->value) {  
            prev->left = pdelete->right;  
        }
        free(pdelete);
        return succeed;
    }
    //3.节点有左右孩子
    if (pdelete->left != NULL && pdelete->right != NULL)
    {
        Node* wantdelete = pdelete;
        prev = pdelete;
        pdelete = pdelete->left;
        while ((pdelete->right) != NULL)
        {
            prev = pdelete;
            pdelete = pdelete->right;
        }
        ElemType swapdata_x = 1;
        swapdata_x = wantdelete->value;
        wantdelete->value = pdelete->value;
        pdelete->value = swapdata_x;
        prev->right = NULL;
        free(pdelete);
        return succeed;
    }
}

Status BST_preorderR(NodePtr T, void (*visit)(NodePtr N)) //递归先序遍历
{ 
    if (T == NULL) { 
        return true;
    }
    visit(T); 
    BST_preorderR(T->left, visit); 
    BST_preorderR(T->right, visit);
}

Status BST_inorderR(NodePtr T, void (*visit)(NodePtr N))//递归中序遍历
{
    if (T == NULL) {
        return true;
    }
    BST_inorderR(T->left, visit); 
    visit(T); 
    BST_inorderR(T->right, visit);  
}

Status BST_postorderR(NodePtr T, void (*visit)(NodePtr N))//递归后序遍历
{
    if (T == NULL) {
        return true;
    }
    BST_postorderR(T->left, visit); 
    BST_postorderR(T->right, visit); 
    visit(T);
}

Status BST_preorderI(BinarySortTreePtr T)//非递归先序遍历 
{
    Node* p = T->root;
    LinkStack stack;
    initLStack(&stack);
    int x = 0;
    pushLStack(&stack, p->value);
    popLStack(&stack, &x);//元素出栈并且打印
    printf("%d ", x);   

    Node* Address = BST_searchAddress(T, x);  
    while (1) {
        if (Address->right != NULL) {
            pushLStack(&stack, (Address->right)->value);
        }
        if (Address->left != NULL) {
            pushLStack(&stack, (Address->left)->value);
        }
        popLStack(&stack, &x);
        printf("%d ", x);    
        Address = BST_searchAddress(T, x);
        //判断何时跳出循环 遍历最后一个元素的时候 这个元素所在节点的左右孩子都没有，并且此时为空栈
        if ((Address->left == NULL && Address->right == NULL) && isEmptyLStack(&stack) == ERROR) {
            break;
        }
    }
    return succeed;
}

Status BST_inorderI(BinarySortTreePtr T)//非递归中序遍历
{
    Node* p = T->root; 
    LinkStack stack; 
    initLStack(&stack); 
    int x = 0; 
    while (1) {
        while (p != NULL) {
            pushLStack(&stack, p->value);
            p = p->left;
        }
        //走出来p为空
        InorderpopLStack(&stack, &x);//出栈并且打印  
        p = BST_searchAddress(T, x);//p指向出栈元素所在节点
        while (1) {
            if (p->right != NULL) {
                p = p->right;
                break;
            } 
            InorderpopLStack(&stack, &x);
            p = BST_searchAddress(T, x);
            if (p->right == NULL && isEmptyLStack(&stack) == ERROR) {
                return succeed;
            }
        }
    }
}

Status BST_postorderI(BinarySortTreePtr T)//非递归后序遍历
{
    LinkStack stack1;
    initLStack(&stack1);
    LinkStack stack2;  
    initLStack(&stack2);
    int topdata = 0;
    int x = 0;
    Node* p = T->root;
    pushLStack(&stack1, p->value);     
    while (1) {
      if (p->left == NULL && p->right == NULL)
      {
          popLStack(&stack1, &x); 
          pushLStack(&stack2, x); 
          getTopLStack(&stack1, &topdata);
          p = BST_searchAddress(T, topdata);
      }
      else {
          popLStack(&stack1, &x);
          pushLStack(&stack2, x);
          if (p->left != NULL) {
              pushLStack(&stack1, (p->left)->value);
              getTopLStack(&stack1, &topdata);
          }
          if (p->right != NULL) {
              pushLStack(&stack1, (p->right)->value);
              getTopLStack(&stack1, &topdata); 
          }
          p = BST_searchAddress(T, topdata);
      }
      if ((p->left == NULL && p->right == NULL) && isEmptyLStack(&stack1)==ERROR) {
          int pop = 0;
          while (isEmptyLStack(&stack2) != ERROR) {
              popLStack(&stack2, &pop);
              printf("%d ", pop);
          }
          return succeed;
      }
    }
}

Status BST_levelOrder(BinarySortTreePtr T)//层次遍历
{
    LQueue quene; 
    InitLQueue(&quene);  
    Node* p = T->root;
    EnLQueue(&quene, p->value);
    int x = 0;
    while (1)
    {
        GetHeadLQueue(&quene, &x);
        printf("%d ", x);
        DeLQueue(&quene);
        if (p->left != NULL) {
            EnLQueue(&quene, (p->left)->value);
        }
        if (p->right != NULL) { 
            EnLQueue(&quene, (p->right)->value);   
        }
        GetHeadLQueue(&quene, &x);
        p = BST_searchAddress(T, x);
        if ((p->left == NULL && p->right == NULL) && IsEmptyLQueue(&quene) == TRUE) {
            return succeed;
        }

    }

}


