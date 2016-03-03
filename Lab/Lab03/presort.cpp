#include<iostream>

using namespace std;

void preSortMerge(int m, int n,int A[], int B[], int C[]) ;
int main()
{
    int a1[5]={2,4,6,8};
    int a2[4] = {1,3,5,7};
    int merge[9];
    preSortMerge(5,4,a1,a2,merge);

    for (int i =0;i<8;i++)
    {
        cout<<merge[i]<<endl;
    }
//    delete []merge;
    return 0;
}
void preSortMerge(int m, int n, int A[], int B[], int C[]) 
{
    int i = 0,j = 0,k = 0;
    while (i < m && j < n) 
    {
        if (A[i] <= B[j])
        {
            C[k] = A[i];
            i++;
        }
        else 
        {
            C[k] = B[j];
            j++;
        }
        k++;
    }
    if (i < m) 
    {
        for (int p = i; p < m; p++)
        {
            C[k] = A[p];
            k++;
        }
    } 
    else 
    {
        for (int p = j; p < n; p++) 
        {
            C[k] = B[p];
            k++;
        }
    }

}
