#include"LinkedStack.h"
int main()
{
	menu();

	printf("请输入操作的选项>>\n");
	printf("操作前请先初始化\n");
	int option = 0;
	scanf("%d", &option);
	LinkStack stack;  
	
	
 switch (option)
 {
		case 1:
		{
			//初始化链栈
			initLStack(&stack);
			printf("请再次输入操作\n");
			int option1 = 0;
			scanf("%d", &option1);
			switch (option1)
			{
			  case 4:
			  {
				//判空
				Status judge = (isEmptyLStack(&stack) == ERROR) ? printf("Empty\n") : printf("Not Empty\n");
				//
				break;
			  }

			  case 2:
			  {
				//入栈
				printf("请输入入栈数据个数\n");
				int number = 0;
				scanf("%d", &number);
				for (int i = 1; i <= number; i++)
				{
					printf("请输入入栈数据\n");
					int num = 0;
					scanf("%d", &num);
					pushLStack(&stack, num);
				}
				//
				break;
			  }

			  case 3:
			  {
				//出栈
				printf("请输入出栈数据个数\n");
				int xx = 0;
				scanf("%d", &xx);
				ElemType data_x = -1;
				//
				for (int j = 1; j <= xx; j++)
				{
					popLStack(&stack, &data_x);
				}
				break;
			  }

			  case 5:
			  {
				//获取顶栈元素 
				int updata = 0;
				getTopLStack(&stack, &updata);
				if (stack.top != NULL)
				{
					printf("顶栈的元素是%d\n", updata);
				}
				break;
			  }
			//

			  case 6:
			  {
				//栈长
				ElemType length = 0;
				LStackLength(&stack, &length);
				if (stack.top != NULL)
				{
					printf("栈的长度为%d\n", length);
				}
				//
				break;
			  }

			  case 7:
			  {
				clearLStack(&stack);
				break;
			  }
 
			  case 8:
			  {
				destroyLStack(&stack);
				break;
				printf("销毁成功\n");
				break;
			  }

			}
		}
		break;
		default:
		{
			printf("未初始化\n");
			break;
		}
 }
	
	return 0;
}