#include"binary_sort_tree.h"

int main()
{
	printf("����ʱ���е�ϣ������������������ˣ�ֻд���˺����Ķ��壬�����չʾʵ�ֵĹ���\n");
	BinarySortTree Tree;

	printf("1.��ʼ��һ����\n");
	BST_init(&Tree);
	printf("Tree.root=%p\n", Tree.root);

	printf("������һЩ����\n");
	BST_insert(&Tree, 5);
	BST_insert(&Tree, 9);
	BST_insert(&Tree, 7); 
	BST_insert(&Tree, 2); 
	BST_insert(&Tree, 3);
	BST_insert(&Tree, 1); 
	BST_insert(&Tree, 10); 
	BST_insert(&Tree, 11);
	BST_insert(&Tree, 4);
	printf("\n");

	printf("�ǵݹ��������\n");
	BST_preorderI(&Tree); 
	printf("\n");

	printf("�ǵݹ��������\n");
	BST_inorderI(&Tree);
	printf("\n");

	printf("�ǵݹ�������\n");
	BST_postorderI(&Tree);
	printf("\n"); 

	printf("�㼶����\n");
	BST_levelOrder(&Tree);
	printf("\n");

	printf("�ݹ��������\n");
	BST_preorderR(Tree.root, print);    
	printf("\n");  

	printf("�ݹ��������\n");
	BST_inorderR(Tree.root, print);  
	printf("\n");  

	printf("�ݹ�������\n");
	BST_postorderR(Tree.root, print);  
	printf("\n");   

	printf("����Ԫ��\n");
	BST_search(&Tree, 3);   
	BST_search(&Tree, 6);     
	BST_search(&Tree, 11);   
	printf("\n");

	printf("ɾ��Ԫ��\n");
	BST_delete(&Tree, 5);  
	BST_delete(&Tree, 8);   
	BST_delete(&Tree, 7);
	printf("\n");

	printf("ɾ����\n");

	printf("�ǵݹ��������\n");
	BST_preorderI(&Tree);
	printf("\n");

	printf("�ǵݹ��������\n");
	BST_inorderI(&Tree);
	printf("\n");

	printf("�ǵݹ�������\n");
	BST_postorderI(&Tree);
	printf("\n");

	printf("�㼶����\n");
	BST_levelOrder(&Tree);
	printf("\n");

	printf("�ݹ��������\n");
	BST_preorderR(Tree.root, print);
	printf("\n");

	printf("�ݹ��������\n");
	BST_inorderR(Tree.root, print);
	printf("\n");

	printf("�ݹ�������\n");
	BST_postorderR(Tree.root, print);
	printf("\n");






	return 0;
}