#include<iostream>

using namespace std;

int calls[38]; // where n is the no of lines.
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
        i++;
       // ++calls[__LINE__];
        count--;
    }

    cout << "Original array ***********" << endl;
        for (int x = 0; x < elems; x ++)
        {
            cout << arr[x] << " ";
        }
        cout << endl;


    for (i =0; i< elems ; i++)
    {
        int prev = arr[i]; 
        int next = i;
        while (next > 0 && arr[next-1] > prev  )
        {
            arr[next] = arr[next-1];
            next = next-1;
        }
        arr[next] = prev;
/*        cout << "Iteration " << i << " ************** " << endl;
        for (int x = 0; x < elems -1; x ++)
        {
            cout << arr[x] << " ";
        }
        cout << endl;
  */  }
    for (int i = 0; i < elems ; i ++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    //for(int i=1; i<38; ++i) if(calls[i]!=0) std::cerr << calls[i] << std::endl; else std::cerr << std::endl;
    return 0;
}
