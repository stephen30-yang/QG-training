#include"head.h"

int main()
{

	//��ʼ��ջ********************************************************************
	charLinkStack stack;
	initcharLStack(&stack);//��������

	intLinkStack intstack;
	initintLStack(&intstack);//�������

	char express[200] = { '0' };
	printf("������һ�����Ȳ�����200������������ʽ(��������)\n");
	printf("tips>:����Ľ���������ͱ���\n");
	scanf("%s", express);

	//����׺���ʽת��Ϊ��׺���ʽ**********************************************************
	//������׺���ʽ  �����ڱ�����׺���ʽ�Ĺ����д������������ִ�ӡ���������ջ ��ӡ�ַ���������ŵ�ʱ����м��㣩

	for (int i = 0; i < strlen(express); i++)//�Ȱ�ÿһ�����ֺ��������ȡ����
	{
		if (express[i] == '+' || express[i] == '-' || express[i] == '*' || express[i] == '/')
		{
			if (isEmptyLStack(&stack)==ERROR)//��ջ��ʱ��ֱ����ջ
			{
				pushLStack(&stack, express[i]);
				continue;
			}

			chartype e = '0';
			if (getTopLStack(&stack, &e) == SUCCESS)//ջ��Ԫ��Ϊ'('��ʱ��ֱ����ջ
			{
				if (e == '(')
				{
					pushLStack(&stack, express[i]);
					continue;
				}
			}

			chartype ee = '0';
			if (getTopLStack(&stack,&ee)==SUCCESS)//ջ����Ԫ��->     //�������ȼ�
			{
				while (compare_opt(ee) >= compare_opt(express[i]))
				{
					popLStack(&stack, &ee);
					printf("%c ", ee);//��ʱ��ջ�������->��������  intstack�����ǰ����Ԫ��

					ElemType value1 = 0;   
					popintLStack(&intstack, &value1);  
					ElemType value2 = 0;  
					popintLStack(&intstack, &value2);  
					int new_value = calculate(value2 ,value1,ee);//���� 
					pushLintStack(&intstack, new_value);//����ջ  
				//	int xx= 0; 
				//	getTopLintStack(&intstack, &xx);

					//�ж��Ƿ��ջ��
					if (isEmptyLStack(&stack) == ERROR)
					{
						break;
					}
					 getTopLStack(&stack, &ee);
				}
				pushLStack(&stack, express[i]);//����ǰ�������ջ
			}

		}

		else if (express[i] == '(')//������ֱ����ջ
		{
			pushLStack(&stack, express[i]);
		}

		else if (express[i] == ')')//��ջ�����������ջ����ջ�ٳ�ջ��ֱ�������š����Ų������
		{
			char getop = '0';
			while (getTopLStack(&stack, &getop)==SUCCESS)
			{
				if (getop != '(')
				{
					popLStack(&stack, &getop);
					printf("%c ", getop);

					ElemType value1 = 0; 
					popintLStack(&intstack, &value1); 
					ElemType value2 = 0;  
					popintLStack(&intstack, &value2); 
					int newvalue = calculate(value2, value1, getop);//���� 
					pushLintStack(&intstack, newvalue);//����ջ 
				//		int xx= 0;
				//		getTopLintStack(&intstack, &xx);

					getTopLStack(&stack, &getop);
				}
				if (getop == '(')
				{
					break;
				}
			}
			popLStack(&stack, &getop);//�������Ž��г�ջ
		}

		else//���� ֱ��������ҽ�����ջ  
			//�����и����� ������������ַ����������� ��Ҫ����ת��
		{
			char numberlist[20];
			int index = 0;
			printf("%c", express[i]);
			numberlist[index++] = express[i];
			int j ;
			for (j = 1; i + j < strlen(express); j++)//�õ�һ������������
			{
				if (express[i + j] >= '0' && express[i + j] <= '9')
				{
					printf("%c", express[i+j]);
					numberlist[index++] = express[i + j];
				}
				else
				{
					i = i + j - 1;
					printf(" ");
					break;
				}
			}
			//��numberlist������������ַ�ת��Ϊ��������
			numberlist[index++] = '\0';
			int value = atoi(numberlist);
			pushLintStack(&intstack, value); //������ջ
		}
	}
	//����ʱ��ջʣ�����ݳ�ջ����Ϊֹ
	printf(" ");
	while (isEmptyLStack(&stack)!=ERROR)
	{
		char ex = '0';
		popLStack(&stack, &ex);
		printf("%c ", ex);
		 
		ElemType value1 = 0;   
		popintLStack(&intstack, &value1);   
		ElemType value2 = 0;   
		popintLStack(&intstack, &value2);   
		int newvalue = calculate(value2, value1, ex);//����   
		pushLintStack(&intstack, newvalue);//����ջ   
			//int xx= 0;  
			//getTopLintStack(&intstack, &xx);         
	}
//********************************************************************************	

//�����׺���ʽ******************************************************************

	int TopElem = 0;
	getTopLintStack(&intstack, &TopElem);
	printf("\nthe result=%d", TopElem);
	return 0;
}