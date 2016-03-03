#include<iostream>
#include"TimePiece.h"
#include "PartitionSort.h"

using namespace std;

template<class T>
PartitionSort<T>::PartitionSort(int no):Sort<T>(no)
{
}

template<class T>
void PartitionSort<T>::sort()
{
    if(this->m_size > 0)
        internal_sort(this->arr,this->m_size);
}

template<class T>
int PartitionSort<T>::partition(T*arr, int len)
{
    int length = len;
    int low = 0;
    int high = length-1;
    T pivot = arr[length-1];

    for (int i = 0; i < len-1; i++)
    {
        if (arr[i] <= pivot )
        {
            T place_holder = arr[i];
            arr[i] = arr[low];
            arr[low]=place_holder;
            low++;
        }
    }
    T temp = arr[low];
    arr[low] = pivot;
    arr[high] = temp;

    return low;        
}

template<class T>
void PartitionSort<T>::internal_sort(T *arr, int len)
{
    int i =0;
    if(len > 0)
    {
        i = partition (arr, len);
        internal_sort(arr,i);
        internal_sort(arr + i + 1, len -i - 1);
    }
}

template<class T>
PartitionSort<T>::~PartitionSort()
{
    //delete []arr;
}


template class PartitionSort<int>;
template class PartitionSort<TimePiece>;
