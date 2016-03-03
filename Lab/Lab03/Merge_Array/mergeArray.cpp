#include<iostream>

using namespace std;

float* merge(float* left_array, int left_size,float* right_array, int right_size);
int main()
{
    int no,val;
    cin>>no;
    float a1[no];
    float* mylist=new float[no];
    for (int i = 0; i < no; i++)
    {
        cin>>val;
        mylist[i] = val;
    }
    //fill up mylist with 7 random floats
    float* sorted_list=merge(mylist, no, NULL, 0);
    //print it out

    cout << "Sorted array is " << endl;
    for (int i =0;i<no;i++)
    {
        cout<<sorted_list[i] << " ";
    }
    cout << endl;
    delete [] sorted_list;
    return 0;

}

float* merge(float* A, int m,float* B,int n)
{
    int i = 0,j = 0,k = 0;
    float* results= new float[m+n];

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
    if(m >1)
    delete []A;
    if(n >1)
    delete []B;
   
    return results;
}
