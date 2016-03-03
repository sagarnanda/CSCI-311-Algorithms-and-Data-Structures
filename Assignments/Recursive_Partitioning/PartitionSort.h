#ifndef PartitionSort_H
#define PartitionSort_H

class PartitionSort
{
    public:
        PartitionSort(int);
        void add(float);
        void sort();
        void display();
        ~PartitionSort();

    private:
        int partition(float *arr, int len);
        void internal_sort(float* arr,int len);
        float *arr;
        int i;
        int m_size;
};

#endif
