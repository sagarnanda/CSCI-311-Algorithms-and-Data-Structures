#include <iostream>
#include "Sorter.h"

using namespace std;

Sorter::Sorter(int count)
{
    max_size = count;
    arr = new float[count];     
    i = 0;
}

void Sorter::add(float num)
{
    arr[i] = num;    
    i++;
}

void Sorter::sort()
{
    int x = 0;
    int cards_filled = 0;
    float place_holder = 0;
    float temp;
    while (cards_filled < max_size)
    {
        place_holder = arr[x];
        i = 0;
        while(i < max_size)
        {
            if(place_holder < arr[i])
            {
                temp = place_holder;
                place_holder = arr[i];
                arr[i] = temp;
            }
            i++;
        }
        arr[cards_filled] = place_holder;
        cards_filled++;
        x++;
    }
}

void Sorter::display()
{
    for(int i = 0; i < max_size; i++)
    {
        if(i < max_size-1)
        cout << arr[i] << " ";
        else
        cout << arr[i];
    }
    cout << endl;
}

Sorter::~Sorter()
{
    delete []arr;
}
