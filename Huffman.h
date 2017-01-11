#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "DoubleLink.h"

class Huffman : public MyNode
{
	public:
		Huffman();
		Huffman(MyNode node);
		void addElement(char name, int value);
		void addTreeToNodeLink(struct tree* t);
		void buildTree();
		struct node* popFromHead();
	private:
		struct tree* root;

};


#endif
