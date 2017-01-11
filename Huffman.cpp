#include "Huffman.h"
#include <iostream>
#include <string.h>
Huffman::Huffman()
{
	this->root = new struct tree;
	struct tree* r = this->root;
	*r = {this->head,0,0};
	this->size = 0;
}
Huffman::Huffman(MyNode node)
{
	this->head = new struct node;
	*this->head = {0,0,0,0};
	/** check It's null or not.
	if(node == 0)
	{
		std::cout << "error: NULL POINTER in Huffman(MyNode node)!\n";
		exit(1);
	}
	*/
	if(node.isEmpty())
	{
		std::cout << "warning: initial from null, nothing to do\n";
		return;
	}
	struct node* h = node.getHeadAhead()->next;
	struct node* t = h->prev;
	if(h == t)
	{
		this->addElement(h->name, h->value);
		return;
	}
	do{
		this->addElement(h->name,h->value);
		h = h->next;
	}
	while(h != t->next);

}
//change the size in addElement(char name).
void Huffman::addElement(char name, int value)
{
	int i=0;
	while(i<value)
	{
		MyNode::addElement(name);
		i++;
	}
}
//change the size;
struct node* Huffman::popFromHead()
{
	struct node* head= this->head->next;
	struct node* second =  head->next;
	struct node* tail =  head->prev;
	if(head == 0)
	{
		std::cout << "error: It's not round link!check! In popFromHead()\n";
		exit(1);
	}
	if(this->size > 1)
	{
		tail->next = second;
		second->prev = tail;
		this->head->next = second;
		this->size--;
	}
	else
	{
		std::cout << "warning: There is only one element in link, return head!\n";
		this->head = 0;
		this->size = 0;
	}
	return head;
}
void Huffman::buildTree()
{
	this->root = new struct tree;
	memset(this->root, 0, sizeof(struct tree));
	while(this->size != 1)
	{
		struct node* head = this->popFromHead();
		struct node* second = this->popFromHead();
		struct tree* left; 
		struct tree* right; 
		if(head != 0)
		{
			left = new struct tree;
			memset(left,0,sizeof(struct tree));
			left->entry = head;
		}
		if(second != 0)
		{
			right = new struct tree;
			memset(right,0,sizeof(struct tree));
			right->entry = second;
		}
		struct tree* newtree = new struct tree;
		*newtree = {'',head->value+second->value,0,0};
		this->root->lnode = left;
		this->root->rnode = right;
		char nm = head->name;
		int value = head->value + second->value;
		this->addElement(nm,value);
		this->sort();
		delete(head);head=0;
		delete(second);second=0;
	}

}
void Huffman::addTreeToNodeLink(struct tree* t)
{
	int value = t->entry->value;
	struct node* head = this->head->next;
	int value_p = head->value;
	do
	{
		if(value > value_p)
		{
				
		}
	}
}
