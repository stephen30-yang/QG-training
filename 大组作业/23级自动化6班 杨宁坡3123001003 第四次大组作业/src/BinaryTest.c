#include"binary_sort_tree.h"

int main()
{
	printf("由于时间有点赶，交互界面来不及做了，只写完了函数的定义，下面仅展示实现的功能\n");
	BinarySortTree Tree;

	printf("1.初始化一个树\n");
	BST_init(&Tree);
	printf("Tree.root=%p\n", Tree.root);

	printf("插入了一些数据\n");
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

	printf("非递归先序遍历\n");
	BST_preorderI(&Tree); 
	printf("\n");

	printf("非递归中序遍历\n");
	BST_inorderI(&Tree);
	printf("\n");

	printf("非递归后序遍历\n");
	BST_postorderI(&Tree);
	printf("\n"); 

	printf("层级遍历\n");
	BST_levelOrder(&Tree);
	printf("\n");

	printf("递归先序遍历\n");
	BST_preorderR(Tree.root, print);    
	printf("\n");  

	printf("递归中序遍历\n");
	BST_inorderR(Tree.root, print);  
	printf("\n");  

	printf("递归后序遍历\n");
	BST_postorderR(Tree.root, print);  
	printf("\n");   

	printf("查找元素\n");
	BST_search(&Tree, 3);   
	BST_search(&Tree, 6);     
	BST_search(&Tree, 11);   
	printf("\n");

	printf("删除元素\n");
	BST_delete(&Tree, 5);  
	BST_delete(&Tree, 8);   
	BST_delete(&Tree, 7);
	printf("\n");

	printf("删除后\n");

	printf("非递归先序遍历\n");
	BST_preorderI(&Tree);
	printf("\n");

	printf("非递归中序遍历\n");
	BST_inorderI(&Tree);
	printf("\n");

	printf("非递归后序遍历\n");
	BST_postorderI(&Tree);
	printf("\n");

	printf("层级遍历\n");
	BST_levelOrder(&Tree);
	printf("\n");

	printf("递归先序遍历\n");
	BST_preorderR(Tree.root, print);
	printf("\n");

	printf("递归中序遍历\n");
	BST_inorderR(Tree.root, print);
	printf("\n");

	printf("递归后序遍历\n");
	BST_postorderR(Tree.root, print);
	printf("\n");






	return 0;
}