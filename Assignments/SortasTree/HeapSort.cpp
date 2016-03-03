#include<iostream>
#include<algorithm>

#include"HeapSort.h"

using namespace std;

HeapSort::HeapSort(int no):i(0),m_size(no),arr(new float[no]) 
{
}

void HeapSort::add(float num)
{
    arr[i] = num;
    i++;
}
int HeapSort::LEFT(int index)
{
    return 2*index+1; 
}
int HeapSort::RIGHT(int index)
{
    return 2*index+2;
}
void HeapSort::sort()
{
    int length = m_size;
    for (int i = (m_size / 2); i >= 0; i--) 
    {
      internal_sort(i, m_size);
    }

    for (int i = 0; i < m_size; i++) 
    {
      swap(arr[0], arr[length - 1]);
      length--;
      internal_sort(0, length);
    }
}
void HeapSort::internal_sort(int index, int length)
{
    int left = LEFT(index);
    int right = RIGHT(index);
    
    if ((left < length) && (arr[index] < arr[left])) 
    {
      swap(arr[left], arr[index]);
      internal_sort(left, length);
    }
    if ((right < length) && (arr[index] < arr[right])) 
    {
      swap(arr[right], arr[index]);
      internal_sort(right, length);
    }
}
void HeapSort::display()
{
    for(int i = 0; i < m_size; i++)
    {
        if (i < m_size -1)
            cout<<arr[i]<<" ";
        else
            cout<<arr[i];
    }
    cout<<endl;
}
HeapSort::~HeapSort()
{
    delete []arr;
}
