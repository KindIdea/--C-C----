#ifndef _LKQUEUE_H_
#define _LKQUEUE_H_

#include "common.h"
typedef int elemType;
typedef struct node
{
    elemType Data;
	struct node *ptNext;
}t_lkQueueNode;

typedef struct lkqueue
{
	t_lkQueueNode  *ptFront;
	t_lkQueueNode  *ptRear;
	t_lkQueueNode  *ptCur;
    int  	        iLength;
}t_LkQueue;
WORD lkqueueInit(t_LkQueue *ptq);
WORD lkqueueIn(t_LkQueue *ptq, elemType *peInValue);
WORD lkqueueOut(t_LkQueue *ptq, elemType *peOutValue);
WORD lkqueueGet(t_LkQueue *ptq, elemType **peOutValue);
WORD lkqueueLength(t_LkQueue *ptq, int *piOutLength);
WORD lkqueueEmpty(t_LkQueue *ptq);
WORD lkqueueClear(t_LkQueue *ptq);
WORD lkqueueDestroy(t_LkQueue *ptq);

#endif 
