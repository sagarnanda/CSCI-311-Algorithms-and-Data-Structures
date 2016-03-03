#include <iostream>
#include<algorithm>
#include<set>

#include "AdjacencyList.h"

using namespace std;

AdjacencyList::AdjacencyList()
{
}

AdjacencyList::AdjacencyList(unsigned int num_vertices)
{
    //vector<unsigned int> empty(num_vertices);
    set<unsigned int> empty;
    for(int i = 0; i < num_vertices; i++)
    {
        list.push_back(empty);
    }
}

void AdjacencyList::add_edge(unsigned int p, unsigned int q)
{
    if(p >= list.size() || q >= list.size())
        return;
    list[p].insert(q);
    list[q].insert(p);
}

void AdjacencyList::display()
{
    Graph::display();
    //cout<<"Graph with "<<list.size()<<" nodes."<<endl;    
    for(int i=0; i<list.size(); i++)
    {
        for(auto iter=list[i].begin(); iter!=list[i].end(); iter++) 
        {
            if ((*iter) > i) 
                cout<< "(" <<i << ", " << *iter << ")" << endl;
        }
    }

}

void AdjacencyList::remove_edge(unsigned int p, unsigned int q)
{
    if(p >= list.size() || q >= list.size())
        return;
    list[p].erase(q);
    list[q].erase(p);
}

unsigned int AdjacencyList::add_vertex()
{
    set<unsigned int> empty;
    list.push_back(empty);
    return list.size()-1;
}

void AdjacencyList::remove_vertex(unsigned int p)
{
    for(int i=0; i<list.size(); i++)
    {
        list[i].erase(p);
    }
    swap(list[list.size()-1], list[p]);
    list.pop_back();
    if(list.size() <= 1)
        return;
    for(auto iter=list[p].begin(); iter!=list[p].end(); iter++)
    {
        list[*iter].erase(list.size());
        list[*iter].insert(p);
    }
}
unsigned int AdjacencyList::degree(unsigned int p)
{
    int degree = 0;
    for(auto iter=list[p].begin(); iter!=list[p].end(); iter++)
    {
        degree++;      
    }
    return degree;
}

unsigned int AdjacencyList::size()
{   
    int size =0;
    for(int i=0; i<list.size(); i++)
    {
        for(auto iter=list[i].begin(); iter!=list[i].end(); iter++) 
        {
            if ((*iter) > i) 
                size++;
        }
    }
    return size;
}

unsigned int AdjacencyList::order()
{
    return list.size();
}

set<unsigned int> AdjacencyList::neighbors(unsigned int p)
{
    set<unsigned int> vertices;
    for(auto iter=list[p].begin(); iter!=list[p].end(); iter++)
    {
         vertices.insert(*iter); 
    }
    return vertices;
}
