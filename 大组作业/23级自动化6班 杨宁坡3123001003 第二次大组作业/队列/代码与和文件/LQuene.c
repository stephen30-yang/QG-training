#include"LQuene.h"
int main()
{
	//初始化
	LQueue quene;
	InitLQueue(&quene);
	printf("初始化成功\n");
    //  

	//入队
	printf("请输入创建的节点个数\n");
	int num = 0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		printf("第%d个节点的数据;>",i);
		int data = 0;
		scanf("%d", &data);
		EnLQueue(&quene, data);
		printf("\n");
	}
	printf("入队成功\n");

	//出队
	printf("请输入出队次数\n");
	int count = 0;
	scanf("%d", &count);
	for (int j = 1; j <= count; j++)
	{
		DeLQueue(&quene);
	}
	//

	//判断是否空队列
	(IsEmptyLQueue(&quene) == TRUE) ? printf("Empty/n") : printf("Not Empty\n");
	//

	//队列长度
	int length= LengthLQueue(&quene);
	printf("队列长度为%d\n", length);
	//

	//遍历
	TraverseLQueue(&quene);
	//

	//得到队头元素
	ElemType TopElem = 0;
	GetHeadLQueue(&quene, &TopElem); 
	printf("队头元素为%d\n", TopElem);
	//

	//清空队列
	 ClearLQueue(&quene);
	 printf("清空成功\n");
	 printf("%p		%llu		%p",quene.front,quene.length,quene.rear );
	 //

	return 0;
}