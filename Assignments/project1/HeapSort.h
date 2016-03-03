#ifndef HeapSort_H
#define HeapSort_H

#include"Sort.h"

template<class T>
class HeapSort : public Sort<T>
{
    public:
        HeapSort(int);
//        void add(float);
        void sort();
//        void display();
        ~HeapSort();
    private:
        int LEFT(int);
        int RIGHT(int);
        void internal_sort(int ,int);
//        float* arr;
//        int i;
//        int m_size;
};
#endif
