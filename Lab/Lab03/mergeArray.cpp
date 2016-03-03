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
    for (int i =0;i<9;i++)
    {
        cout<<sorted_list[i] << " ";
    }
    cout << endl;
    //delete [] sorted_list;
    return 0;

}

float* merge(float* A, int m,float* B,int n)
{
    int i = 0,j = 0,k = 0;
    float* results= new float[m+n];
    cout << "Content of A " << endl;
    for(int i = 0; i < m ; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << "Content of B " << endl;
    for(int i = 0; i < n ; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;

    if(m > 1)
    {
        results=merge(A, m/2, A+(m/2), m-(m/2));
         //delete [] A;
         A = results;
     //   for (int i = 0; i < m; i++ )
     //   {
     //       A[i]=results[i]; 
     //   }
        //      A = results;
        //release left array 
        //left array = results


    }
    if(n > 1)
    {
        results=merge(B, n/2, B+(n/2), n-(n/2));
        //delete [] B;
        B = results;
       // for (int i = 0; i < n; i++ )
       // {
       //     B[i]=results[i]; 
       // }

        //    B = results;
        // release right array 
        // right arrat = results
    }
    cout << "Content of before sorting A " << endl;
    for(int i = 0; i < m ; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    cout << "Content of before sorting B " << endl;
    for(int i = 0; i < n ; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;

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
    cout << "Results after each iteration " << endl;
    for(int i = 0; i < (m+n); i++)
    {
        cout << results[i] << " ";
    }
    cout << endl;
    return results;
}
