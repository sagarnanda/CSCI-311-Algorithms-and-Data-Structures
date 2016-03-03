#include"Graph.h"
#include<iostream>
//using std::cout;
//using std::endl;
using namespace std;
void Graph::display()
{
    cout << "Graph with " << order() << " nodes and " << size() << " edges." << endl;
}

Graph::~Graph()
{
}

map<unsigned int, unsigned int> Graph::breadth_first_search(unsigned int p )
{
    queue<unsigned int> c;
    map<unsigned int, unsigned int> m;
    set<unsigned int> neighbor;
    //    list<int> distance;
    unsigned int no_of_vertices = order();
    //    distance[0] = 0; 

    int distance[no_of_vertices] ;
    for (int i = 0; i < no_of_vertices; i++)
    {
        distance[i] = -1;
    }
    distance[0]= 0;
    c.push(0);
    while(!c.empty())
    {
        int current = c.back();
        c.pop();
        neighbor = this->neighbors(current); //calling pure virtual function
        for(auto nbor= neighbor.begin(); nbor!=neighbor.end(); nbor++)
        {
            if(distance[*nbor] == -1)
            {
                m[*nbor]=current; //map for previous node. 
                distance[*nbor] = distance[current]+1;
                c.push(*nbor);
            }
        }
    }
    return m;
}
