#ifndef AdjacencyMatrix_H
#define AdjacencyMatrix_H
#include <set>
#include <vector>
#include "Graph.h"
using namespace std;

class AdjacencyMatrix : public Graph 
{
    public:
        AdjacencyMatrix();
        AdjacencyMatrix(unsigned int num_vertices);
        virtual void add_edge(unsigned int, unsigned int, int);
        void display();
        void remove_edge(unsigned int p, unsigned int q);
        unsigned int add_vertex();
        void remove_vertex(unsigned int p);

        unsigned int degree(unsigned int);
        unsigned int size();
        unsigned int order();

        set<unsigned int> neighbors(unsigned int p);
        
        
        int weight(unsigned int p, unsigned q);
        set<unsigned int> out_neighbors(unsigned int src);

    private:
        vector< vector<unsigned int> > list;
};
#endif
