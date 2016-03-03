#ifndef AdjacencyList_H
#define AdjacencyList_H
#include <set>
#include <vector>
#include "Graph.h"
using namespace std;

class AdjacencyList : public Graph
{
    public:
        AdjacencyList();
        AdjacencyList(unsigned int num_vertices);
        void add_edge(unsigned int, unsigned int);
        void display();
        void remove_edge(unsigned int p, unsigned int q);
        unsigned int add_vertex();
        void remove_vertex(unsigned int p);

        unsigned int degree(unsigned int);
        unsigned int size();
        unsigned int order();

        set<unsigned int> neighbors(unsigned int p);

    private:
        vector< set<unsigned int> > list;
        //vector< vector<unsigned int> > list;
};
#endif
