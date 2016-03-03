#include<iostream>

#include"Sort.h"
#include"PartitionSort.h"
#include"HeapSort.h"
#include"MergeSort.h"
#include"InsertSort.h"
#include"TimePiece.h"

using namespace std;


int main()
{
    int option;
    cin>>option;
    Sort<TimePiece>* so = NULL;

    switch (option)
    {
        case 1:
            {
                //                cout<<"Partition Sort"<<endl;
                int count;
                cin>>count;
                so = new PartitionSort<TimePiece>(count);
                TimePiece num;
                for(int i=0; i<count; ++i)
                {
                    cin >> num;
                    so->add(num);
                }
                //                so->display();
                so->sort();
                so->display();
                break;

            }

        case 2:
            {
                //                cout<<"Heap Sort"<<endl;
                int count;
                cin>>count;
                so = new HeapSort<TimePiece>(count);
                TimePiece num;
                for(int i=0; i<count; ++i)
                {
                    cin >> num;
                    so->add(num);
                }
                //               so->display();
                so->sort();
                so->display();
                break;
            }
        case 3:
            {
                //              cout<<"Merge Sort"<<endl;
                int count;
                cin>>count;
                so = new MergeSort<TimePiece>(count);
                TimePiece num;
                for(int i=0; i<count; ++i)
                {
                    cin >> num;
                    so->add(num);
                }
                //             so->display();
                so->sort();
                so->display();
                break;

            }
        case 4:
            {
                //            cout<<"Insertion Sort"<<endl;
                int count;
                cin>>count;
                so = new InsertSort<TimePiece>(count);
                TimePiece num;
                for(int i=0; i<count; ++i)
                {
                    cin >> num;
                    so->add(num);
                }
                //           so->display();
                so->sort();
                so->display();
                break;
            }
    }
    if(so)
    {
        delete so;
    }
}
