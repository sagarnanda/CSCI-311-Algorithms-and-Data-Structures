#include<iostream>
#ifndef Sorter_H
#define Sorter_H

using namespace std;

template <class T> 
class Sorter
{
    public:
        Sorter(int count);
        ~Sorter();
        void add(T num);
        void sort();
        void display();

    private:
        T *arr;
        int max_size;
        int i;
};

template <class T> 
Sorter<T>::Sorter(int count)
{
    max_size = count;
    arr = new T[count];     
    i = 0;
}

template <class T> 
void Sorter<T>::add(T num)
{
    arr[i] = num;    
    i++;
}

template <class T> 
void Sorter<T>::sort()
{
    int x = 0;
    int cards_filled = 0;
    T place_holder;
    T temp;
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

template <class T> 
void Sorter<T>::display()
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

template<class T>
Sorter<T>::~Sorter()
{
    delete []arr;
}
#endif
