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

Node* NewTreeNode(ElemType x)//�����µĽڵ�
{
	Node* newtreenode = (Node*)malloc(sizeof(Node));
	assert(newtreenode!=NULL);
	newtreenode->left = NULL;
	newtreenode->right = NULL;
	newtreenode->value = x; 
	return newtreenode; 
} 

Status BST_insert(BinarySortTreePtr T, ElemType x)//����������Ĳ���
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
                printf("����ʧ��\n");
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

Status BST_search(BinarySortTreePtr T, ElemType x)//����������Ĳ���
{
    Node* Search = T->root;
    while (Search!=NULL){
        if (x == Search->value)
        {
            printf("%dԪ�ش���\n", x);
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
    //���ܹ�����ѭ�� ��ô��ʱSearchָ��ָ��NULL Ԫ�ز�����
    if (Search == NULL) {
        printf("%dԪ�ز�����\n", x);
        return failed;
    }
}

Node* BST_searchAddress(BinarySortTreePtr T, ElemType x)//����������Ĳ��� ���ҷ��ظ�Ԫ�����ڽڵ�ĵ�ַ
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
    //���ܹ�����ѭ�� ��ô��ʱSearchָ��ָ��NULL Ԫ�ز�����
    if (Search == NULL) {
        printf("%dԪ�ز�����\n", x);
        return NULL;   
    }
}

Status BST_delete(BinarySortTreePtr T, ElemType x)//����������нڵ��ɾ�� ��ǰ���滻
{
    //1.���ж���Ҫɾ����Ԫ���Ƿ����
    Status JudgeExist = BST_search(T, x);
    if (JudgeExist == failed){
        printf("%dԪ�ز�����,�޷�ɾ��\n",x);
        return failed;
    }
    //����->����ɾ�� 
    //���ɾ�����ǵ�һ�����ڵ�  
    if (x == (T->root)->value) { 
        Node* pdelete = T->root;     
        //��ǰ��
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
        //�Һ��
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

    //���ǵ�һ�����ڵ�����
    Node* pdelete = T->root; 
    Node* prev = T->root;

    //��ɾ���Ľڵ�pdelete�������һ�����ڵ�prev
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
    
    //1.ɾ��Ҷ�ӽڵ� Ҳ���Ǹýڵ�����Һ��Ӷ��ǿ�
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
    //2.�ڵ�ֻ��һ�����ӻ����Һ��ӵ�ʱ��
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
    //3.�ڵ������Һ���
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

Status BST_preorderR(NodePtr T, void (*visit)(NodePtr N)) //�ݹ��������
{ 
    if (T == NULL) { 
        return true;
    }
    visit(T); 
    BST_preorderR(T->left, visit); 
    BST_preorderR(T->right, visit);
}

Status BST_inorderR(NodePtr T, void (*visit)(NodePtr N))//�ݹ��������
{
    if (T == NULL) {
        return true;
    }
    BST_inorderR(T->left, visit); 
    visit(T); 
    BST_inorderR(T->right, visit);  
}

Status BST_postorderR(NodePtr T, void (*visit)(NodePtr N))//�ݹ�������
{
    if (T == NULL) {
        return true;
    }
    BST_postorderR(T->left, visit); 
    BST_postorderR(T->right, visit); 
    visit(T);
}

Status BST_preorderI(BinarySortTreePtr T)//�ǵݹ�������� 
{
    Node* p = T->root;
    LinkStack stack;
    initLStack(&stack);
    int x = 0;
    pushLStack(&stack, p->value);
    popLStack(&stack, &x);//Ԫ�س�ջ���Ҵ�ӡ
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
        //�жϺ�ʱ����ѭ�� �������һ��Ԫ�ص�ʱ�� ���Ԫ�����ڽڵ�����Һ��Ӷ�û�У����Ҵ�ʱΪ��ջ
        if ((Address->left == NULL && Address->right == NULL) && isEmptyLStack(&stack) == ERROR) {
            break;
        }
    }
    return succeed;
}

Status BST_inorderI(BinarySortTreePtr T)//�ǵݹ��������
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
        //�߳���pΪ��
        InorderpopLStack(&stack, &x);//��ջ���Ҵ�ӡ  
        p = BST_searchAddress(T, x);//pָ���ջԪ�����ڽڵ�
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

Status BST_postorderI(BinarySortTreePtr T)//�ǵݹ�������
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

Status BST_levelOrder(BinarySortTreePtr T)//��α���
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


