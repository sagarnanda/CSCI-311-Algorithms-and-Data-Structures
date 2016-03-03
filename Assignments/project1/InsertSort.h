#ifndef InsertSort_H
#define InsertSort_H

#include "Sort.h"

template<class T>
class InsertSort : public Sort<T>
{
    public:
        InsertSort(int);
        void sort();
        ~InsertSort();

    private:
        void internal_sort(T* arr, int elems); 
};

#endif
