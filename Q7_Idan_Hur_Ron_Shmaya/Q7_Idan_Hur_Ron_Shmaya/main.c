#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


int main()
{
	ptr firstList,*secondList,*sumList;
	char* firstNum,*second,*sum;

	createList(&firstList);
	puts("========================\nfirst big number--->");
	intToList(firstList);
	createList(&secondList);
	puts("========================\nsecond big number--->");
	intToList(secondList);
	int pick = 0;
	do {
		puts("1. to see first number.\n2. to see second number.\n3. to see sum of two numbers.\n-1 to Exit");
		scanf("%d", &pick);
		switch (pick)
		{
		case 1:
			puts("the list--->");
			firstNum=printList(firstList);
			printf("the number: %s\n", firstNum);
			break;
		case 2:
			puts("the list--->");
			second = printList(secondList);
			printf("the number: %s\n", second);
			break;
		case 3:
			sumList=addint(firstList, secondList);
			puts("the sum list--->");
			sum = printList(sumList);
			printf("the number: %s\n", sum);
			break;
		}

	} while (pick != -1);
}