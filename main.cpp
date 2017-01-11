#include "DoubleLink.h"
#include "Hman.h"
#include "Arrays.h"
#include <iostream>

int main()
{
	char filename[] = "tailn10.txt";
	Arrays str;
	str.getArr(filename);
	MyNode mn(str.getStr());
	mn.sort();
	Hman hfm(mn);
	hfm.buildTree();
	hfm.code();
	return 0;
}
