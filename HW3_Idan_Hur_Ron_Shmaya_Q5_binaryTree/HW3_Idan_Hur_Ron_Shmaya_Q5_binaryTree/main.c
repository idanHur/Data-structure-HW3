#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "treeSearch.h"


int main() 
{
	tree_ptr tree = initTree();
	int x = 0;
	while (x != -1)
	{
		printf("enter value to add in Tree or -1 to exit\n");
		scanf("%d", &x);
		if (x != -1)
			addToTree(&tree, x);
	}
	printf("----------------------------------------------\n");
	printf("Our tree is ---> ");
	printTree(tree);
	printf("\n----------------------------------------------\n");
	int v, u;
	printf("please enter u (the miniom, we print x>=u)\n");
	scanf("%d", &u);
	printf("please enter v (the maximom, we print x<=v)\n");
	scanf("%d", &v);
	printf("the ans of range search (numbers between %d<=x<=%d) ---> ",u,v);
	rangeSearch(tree, u, v);
	puts("");
	system("pause");
}