#include <stdio.h>
#include <stdlib.h>
#include "q1.h"


QueueNode* createQueue()// creates an empty queue
{
	return NULL;
}
int isEmptyQueue(queueinfo* Q)// returns 1 if the queue is empty, 0 if not
{
	if (!Q)
		return 1;
	return 0;
}
void insert(QueueNode** Q, queueinfo x)// inserts item x at the rear of the queue Q.
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->value = x;
	if (isEmptyQueue(*Q))
		temp->next = temp;
	else {
		temp->next = (*Q)->next;
		(*Q)->next = temp;
	}
	(*Q) = temp;
}
void delafter(QueueNode* p, queueinfo* x)// deletes the node after node p from the list, and stores its contents in x.
{
	if (p == NULL)
		return;
	QueueNode* temp = p->next;
	p->next = temp->next;
	*x = temp->value;
	free(temp);
}
void PrintQueue(QueueNode* Q)// prints the contents of the queue
{
	if (isEmptyQueue(Q))
		return;
	QueueNode* p = Q->next;
	do 
	{
		printf("%d ,", p->value);
		p = p->next;
	}while (p != Q->next);
}