#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


void createList(ptr* pList)
{
	ptr temp = (ptr)malloc(sizeof(Node));
	*pList = temp;
	(*pList)->next = *pList;
	(*pList)->value = -1;
}
int isEmpty(ptr pList)
{
	if (!pList)
		return 1;
	if (pList->next = pList)
		return 1;
	return 0;
}
void insert(Node* pNode, info x)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->value = x;
	temp->next = pNode->next;
	pNode->next = temp;
	
}

void intToList(ptr pList)
{
	char bigNum[255];
	puts("please enter big number");
	scanf("%s", bigNum);
	Node* p = pList;
	int len = strlen(bigNum),num = 0;
	char numChar[6];
	for (int i = len; i > 5; i = i - 5)
	{
		strcpy(numChar, &bigNum[i - 5]);
		bigNum[i - 5] = '\0';
		sscanf(numChar, "%d", &num);
		insert(p, num);
		p = p->next;
	}
	strcpy(numChar, bigNum);
	sscanf(numChar, "%d", &num);
	insert(p, num);
}

char* printList(ptr pList) {
	char str[255] ="";
	char* ans;
	char num[6];
	if (pList == NULL)
		return;
	if (pList == pList->next)
	{
		puts("List empty");
		return;
	}
	if (pList->next->next->value ==-1)
	{
		printf("%d\n", pList->next->value);
		sprintf(num, "%d", pList->next->value);
		strcat(str, num);
		ans = (char*)malloc(sizeof(char) *strlen(str+1));
		strcpy(ans, str);
		return ans;
	}
	ptr last= pList;
	ptr first = pList;
	do {
		last = last->next;
	} while (last->next->value != -1);
	while (first!=last)
	{
		while (first->next!=last)
			first = first->next;
		
		printf("%d_", last->value);
		sprintf(num, "%d", last->value);
		strcat(str, num);
		last = first;
		first = pList->next;
	}
	printf("%d\n", first->value);
	sprintf(num, "%d", first->value);
	strcat(str, num);
	ans = (char*)malloc(sizeof(char) *strlen(str + 1));
	strcpy(ans, str);
	return ans;
}
ptr addint(ptr p, ptr q)
{
	ptr toAdd;
	int sum = 0;
	if (p->value == -1 && q->value == -1) {
		ptr newList=(ptr)malloc(sizeof(Node));;
		newList->value=-1;
		newList->next = addint(p->next, q->next);
		ptr pos = newList;
		while (pos->next != NULL)
		{
			pos = pos->next;
		}
		pos->next= newList;
		addCure(newList->next);
		return newList;
	}
	else if (p->next->value == -1 && q->next->value == -1) {
		sum = q->value + p->value;
		toAdd = (ptr)malloc(sizeof(Node));
		toAdd->value = sum;
		toAdd->next = NULL;
		return toAdd;
	}
	else if (p->next->value == -1 && q->value == -1) {
		sum =  p->value;
		toAdd = (ptr)malloc(sizeof(Node));
		toAdd->value = sum;
		toAdd->next = NULL;
		return toAdd;
	}
	else if (p->value == -1 && q->next->value == -1) {
		sum = q->value;
		toAdd = (ptr)malloc(sizeof(Node));
		toAdd->value = sum;
		toAdd->next = NULL;
		return toAdd;
	}
	else if(p->value == -1 && q->value != -1) {

		sum = q->value;
		toAdd = (ptr)malloc(sizeof(Node));
		toAdd->value = sum;
		toAdd->next = addint(p, q->next);
		return toAdd;

	}
	else if (p->value != -1 && q->value == -1)
	{
		sum = p->value;
		toAdd = (ptr)malloc(sizeof(Node));
		toAdd->value = sum;
		toAdd->next = addint(p->next, q);
		return toAdd;
	}
	else {
		sum = p->value + q->value;
		toAdd = (ptr)malloc(sizeof(Node));
		toAdd->value = sum;
		toAdd->next =addint(p->next, q->next);
		return toAdd;
	}
}
void addCure(ptr p) {
	int sum = p->value;
	int cur = sum / 100000;
	if (cur != 0) {
		if (p->next->value != -1)
		{
			p->value = sum % 100000;
			sum = p->next->value + cur;
			addCure(p->next, sum);
		}
		else
			insert(p, cur);
	}
	p->value = sum % 100000;
}