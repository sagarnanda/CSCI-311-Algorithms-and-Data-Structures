#ifndef AdjacencyList_H
#define AdjacencyList_H
#include <set>
#include <vector>
using namespace std;

class AdjacencyList
{
    public:
        AdjacencyList();
        AdjacencyList(unsigned int num_vertices);
        void add_edge(unsigned int, unsigned int);
        void display();
        void remove_edge(unsigned int p, unsigned int q);
        unsigned int add_vertex();
        void remove_vertex(unsigned int p);

    private:
        vector< set<unsigned int> > list;
        //vector< vector<unsigned int> > list;
};
#endif
