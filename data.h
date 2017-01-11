#ifndef DATA_H
#define DATA_H

#define CHUNK 1024
struct node
{
	char name;
	int value;
	struct node* prev;
	struct node* next;
};

struct tree
{
	struct node* entry;
	struct node* prev;
	struct node* next;
	struct tree* lnode;
	struct tree* rnode;
	struct tree* parent;
};
#endif
