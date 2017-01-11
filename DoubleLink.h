#ifndef DOUBLELINK_H
#define DOUBLELINK_H
#include "data.h"
class MyNode
{
	friend class Hman;
	protected:
		unsigned int size = 0;
		struct node* head = 0;
	public:
		MyNode();
		MyNode(const char str[CHUNK]);
		bool isEmpty();
		struct node* getHeadAhead();
		/*
		 * 给链表插入一个元素。
		 * */
		void addElement(char str);
		/*
		 * 在链表尾部插入一个节点。
		 * */
		void addNodeAtTail(struct node* element);
		void addNodeAtTail(struct node* list, struct node* element);
		/*
		 * 给链表中的数据按照从小到大排序。
		 * */
		void sort();
		void insertBetweenAnd(struct node* head, struct node* tail, struct node* element);
		void insertSort(struct node* pointer, struct node* element);
		/**
		 * 打印自身存储数据。
		 * */
		void print();
		/*
		 * 删除自身指针
		 * */
		~MyNode();


};
#endif
