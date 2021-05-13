#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "q2.h"

void q2A()
{
	NODE* pList = creatList(), *reorderdList;
	int x = 0;
	while (x != -1)
	{
		printf("enter value of node or -1 to exit\n");
		scanf("%d", &x);
		if (x != -1)
			addTolist(&pList, x);
	}
	puts("before");
	print(pList);
	puts("after reorder");
	reorderdList = Reorder(pList);
	print(reorderdList);
}
void q2B()
{
	NODE* pList = creatList();
	int x = 0;
	while (x != -1)
	{
		printf("enter value of node or -1 to exit\n");
		scanf("%d", &x);
		if (x != -1)
			addTolist(&pList, x);
	}
	puts("before");
	print(pList);
	puts("after reorder");
	Reorderd(&pList);
	print(pList);
}

int main()
{
	puts("Q2A-----------------------------------------" );
	q2A();
	
	puts("Q2B---------------------------------------- - ");
	q2B();
	system("pause");
}