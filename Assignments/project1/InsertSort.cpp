#include "InsertSort.h"
#include "TimePiece.h"

template<class T>
InsertSort<T>::InsertSort(int no):Sort<T>(no)
{
}

template<class T>
void InsertSort<T>::sort()
{
    if(this->m_size > 0)
        internal_sort(this->arr,this->m_size);       
}

template<class T>
void InsertSort<T>::internal_sort(T*arr,int elems)
{
    for (this->i =0; this->i< elems ; this->i++)
    {
        auto prev = this->arr[this->i]; 
        auto next = this->i;
        while (next > 0 && arr[next-1] > prev  )
        {
            arr[next] = arr[next-1];
            next = next-1;
        }
        arr[next] = prev;
    }
}

template<class T>
InsertSort<T>::~InsertSort()
{
//    delete [] arr;
}
template class InsertSort<int>;
template class InsertSort<TimePiece>;
