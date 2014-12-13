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
		printf("\t��ѡ��˵���(0--6)��");
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
				printf("�������ջ��ֵ��");
				InputElem(&eValue);
				
				iState = lkqueueIn(&S,&eValue);
				if (TRUE == iState)
				{
					printf("���Գɹ���");
				}
			
				break;
                
            }
		case 2:
			{
				elemType eValue;
			
				iState = lkqueueOut(&S,&eValue);
				if (TRUE == iState)
				{
					printf("���Գɹ���ֵΪ:");
					OutputElem(eValue);
				}
			    if
				{
					printf("�Կգ�û���κ�ֵ!");			
				}
				break;
			
			}
		case 3:
			{
				elemType *eValue;

				iState = seqStackPop(&S,&eValue);
				if (TRUE == iState)
				{
					printf("��ջ�ɹ���ֵΪ:");
					OutputElem(eValue);
				}
				else 
				{
					printf("ջ�գ�û���κ�ֵ!");			
				}
				break;
			}
		case 4:
			{
                 elemType *eValue;
                
                iState = seqStackGet(&S,&eValue);
                if (TRUE == iState)
                {
                    printf("ջ����ֵΪ:");
                    OutputElem(eValue);
                }
                else
                {
                    printf("ջ�գ�ջ��Ԫ�ز����ڣ�");			
                }
				break;
			}
		case 5:
			{
                iState = seqStackFull(&S);
                if (TRUE == iState)
                {
                    printf("ջ������");
                }
                else 
                {
                    printf("ջδ����");
                }
				break;
			}
		case 6:
			{
                iState = seqStackEmpty(&S);
                if (TRUE == iState)
                {
                    printf("ջΪ�գ�");
                }
                else 
                {
                    printf("ջ���գ�");
                }
				break;
			}
		default:
			{
                printf("ѡ������Ų��Ϸ���������ѡ��ָ�����ܣ�");
				break;
			}
		}
    }
}

void menu()
{
    printf("\n");
    printf("\n***********************************************");
    printf("\n*              ˳  �� ջ �� ϵ ͳ              *");
    printf("\n***********************************************");
    printf("\n*          0----------��       ��             *");
    printf("\n*          1----------��       ��             *");
    printf("\n*                                             *");
    printf("\n*          2----------��       ջ             *");
    printf("\n*          3----------��       ջ             *");
    printf("\n*          4----------ȡջ�� Ԫ��             *");
    printf("\n*                                             *");
    printf("\n*          5----------��  ջ   ��             *");
    printf("\n*          6----------��  ջ   ��             *");
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
