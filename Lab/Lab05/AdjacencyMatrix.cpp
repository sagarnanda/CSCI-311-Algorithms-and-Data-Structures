#include <iostream>
#include<algorithm>
#include "AdjacencyMatrix.h"

using namespace std;

AdjacencyMatrix::AdjacencyMatrix()
{
}

AdjacencyMatrix::AdjacencyMatrix(unsigned int num_vertices)
{
    vector<unsigned int> empty(num_vertices,0);
    for(int i = 0; i < num_vertices; i++)
    {
        list.push_back(empty);
    }
}

void AdjacencyMatrix::add_edge(unsigned int p, unsigned int q)
{
    if(p >= list.size() || q >= list.size())
        return;
    list[p][q] = 1;
    list[q][p] = 1;
}

void AdjacencyMatrix::display()
{
    cout<<"Graph with "<<list.size()<<" nodes."<<endl;    
    for(int i=0; i<list.size(); i++)
    {
        int j = 0;
        for(auto iter=list[i].begin(); iter!=list[i].end(); iter++,j++) 
        {
            if ((j) > i && (*iter)==1) 
                cout<< "(" <<i << ", " << j << ")" << endl;
        }
    }
    /*
    cout << "AdjacencyMatrix is " << endl;
    for(int i=0; i<list.size(); i++)
    {
        int j = 0;
        cout << i << " -->\t";
        for(auto iter=list[i].begin(); iter!=list[i].end(); iter++,j++) 
        {
                cout << *iter << "  ";
        }
        cout << endl;
    }
    */
}

void AdjacencyMatrix::remove_edge(unsigned int p, unsigned int q)
{
    if(p >= list.size() || q >= list.size())
        return;
    list[p][q] = 0;
    list[q][p] = 0;
}

unsigned int AdjacencyMatrix::add_vertex()
{
    vector<unsigned int> empty(list.size() +1 ,0);
    list.push_back(empty);
    for(int i=0; i<list.size()-1; i++)
    {
        list[i].push_back(0);
    }
    return list.size()-1;
}

void AdjacencyMatrix::remove_vertex(unsigned int p)
{
    for(int i=0; i<list.size(); i++)
    {
        list[i][p] = 0;
    }
    swap(list[list.size()-1], list[p]);
    //remove last from list of list
    //if last of the list is set list[i][p] = 1;
    for(int i =0; i < list.size(); i++)
    {
        if(list[i][list[i].size()-1] == 1)
        {
            list[i][p] = 1;
        }
        list[i].pop_back();
    }
    list.pop_back();
    if(list.size() <= 1)
        return;
}
