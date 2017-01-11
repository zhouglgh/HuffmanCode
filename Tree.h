#ifndef TREE_H
#define TREE_H
#include "data.h"
class Tree
{
	friend class Hman;
	private:
		Tree* left ;
		Tree* right;
		Tree* prev ;
		Tree* next ;
		char name;
		unsigned int value;
		bool isSynthetic = 0;
	public:
		Tree();
		Tree(struct node* node);
		void build();
		void addBehind(Tree *head, Tree *next);
		void setNameValue(char name, unsigned int value);
	
};


#endif
