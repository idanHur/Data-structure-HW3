#pragma once

typedef int info;
typedef struct node
{
	info value;
	struct node* next;
}Node, *ptr;

//the explanation is in the word doc

void createList(ptr* pList);
int isEmpty(ptr pList);
void insert(Node* pNode, info x);
char* printList(ptr pList); //b
void intToList(ptr pList); //a
void addCure(ptr p); //fix cur
ptr addint(ptr p, ptr q); //c