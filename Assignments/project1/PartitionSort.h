#ifndef PartitionSort_H
#define PartitionSort_H

#include"Sort.h"

template<class T> 
class PartitionSort : public Sort<T>
{
    public:
        PartitionSort(int);
//        void add(float);
        void sort();
//        void display();
        ~PartitionSort();

    private:
        int partition(T*arr, int len);
        void internal_sort(T* arr,int len);
//        float *arr;
//        int i;
//        int m_size;
};

#endif
