#include "DoubleLink.h"
#include <string.h>
#include <iostream>
#include <stdlib.h>


static void deleteItSelf(struct node* node ,struct node* finalnode);

MyNode::MyNode()
{
	this->head = new struct node;
	*this->head = {0,0,0,0};
	}
MyNode::MyNode(const char str[CHUNK])
{
	this->head = new struct node;
	*this->head = {0,0,0,0};
	int i=0,length=strlen(str);
	while(i<length)
	{
		this->addElement(str[i]);
		i++;
		this->size++;
	}
}
bool MyNode::isEmpty()
{
	return !this->size;	
}
struct node* MyNode::getHeadAhead()
{
	return this->head;	
}
/*
 * 把element节点插入到list尾部。
 * */
void MyNode::addNodeAtTail(struct node* element)
{
	struct node *head = this->head->next;
	struct node *tail = head->prev;
	this->insertBetweenAnd(tail,head,element);
}
/*
 * 新建节点并插入到链表尾。change the value of size.
 * */
void  MyNode::addElement(char ch)
{
	if(this->head == NULL)
	{
		struct node* newnode = new struct node;
		*newnode = {ch,1,newnode,newnode};
		this->head->next = newnode;
		this->size++;
		return; 
	}
	else
	{
		struct node* tmp = this->head->next;
		if(tmp == 0)
		{
			tmp = new struct node;
			*tmp = {ch,1,tmp,tmp};
			this->head->next = tmp;
			this->size++;
			return; 
		}
		if(tmp->name == ch)
		{
			tmp->value++;
			return; 
		}
		else
		{
			tmp = tmp->next;
			while(tmp != this->head->next && tmp != 0)
			{
				if(tmp->name == ch)
				{
					tmp->value++;
					return; 
				}
				tmp = tmp->next;
			}
			struct node* tail = new struct node;
			*tail = {ch,1};
			addNodeAtTail(tail);
			this->size++;
		}
		return; 
	}
}
/*
 * 相邻节点间的插入。
 * */
void MyNode::insertBetweenAnd(struct node* front, struct node* back, struct node* element)
{
	if(front == 0 || back == 0 || front->next != back || back->prev != front)
	{
		std::cout << "null pointer at insetBetweenAnd()!Please check!\n";
		exit(1);
	}
	if(element != 0)
	{
		front->next   = element;
		element->prev = front;
		back->prev   = element;
		element->next = back;
	}
}
/*
 * Used in sort().
 * */
void MyNode::insertSort(struct node* element, struct node* pointer)
{
	if(pointer == 0 || element == 0)
	{
		std::cout << "null pointer in insertSort(),check!" << std::endl;
		exit(1);
	}
	if(pointer == element)
		return;
	if(pointer->value > element->value)
	{
		struct node* prev = pointer->prev;
		if(prev->value < element->value)
		{
			this->insertBetweenAnd(prev,pointer,element);
			return;
		}
		else
		{
			insertSort(prev,element);
		}
	}
	else if(pointer->value < element->value)
	{
		struct node* next = pointer->next;
		if(next->value > element->value)
		{
			this->insertBetweenAnd(pointer,next,element);
			return;
		}
		else
		{
			insertSort(next,element);
		}
	}
	else
	{
		insertSort(element,pointer->next);
	}
}

void exchange(struct node* pointer,struct node* iterator)
{
	if(pointer ==0 || iterator == 0)
	{
		std::cout << "null pointer error in exchange()!check!\n";
		exit(1);
	}
	char name  = pointer->name;
	char value = pointer->value;
	pointer->name = iterator->name;
	pointer->value= iterator->value;
	iterator->name  = name;
	iterator->value = value;
}
/*
 * 插入排序。
 * */
void MyNode::sort()
{
	struct node* head = this->head->next;
	struct node* pointer = head->prev;
	while(pointer != head)
	{
		struct node* iterator= head;
		while(iterator != pointer)
		{
			int vp = pointer->value;
			int vi = iterator->value;
			if(vp < vi)
				exchange(pointer,iterator);
			iterator = iterator->next;
		}
		pointer = pointer->prev;
	}
}
MyNode::~MyNode()
{
	
	deleteItSelf(this->head->next,this->head->next->prev);
	delete(this->head);
	this->head = 0;
}
/*
 * 清除存储空间。
 * */
static void deleteItSelf(struct node* head,struct node* tail)
{
	struct node* pointer = head;
	struct node* del=0;
	while(pointer != tail)
	{
		del = pointer;
		tail->next = pointer->next	;
		pointer->next->prev = pointer->prev;
		pointer =pointer->next;
		delete(del);
		del=0;
	}
	delete(tail);
}
/*
 * 打印数据。
 * */
void MyNode::print()
{
	struct node* head     = this->head->next;
	struct node* iterator = head;
	int i=1;
	do{
		std::cout << i<<':'<<iterator->name<<','<<iterator->value<<','<<std::endl;
		i++;
		iterator = iterator->next;
	}while(iterator != head);
}
