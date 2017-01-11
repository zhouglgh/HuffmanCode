#ifndef ARRAYS_H
#define ARRAYS_H

#include "data.h"

class Arrays {
    public:
		Arrays();
        void  getArr(char *filename);
        char* getStr();
    private:
        char arr[CHUNK];

};




#endif

