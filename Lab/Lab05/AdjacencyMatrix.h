#ifndef AdjacencyMatrix_H
#define AdjacencyMatrix_H
#include <set>
#include <vector>
using namespace std;

class AdjacencyMatrix
{
    public:
        AdjacencyMatrix();
        AdjacencyMatrix(unsigned int num_vertices);
        void add_edge(unsigned int, unsigned int);
        void display();
        void remove_edge(unsigned int p, unsigned int q);
        unsigned int add_vertex();
        void remove_vertex(unsigned int p);

    private:
        vector< vector<unsigned int> > list;
};
#endif
