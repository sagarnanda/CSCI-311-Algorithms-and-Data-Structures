#include<iostream>

using namespace std;
float* merge(float arrayA[],float arrayB[],float arrayC[],int lsz, int rsz);
void mergeSort(int arrayC[],int arrayS[],int arraySize);
void m_sort(int arrayC[],int arrayS[],int left, int right);
void merge(int numbers[], int temp[], int left, int mid, int right);
int main()
{
    int arrayA[5]= {4,6,8,9,12};
    int arrayB[5]= {53,4,42,21,27};
    int arrayC[10];
    float* result=new float[7];
    merge(arrayA, arrayB, arrayC, 5,5);

}
float* merge(float arrayA[],float arrayB[],float arrayC[],int lsz, int rsz)
{
    if(lsz > 1)
    {
       //new memory 
       // merge sort
    }
    if(rsz > 1)
    {
        //new meomry
        // sort ra
    }


}

