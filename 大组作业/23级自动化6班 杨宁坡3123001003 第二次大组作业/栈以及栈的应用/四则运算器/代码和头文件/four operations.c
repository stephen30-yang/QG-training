#include"head.h"

int main()
{

	//初始化栈********************************************************************
	charLinkStack stack;
	initcharLStack(&stack);//存放运算符

	intLinkStack intstack;
	initintLStack(&intstack);//存放数字

	char express[200] = { '0' };
	printf("请输入一个长度不超过200的四则运算表达式(包括符号)\n");
	printf("tips>:计算的结果是以整型表达的\n");
	scanf("%s", express);

	//将中缀表达式转化为后缀表达式**********************************************************
	//遍历后缀表达式  可以在遍历后缀表达式的过程中穿插计算操作数字打印出来后就入栈 打印字符（运算符号的时候进行计算）

	for (int i = 0; i < strlen(express); i++)//先把每一个数字和运算符抽取出来
	{
		if (express[i] == '+' || express[i] == '-' || express[i] == '*' || express[i] == '/')
		{
			if (isEmptyLStack(&stack)==ERROR)//空栈的时候直接入栈
			{
				pushLStack(&stack, express[i]);
				continue;
			}

			chartype e = '0';
			if (getTopLStack(&stack, &e) == SUCCESS)//栈顶元素为'('的时候直接入栈
			{
				if (e == '(')
				{
					pushLStack(&stack, express[i]);
					continue;
				}
			}

			chartype ee = '0';
			if (getTopLStack(&stack,&ee)==SUCCESS)//栈顶有元素->     //考虑优先级
			{
				while (compare_opt(ee) >= compare_opt(express[i]))
				{
					popLStack(&stack, &ee);
					printf("%c ", ee);//此时出栈的运算符->进行运算  intstack里面的前两个元素

					ElemType value1 = 0;   
					popintLStack(&intstack, &value1);  
					ElemType value2 = 0;  
					popintLStack(&intstack, &value2);  
					int new_value = calculate(value2 ,value1,ee);//计算 
					pushLintStack(&intstack, new_value);//再入栈  
				//	int xx= 0; 
				//	getTopLintStack(&intstack, &xx);

					//判断是否空栈了
					if (isEmptyLStack(&stack) == ERROR)
					{
						break;
					}
					 getTopLStack(&stack, &ee);
				}
				pushLStack(&stack, express[i]);//将当前运算符入栈
			}

		}

		else if (express[i] == '(')//左括号直接入栈
		{
			pushLStack(&stack, express[i]);
		}

		else if (express[i] == ')')//将栈顶的运算符出栈，出栈再出栈，直到左括号。括号不作输出
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
					int newvalue = calculate(value2, value1, getop);//计算 
					pushLintStack(&intstack, newvalue);//再入栈 
				//		int xx= 0;
				//		getTopLintStack(&intstack, &xx);

					getTopLStack(&stack, &getop);
				}
				if (getop == '(')
				{
					break;
				}
			}
			popLStack(&stack, &getop);//把左括号进行出栈
		}

		else//数字 直接输出并且进行入栈  
			//这里有个问题 输出的数字是字符而不是数字 需要进行转化
		{
			char numberlist[20];
			int index = 0;
			printf("%c", express[i]);
			numberlist[index++] = express[i];
			int j ;
			for (j = 1; i + j < strlen(express); j++)//拿到一个完整的数字
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
			//将numberlist数组里的数字字符转化为整型数据
			numberlist[index++] = '\0';
			int value = atoi(numberlist);
			pushLintStack(&intstack, value); //数字入栈
		}
	}
	//结束时把栈剩余数据出栈到空为止
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
		int newvalue = calculate(value2, value1, ex);//计算   
		pushLintStack(&intstack, newvalue);//再入栈   
			//int xx= 0;  
			//getTopLintStack(&intstack, &xx);         
	}
//********************************************************************************	

//计算后缀表达式******************************************************************

	int TopElem = 0;
	getTopLintStack(&intstack, &TopElem);
	printf("\nthe result=%d", TopElem);
	return 0;
}