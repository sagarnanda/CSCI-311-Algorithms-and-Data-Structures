#ifndef GRAPH_H
#define GRAPH_H
class Graph {
  public:
    virtual void remove_vertex(unsigned int p)=0;
    virtual void remove_edge(unsigned int p, unsigned int q)=0;
    virtual unsigned int add_vertex()=0;
    virtual void add_edge(unsigned int, unsigned int)=0;
    virtual void display();
    virtual unsigned int degree(unsigned int)=0;
    virtual unsigned int size()=0; //number of edges
    virtual unsigned int order()=0; //number of vertices
    virtual ~Graph();
};
#endif
