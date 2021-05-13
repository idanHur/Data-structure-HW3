#include <stdio.h>
#include <stdlib.h>
#include "q2.h"

NODE* creatList()
{
	return NULL;
}

NODE* lastNodeInList(NODE* pList)
{
	if (!pList)
		return NULL;
	NODE* p = pList;
	while (p->next)
	{
		p = p->next;
	}
	return p;
}
NODE* addTolist(NODE** pList, int value)
{
	NODE* lastNode, *toAdd = (NODE*)malloc(sizeof(NODE));
	toAdd->key = value;
	toAdd->next = NULL;
	if (!*pList)
		*pList = toAdd;
	else
	{
		lastNode = lastNodeInList(*pList);
		lastNode->next = toAdd;
	}
	return toAdd;
}
NODE* insert(NODE** pNode, int value)
{
	NODE* temp, *toAdd = (NODE*)malloc(sizeof(NODE));
	toAdd->key = value;
	toAdd->next = NULL;
	if (!(*pNode))
		*pNode = toAdd;
	else
	{
		temp = (*pNode)->next;
		(*pNode)->next = toAdd;
		toAdd->next = temp;
	}
	return toAdd;
}
void Reorderd(NODE** head)
{
	NODE *p = *head, *firstEven = NULL,*temp,*numBeforeFirstEven=NULL,*lastEven=NULL;
	if (!p)
		return;
	while (p)
	{
		if (p->key % 2 == 0)//case the num even
		{
			if (firstEven == NULL)// if is the first even in list
			{
				firstEven = p;//remmember the first even
				lastEven = p;//if is the first even he is the last for now
			}
			else
			{
				lastEven->next = p; //connect between last even to next even
				lastEven = p; //last even move to next even
			}
			p = p->next;
		}
		else if (firstEven != NULL)// num is odd and we had a even number before
		{
			//change all places that necessery
			temp = p->next;
			p->next = firstEven;
			lastEven->next = temp;
			if (numBeforeFirstEven != NULL)
				numBeforeFirstEven->next = p;
			else//case the first num was even
				*head = p;
			numBeforeFirstEven = p;
			p = temp;
		}
		else //case the first numbers was odd
		{
			numBeforeFirstEven = p;
			p = p->next;
		}
	}
}


NODE* Reorder(NODE* head)
{
	NODE* newList, *lastNodeOfOdd = NULL,*p = head;
	if (!p)
		return NULL;
	newList = creatList();
	while (p)
	{
		if (p->key % 2 == 0)
			addTolist(&newList, p->key);
		else
		{
			if (lastNodeOfOdd == NULL)
			{
				insert(&lastNodeOfOdd, p->key);
				lastNodeOfOdd->next = newList;
				newList = lastNodeOfOdd;
			}
			else
				lastNodeOfOdd = insert(&lastNodeOfOdd, p->key);
		}
		p = p->next;
	}
	return newList;
}
void print(NODE* pList)
{
	NODE* p = pList;
	if (!pList)
	{
		printf("empty list\n");
		return;
	}
	printf("The list is:\n");
	while (p)
	{
		printf("%d, ", p->key);
		p = p->next;
	}
	puts("");
}