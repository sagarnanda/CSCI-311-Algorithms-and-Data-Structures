#include<iostream>
#ifndef Sorter_H
#define Sorter_H

using namespace std;

class Sorter
{
    public:
        Sorter(int count);
        ~Sorter();
        void add(float num);
        void sort();
        void display();

    private:
        float *arr;
        int max_size;
        int i;
};

#endif
