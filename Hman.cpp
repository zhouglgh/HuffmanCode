#include "Hman.h"
#include <string.h>
#include <iostream>
Hman::Hman()
{
	this->root= 0;	
}
Hman::Hman(MyNode mn)
{
	struct node* head = mn.head->next;
	char name          = head->name;
	unsigned int value = head->value;
	this->root = new class Tree;
	this->root->setNameValue(name,value);
	struct node *pointer = head->next;
	while ( pointer != head)
	{
		Tree *t = new Tree(pointer);	
		this->addTail(this->root, t);
		pointer = pointer->next;
	}
}
void Hman::addTail(Tree *head, Tree *next)
{
	Tree *pointer = head;
	do{
		if(pointer != 0)
		{
			if(pointer->next == 0)
			{
				pointer->next = next;
				if(next != 0)
				{
					next->prev = pointer;	
				}
				else
				{
					std::cout << "warning: in addBehind(),null pointer!check!\n";	
				}
				break;
			}
			pointer = pointer->next;
		}
		else
		{
			std::cout << "error: point to empty address!\n";	
		}
	}while(1);
}
void Hman::show()
{
	Tree *t = this->root;
	do{
		cout << "name: " << t->name << ", value: " << t->value << ", newnode:"<< t->isSynthetic
		    << ",left"<<t->left<<",right"<<t->right<<endl;
		if(! t->next) 
			break;
		else
			t =t->next;
	}while(t != 0);

}
Hman::~Hman()
{
	Tree *t = this->root;
	Tree *del =0;
	do{
		del = t;
		if(! t->next) 
		{
			delete(t);
			break;
		}
		else
			t =t->next;
		delete(del);
		t->prev=0;
	}while(t != 0);
	
}
/*
 * 有序插入一个Tree节点
 * 0: sucess.
 * 1: failed.
 * */
int Hman::insertInOrder(Tree *node)
{
	unsigned int value = node->value;
	Tree *pointer = this->root;
	Tree *next    = 0;
	do{
		next    = pointer->next;
		if(next == 0)
		{
			pointer->next = node;
			node->prev = pointer;
			node->next = 0;
			return 0;
		}
		unsigned int targetValue = pointer->value;
		unsigned int targetNextValue = next->value;
		if(value >= targetValue && value < targetNextValue)
		{
			pointer->next = node;
			node->prev    = pointer;
			node->next    = next;
			next->prev    = node;
			return 0;
		}
		pointer = pointer->next;
	}while(pointer != 0);
	return 1;

}
/*
 * 执行一次合并操作。
 * 0:sucess.
 * 1:Only one tree node left, can't synthesize.
 * */
int Hman::synthesizeOnce()
{
	Tree *first = this->root;
	Tree *second= first->next;
	Tree *newTreeNode = new Tree;
	if(first && second)
	{
		this->root  = second->next;
		if(!this->root)
		{
			newTreeNode->setNameValue('$',0);
			newTreeNode->left = first;	
			newTreeNode->right= second;	
			newTreeNode->isSynthetic = 1;	
			newTreeNode->prev = 0;	
			newTreeNode->next = 0;	
			this->root = newTreeNode;
			return 1;
		}
		this->root->prev = 0;
		second->next= 0;
		second->prev= 0;
		first->next = 0;
		first->prev = 0;
		char name = '$';
		unsigned int value = first->value + second->value;
		newTreeNode->setNameValue(name,value);
		newTreeNode->isSynthetic = 1;
		newTreeNode->left = first;
		newTreeNode->right= second;
		newTreeNode->prev = 0;
		newTreeNode->next = 0;
		if ( !this->insertInOrder(newTreeNode))
			return 0;
	}
	else if(first && !second)
	{
		std::cout << "Only one node in tree. over!\n";
		return 1;	
	}
	else
	{
		std::cout << "error: in synthesizeOnce(),check!\n";
		exit(1);
	}
}
void Hman::buildTree()
{
	while(!synthesizeOnce());
}

void Hman::identifyTreeNode(Tree *node,string codema)
{
	if( !node )
	{
		std::cout << "error: null pointer, in identifyTreeNode()!\n";
		exit(1);
	}
	else
	{
		if(!node->isSynthetic)
		{
			std::cout <<codema<< "," << node->name << std::endl;	
			return;
		}
		else
		{
			if(!node->left)
			{
				std::cout << "error: is not leaf node, but has no left node.\n";
				exit(1);
			}
			else
			{
				identifyTreeNode(node->left, codema+'0');
			}
			if(!node->right)
			{
				std::cout << "error: is not leaf node, but has no right node.\n";
				exit(1);
			}
			else
			{
				identifyTreeNode(node->right, codema+'1');
			}
		}
	}
}
int Hman::code()
{
	string codestring="";
	this->identifyTreeNode(this->root, codestring);
}
void Hman::printRoot()
{
	printTree(this->root);	
}
void Hman::printTree(Tree *node)
{
	if(node)
	{
		cout << "name:"<<node->name<<",value:"<<node->value<<endl;	
		printTree(node->left);
		printTree(node->right);
	}
	else
	{
		return;	
	}
}
