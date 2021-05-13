#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "q1.h"




void q1A()
{
	QueueNode* pList = createQueue();
	int choice = 0,x =0,flag =0;
	while (choice != -1)
	{
		printf("\n1. To cheack if Empty \n2. To add new value \n3. Delete node \n4. Print list \n-1. To exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("The list is empty? : %s\n", isEmptyQueue(pList) == 1 ? "Yes" : "No");//is the queneNode empty cheak
			break;
		case 2://insert to queneNode cheack
			printf("Enter a value to insert :");
			scanf("%d", &x);
			insert(&pList, x);
			break;
		case 3:
			if (pList = pList->next)//if there is only 1 node we will need to put Q=NULL and not garbeg
				flag = 1;
			delafter(pList, &x);
			printf("returnd deleted value is : %d \n", x);
			if (flag)
				pList = createQueue();
			flag = 0;
			break;
					
			case 4:
				printf("the list is:\n");//prints the queneNode cheak
				PrintQueue(pList);
				break;
		}
	}
}
void q1B()
{
	QueueNode* queue = createQueue();
	int n, k,returnd = -1;
	printf("please enter the number of soldiers -->(n) ");
	scanf("%d", &n);
	printf("please enter the number of jumps -->(k) ");
	scanf("%d", &k);
	for (int i = 1; i <= n; i++)//insert new soldiers
		insert(&queue, i);
	printf("order of elimination: ");
	while (queue != queue->next)//do intl last soldier 
	{
		for (int i = 0; i < k - 1; i++)
		{
			queue = queue->next;
		}
		delafter(queue, &returnd);//delete by order of elimination after delet will start at the next node after deleted by it self that is how the quene works
		printf("%d ", returnd);
	}
	printf("\nLeader : %d\n", queue->value);
}

int main()
{
	puts("Q1A-----------------------------------------");
	q1A();

	puts("Q1B---------------------------------------- - ");
	q1B();
	system("pause");
}