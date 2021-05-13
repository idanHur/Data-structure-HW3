#pragma once

typedef int queueinfo;
typedef struct node
{
	queueinfo value;
	struct node* next;
}QueueNode;



QueueNode* createQueue();// creates an empty queue
int isEmptyQueue(queueinfo* Q);// returns 1 if the queue is empty, 0 if not
void insert(QueueNode** Q, queueinfo x);// inserts item x at the rear of the queue Q.
void delafter(QueueNode* p, queueinfo* x);// deletes the node after node p from the list, and stores its contents in x.
void PrintQueue(QueueNode* Q);// prints the contents of the queue