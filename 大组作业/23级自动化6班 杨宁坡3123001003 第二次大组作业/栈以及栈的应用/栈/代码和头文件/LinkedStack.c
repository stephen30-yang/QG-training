#include"LinkedStack.h"
int main()
{
	menu();

	printf("�����������ѡ��>>\n");
	printf("����ǰ���ȳ�ʼ��\n");
	int option = 0;
	scanf("%d", &option);
	LinkStack stack;  
	
	
 switch (option)
 {
		case 1:
		{
			//��ʼ����ջ
			initLStack(&stack);
			printf("���ٴ��������\n");
			int option1 = 0;
			scanf("%d", &option1);
			switch (option1)
			{
			  case 4:
			  {
				//�п�
				Status judge = (isEmptyLStack(&stack) == ERROR) ? printf("Empty\n") : printf("Not Empty\n");
				//
				break;
			  }

			  case 2:
			  {
				//��ջ
				printf("��������ջ���ݸ���\n");
				int number = 0;
				scanf("%d", &number);
				for (int i = 1; i <= number; i++)
				{
					printf("��������ջ����\n");
					int num = 0;
					scanf("%d", &num);
					pushLStack(&stack, num);
				}
				//
				break;
			  }

			  case 3:
			  {
				//��ջ
				printf("�������ջ���ݸ���\n");
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
				//��ȡ��ջԪ�� 
				int updata = 0;
				getTopLStack(&stack, &updata);
				if (stack.top != NULL)
				{
					printf("��ջ��Ԫ����%d\n", updata);
				}
				break;
			  }
			//

			  case 6:
			  {
				//ջ��
				ElemType length = 0;
				LStackLength(&stack, &length);
				if (stack.top != NULL)
				{
					printf("ջ�ĳ���Ϊ%d\n", length);
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
				printf("���ٳɹ�\n");
				break;
			  }

			}
		}
		break;
		default:
		{
			printf("δ��ʼ��\n");
			break;
		}
 }
	
	return 0;
}