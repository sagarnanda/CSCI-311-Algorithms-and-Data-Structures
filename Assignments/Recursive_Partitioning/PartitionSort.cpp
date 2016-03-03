#include<iostream>
#include "PartitionSort.h"

using namespace std;

PartitionSort::PartitionSort(int no):i(0),m_size(no),arr(new float[no])
{
}
void PartitionSort::add(float num)
{
    arr[i] = num;
    i++;
}
void PartitionSort::sort()
{
    if(m_size > 0)
        internal_sort(arr,m_size);
}

void PartitionSort::display()
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
int PartitionSort::partition(float *arr, int len)
{
    int length = len;
    int low = 0;
    int high = length-1;
    float pivot = arr[length-1];

    for (int i = 0; i < len-1; i++)
    {
        if (arr[i] <= pivot )
        {
            float place_holder = arr[i];
            arr[i] = arr[low];
            arr[low]=place_holder;
            low++;
        }
    }
    float temp = arr[low];
    arr[low] = pivot;
    arr[high] = temp;

    return low;        
}
void PartitionSort::internal_sort(float *arr, int len)
{
    int i =0;
    if(len > 0)
    {
        i = partition (arr, len);
        internal_sort(arr,i);
        internal_sort(arr + i + 1, len -i - 1);
    }
}
PartitionSort::~PartitionSort()
{
    delete []arr;
}
