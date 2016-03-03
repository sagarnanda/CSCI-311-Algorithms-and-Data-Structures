#ifndef MergeSort_H
#define MergeSort_H

#include "Sort.h"

using namespace std;

template<class T>
class MergeSort : public Sort<T>
{
    public:
        MergeSort(int);
        void sort();
        ~MergeSort();

    private:
       T* merge(T* left_array, int left_size,T* right_array, int right_size);
};

#endif
