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

void AdjacencyMatrix::add_edge(unsigned int p, unsigned int q, int w)
{
    if(p >= list.size() || q >= list.size())
        return;
    list[p][q] = w;
//    list[q][p] = 1;
}

void AdjacencyMatrix::display()
{
    Graph::display();
    //    cout<<"Graph with "<<list.size()<<" nodes."<<endl;    
    for(int i=0; i<list.size(); i++)
    {
        int j = 0;
        for(auto iter=list[i].begin(); iter!=list[i].end(); iter++,j++) 
        {
            if ((j) > i && (*iter)==1) 
                cout<< "(" <<i << ", " << j << ")" << endl;
        }
    }
}

void AdjacencyMatrix::remove_edge(unsigned int p, unsigned int q)
{
    if(p >= list.size() || q >= list.size())
        return;
    list[p][q] = 0;
//    list[q][p] = 0;
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
unsigned int AdjacencyMatrix::degree(unsigned int p)
{
         int degree = 0;
         for(auto iter=list[p].begin(); iter!=list[p].end(); iter++) 
        {
            if((*iter)==1)
            degree++;
        }
    return degree;
}

unsigned int AdjacencyMatrix::size()
{
    int size =0;
    for(int i=0; i<list.size(); i++)
    {
        int j = 0;
        for(auto iter=list[i].begin(); iter!=list[i].end(); iter++,j++) 
        {
            if ((j) > i && (*iter)==1) 
            size++;
        }
    }
    return size;
}

unsigned int AdjacencyMatrix::order()
{
    return list.size();
}


set<unsigned int> AdjacencyMatrix::neighbors(unsigned int p)
{
    set<unsigned int>vertices;
    int j =0;
    for(auto iter=list[p].begin(); iter!=list[p].end(); iter++, j++)
    {
        if((*iter) ==1)
    //    cout<<(*iter);
        vertices.insert(j);    
    }
    return vertices;
}

int AdjacencyMatrix::weight(unsigned int p, unsigned q)
{
    int i =0;
    i = list[p][q];
    return i;
}

set<unsigned int> AdjacencyMatrix::out_neighbors(unsigned int src)
{
    set<unsigned int>out_nbor;
    int j =0;
    for(auto iter=list[src].begin(); iter!=list[src].end(); iter++, j++)
    {
        if((*iter > 0))
        out_nbor.insert(j);
    }
    return out_nbor;
}

