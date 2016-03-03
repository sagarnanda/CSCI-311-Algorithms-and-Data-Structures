#include"Graph.h"
#include<iostream>
using std::cout;
using std::endl;

void Graph::display()
{
  cout << "Graph with " << order() << " nodes and " << size() << " edges." << endl;
}

Graph::~Graph()
{
}
