#include "Arrays.h"
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

Arrays::Arrays()
{
	memset(this->arr,0,CHUNK);
}

void Arrays::getArr(char *filename)
{
    ifstream in(filename);
    if(!in)
    {
        std::cout << filename << ":open error!\n";
		return;
    }
	int i = 0;
	while(i<CHUNK)
	{
		if(!in.eof())
			in >> this->arr[i];
		else
			break;
		i++;
	}

}
char* Arrays::getStr()
{
	return this->arr;
	}
