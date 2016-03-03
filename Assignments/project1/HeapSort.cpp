#include<iostream>
#include<algorithm>
#include"TimePiece.h"

#include"HeapSort.h"

using namespace std;
template<class T>
HeapSort<T>::HeapSort(int no):Sort<T>(no)
{
}

template<class T>
int HeapSort<T>::LEFT(int index)
{
    return 2*index+1; 
}

template<class T>
int HeapSort<T>::RIGHT(int index)
{
    return 2*index+2;
}

template<class T>
void HeapSort<T>::sort()
{
    int length = this->m_size;
    for (int i = (this->m_size / 2); i >= 0; i--) 
    {
      internal_sort(i, this->m_size);
    }

    for (int i = 0; i < this->m_size; i++) 
    {
      swap(this->arr[0], this->arr[length - 1]);
      length--;
      internal_sort(0, length);
    }
}

template<class T>
void HeapSort<T>::internal_sort(int index, int length)
{
    int left = LEFT(index);
    int right = RIGHT(index);
    
    if ((left < length) && (this->arr[index] < this->arr[left])) 
    {
      swap(this->arr[left], this->arr[index]);
      internal_sort(left, length);
    }
    if ((right < length) && (this->arr[index] < this->arr[right])) 
    {
      swap(this->arr[right], this->arr[index]);
      internal_sort(right, length);
    }
}
template<class T>
HeapSort<T>::~HeapSort()
{
//    delete []arr;
}

template class HeapSort<int>;
template class HeapSort<TimePiece>;
