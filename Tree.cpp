#include "Tree.h"
#include <iostream>

Tree::Tree()
{
	this->left = 0;
	this->right= 0;
	this->prev = 0;
	this->next = 0;
	this->name = 0;
	this->value= 0;
	this->isSynthetic= 0;
}
Tree::Tree(struct node *node)
{
	this->setNameValue(node->name, node->value);
}
void Tree::setNameValue(char name, unsigned int value)
{
	this->name = name;	
	this->value= value;	
	this->left = 0;
	this->right= 0;
	this->prev = 0;
	this->next = 0;
	this->isSynthetic = 0;
}
