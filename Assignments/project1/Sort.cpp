#include<iostream>
#include"TimePiece.h"
#include"sort.h"
using namespace std;

template<class T>
Sort<T>::Sort(int no):i(0),m_size(no),arr (new T[no])
{
}

template<class T>
void Sort<T>::add(T num)
{
    arr[i] = num;
    i++;
}

template<class T>
void Sort<T>::display()
{
    for(int i = 0; i < m_size; i++)
    {
        if(i < m_size-1)
            cout << arr[i] << " ";
        else
            cout << arr[i];
    }
    cout << endl;
}

template<class T>
Sort<T>::~Sort()
{
    delete []arr;
}


template class Sort<int>;
template class Sort<TimePiece>;
