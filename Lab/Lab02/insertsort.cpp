#include<iostream>

using namespace std;

int calls[36]; // where n is the no of lines.
int main()
{
    int count= 0,i = 0,num = 0;
    cin >> count; //Number of elems to be sorted
    int *arr = new int[count];
    int elems = count; 
    while(count > 0)
    {
        cin >> num;
        arr[i] = num;
        ++calls[__LINE__];
        i++;
        count--;
    }
    for (i =0; ++calls[__LINE__],i< elems ; i++)
    {
        ++calls[__LINE__];
        int prev = arr[i]; 
        int next = i;
        while ((++calls[__LINE__],next > 0) && arr[next-1] > prev  )
        {
            ++calls[__LINE__];
            arr[next] = arr[next-1];
            next = next-1;
        }
        arr[next] = prev;
    }
    for (int i = 0;++calls[__LINE__], i < elems ; i ++)
    {
        cout << arr[i] << " ";
    }
    for(int i=1; i<36; ++i) if(calls[i]!=0) std::cerr << calls[i] << std::endl; else std::cerr << std::endl;
    delete [] arr;
    return 0;
}
