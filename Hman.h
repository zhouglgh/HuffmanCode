#ifndef HMAN_H
#define HMAN_H
#include "data.h"
#include "Tree.h"
#include "DoubleLink.h"
#include <string>


using namespace std;
class Hman
{
	private:
		Tree *root;
	public:
		Hman();
		~Hman();
		Hman(MyNode mn);
		void addTail(Tree *head, Tree *next);
		void show();
		int synthesizeOnce();
		int insertInOrder(Tree *node);
		void buildTree();
		int code();
		void identifyTreeNode(Tree *node, string codema);
		void printRoot();
		void printTree(Tree *node);
};


#endif
