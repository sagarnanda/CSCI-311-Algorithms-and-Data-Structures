#include<iostream>
#include"TimePiece.h"

#include "MergeSort.h"

template<class T>
MergeSort<T>::MergeSort(int no):Sort<T>(no)
{
}

template<class T>
void MergeSort<T>::sort()
{
    if(this->m_size > 0)
        this->arr = merge(this->arr,this->m_size,NULL,0);
}

template<class T>
T* MergeSort<T>::merge(T* A, int m,T* B,int n)
{
    int i = 0,j = 0,k = 0;
    T* results= new T[m+n];

    if(m > 1)
    {
        A=merge(A, m/2, A+(m/2), m-(m/2));
    }
    if(n > 1)
    {
        B=merge(B, n/2, B+(n/2), n-(n/2));
    }

    i = 0;
    k = 0;
    j = 0;
    while (i < m && j < n) 
    {
        if (A[i] <= B[j])
        {
            results[k] = A[i];
            i++;
        }
        else 
        {
            results[k] = B[j];
            j++;
        }
        k++;
    }
    if (i < m) 
    {
        for (int p = i; p < m; p++)
        {
            results[k] = A[p];
            k++;
        }
    } 
    else 
    {
        for (int p = j; p < n; p++) 
        {
            results[k] = B[p];
            k++;
        }
    }

   if(m > 1) 
    delete []A;
   if(n > 1)
    delete []B;
  
    return results;
}
template<class T>
MergeSort<T>::~MergeSort()
{
//    delete []arr;
}
template class MergeSort<int>;
template class MergeSort<TimePiece>;
