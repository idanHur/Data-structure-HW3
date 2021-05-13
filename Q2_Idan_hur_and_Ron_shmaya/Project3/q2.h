#pragma once


typedef struct node
{
	int key;
	struct node *next;
}NODE;

NODE* creatList();//Create an empty list
NODE* lastNodeInList(NODE* pList);//parameter: pointer to start of list ,return: the last node in the list 
NODE* addTolist(NODE** pList,int value);//parameter: pointer to start of list and value of new node ,return: pointer to new node, what does: add to end of list
NODE* Reorder(NODE* head);//reuired methode  
void Reorderd(NODE** head);//reuired methode cant have same name as reorder so we added a "d"
NODE* insert(NODE** pNode, int value);//parameter: pointer to node and value of new node ,return: new node ,what does:function add new node after the node that had been given in parameter
void print(NODE* pList);//parameter: pointer to start of list, what does: print list