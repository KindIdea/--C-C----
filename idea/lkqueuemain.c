#include "lkqueue.h"
#include <stdio.h>
void menu();
void InputElem(elemType * peValue);
void OutputElem(elemType * peValue);

void main()
{
	t_LkQueue S;
    int iState;
	int iChoice;
	int iFlag = 1;

    lkqueueInit(&S);
	while(iFlag)
	{
        menu();
		printf("\t请选择菜单号(0--6)：");
        fflush(stdin);
		scanf("%d",&iChoice);

		switch(iChoice)
		{
		case 0:
			{
				iFlag=0;
				break;
			}
        case 1:
            {
				elemType eValue;
				printf("请输入进栈的值：");
				InputElem(&eValue);
				
				iState = lkqueueIn(&S,&eValue);
				if (TRUE == iState)
				{
					printf("进对成功！");
				}
			
				break;
                
            }
		case 2:
			{
				elemType eValue;
			
				iState = lkqueueOut(&S,&eValue);
				if (TRUE == iState)
				{
					printf("出对成功！值为:");
					OutputElem(eValue);
				}
			    if
				{
					printf("对空，没有任何值!");			
				}
				break;
			
			}
		case 3:
			{
				elemType *eValue;

				iState = seqStackPop(&S,&eValue);
				if (TRUE == iState)
				{
					printf("出栈成功！值为:");
					OutputElem(eValue);
				}
				else 
				{
					printf("栈空，没有任何值!");			
				}
				break;
			}
		case 4:
			{
                 elemType *eValue;
                
                iState = seqStackGet(&S,&eValue);
                if (TRUE == iState)
                {
                    printf("栈顶的值为:");
                    OutputElem(eValue);
                }
                else
                {
                    printf("栈空，栈顶元素不存在！");			
                }
				break;
			}
		case 5:
			{
                iState = seqStackFull(&S);
                if (TRUE == iState)
                {
                    printf("栈已满！");
                }
                else 
                {
                    printf("栈未满！");
                }
				break;
			}
		case 6:
			{
                iState = seqStackEmpty(&S);
                if (TRUE == iState)
                {
                    printf("栈为空！");
                }
                else 
                {
                    printf("栈不空！");
                }
				break;
			}
		default:
			{
                printf("选择功能序号不合法！请重新选择指定功能！");
				break;
			}
		}
    }
}

void menu()
{
    printf("\n");
    printf("\n***********************************************");
    printf("\n*              顺  序 栈 子 系 统              *");
    printf("\n***********************************************");
    printf("\n*          0----------返       回             *");
    printf("\n*          1----------遍       历             *");
    printf("\n*                                             *");
    printf("\n*          2----------进       栈             *");
    printf("\n*          3----------出       栈             *");
    printf("\n*          4----------取栈顶 元素             *");
    printf("\n*                                             *");
    printf("\n*          5----------判  栈   空             *");
    printf("\n*          6----------判  栈   满             *");
    printf("\n***********************************************\n");

}

void InputElem(elemType * peValue)
{
    scanf("%d",peValue);
}

void OutputElem(elemType * peValue)
{
    printf("%d ", *peValue);
}
