#pragma once


typedef int itemType;
typedef struct node
{
	itemType info;
	struct node* left;
	struct node* right;
} tree_node, *tree_ptr;


int			 isEmpty(tree_ptr pTree);//cheack if the tree is empty
tree_ptr	 buildTree(tree_ptr left, tree_ptr right, itemType value);//adds a new brench to tree
tree_ptr	 initTree();//initalizing a new tree 
void		 addToTree(tree_ptr* head, itemType value);//adds a new value to given tree 
void		 printTree(tree_ptr head);
void		 rangeSearch(tree_ptr t, itemType u, itemType v);