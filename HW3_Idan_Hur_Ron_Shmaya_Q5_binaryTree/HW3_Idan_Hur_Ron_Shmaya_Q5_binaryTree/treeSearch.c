#include <stdio.h>
#include <stdlib.h>
#include "treeSearch.h"

int		isEmpty(tree_ptr pTree)
{
	if (!pTree)
		return 1;
	return 0;
}
tree_ptr	 buildTree(tree_ptr left, tree_ptr right, itemType value)
{
	tree_ptr temp = (tree_ptr)malloc(sizeof(tree_node));
	if (!temp)
		return NULL;
	temp->info = value;
	temp->left = left;
	temp->right = right;
	return temp;
}
void	 addToTree(tree_ptr* head, itemType value)
{
	if (isEmpty(*head))
	{
		*head = buildTree(NULL, NULL, value);
		return;
	}
	tree_ptr p = *head;
	if (value > p->info)
		if(isEmpty(p->right))
			p->right = buildTree(NULL, NULL, value);
		else
			addToTree(&p->right, value);
	else
		if (isEmpty(p->left))
			p->left = buildTree(NULL, NULL, value);
		else
			addToTree(&p->left, value);
}


tree_ptr initTree()
{
	return NULL;
}
void printTree(tree_ptr head)
{
	if (isEmpty(head))
		return;
	printTree(head->left);
	printf("%d ,", head->info);
	printTree(head->right);
}

void	rangeSearch(tree_ptr t, itemType u, itemType v)
{
	if (isEmpty(t))
		return;
	if (t->info >= u)
		rangeSearch(t->left, u, v);
	if (t->info <= v && t->info >= u)
		printf("%d ,", t->info);
	if (t->info <= v)
		rangeSearch(t->right, u, v);
}
