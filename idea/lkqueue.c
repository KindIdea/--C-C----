#include "lkqueue.h"

WORD lkqueueInit(t_LkQueue *ptq)
{
    // 判断是否合法
	if (NULL == ptq)
	{
		return ILLEGAL;
	}
	ptq->ptFront = NULL;
	ptq->ptRear = NULL;
	ptq->ptCur = NULL;
	ptq->iLength = 0;
	
	return TRUE;
	
}
WORD lkqueueIn(t_LkQueue *ptq, elemType *peInValue)
{
	// 判断是否合法
	if (NULL == ptq)
	{
		return ILLEGAL;
	}
    // 申请节点空间
	ptq->ptCur = (t_lkQueueNode *)malloc(sizeof(t_lkQueueNode));
	
	if (NULL == ptq->ptCur)
	{
		return OVERFLOW;
	}
	ptq->ptCur->Data = *peInValue;
	ptq->ptCur->ptNext = NULL;
	
	if ((NULL == ptq->ptRear) && (NULL == ptq->ptFront) )
	{
		ptq->ptFront = ptq->ptCur;	
	}
	else
	{
		ptq->ptRear->ptNext = ptq->ptCur;
	}
	
    ptq->ptRear = ptq->ptCur;
	
	ptq->iLength++;
	
	return TRUE;
	
}
WORD lkqueueOut(t_LkQueue *ptq, elemType *peOutValue)
{
	// 判断是否合法
	if (NULL == ptq)
	{
		return ILLEGAL;
	}
	
	if (TRUE == lkqueueEmpty(ptq))
	{
		return FALSE;
	}
	
	ptq->ptCur = ptq->ptFront;
	ptq->ptFront = ptq->ptFront->ptNext;
	if (NULL == ptq->ptFront)// 当只有一个结点出对时
	{
		ptq->ptRear = NULL;
	}
	
	
	*peOutValue = ptq->ptFront->Data;
	
	free(ptq->ptCur);
	
	ptq->iLength--;
	
	return TRUE;
}
WORD lkqueueGet(t_LkQueue *ptq, elemType **peOutValue)// 注意返回值
{
	// 判断是否合法
	if (NULL == ptq)
	{
		return ILLEGAL;
	}
	
	if (TRUE == lkqueueEmpty(ptq))
	{
		return FALSE;
	}
	// 返回值 
	*peOutValue = &(ptq->ptFront->Data);
	
	return TRUE;
}
WORD lkqueueLength(t_LkQueue *ptq, int *piOutLength)
{	// 判断是否合法
	if (NULL == ptq)
	{
		return ILLEGAL;
	}
	*piOutLength = ptq->iLength;
	
	
	return TRUE;
}
WORD lkqueueEmpty(t_LkQueue *ptq)
{
	// 判断是否合法
	if (NULL == ptq)
	{
		return ILLEGAL;
	}
	if ((NULL == ptq->ptRear) &&  (NULL == ptq->ptFront))
	{
		return TRUE;
	} 
	else
	{
		return FALSE;
	}
	
}

WORD lkqueueClear(t_LkQueue *ptq)
{// 判断是否合法
	if (NULL == ptq)
	{
		return ILLEGAL;
	}
	ptq->ptCur = ptq->ptFront;
	while (NULL != ptq->ptCur)
	{
		t_lkQueueNode *pTemp;
		
		pTemp = ptq->ptCur;

		ptq->ptCur = ptq->ptCur->ptNext;

		free(pTemp);
		
	}
	ptq->ptFront = NULL;
	ptq->ptRear = NULL;
	ptq->iLength = 0;

	return TRUE;
}
WORD lkqueueDestroy(t_LkQueue *ptq)
{
	return TRUE;
}