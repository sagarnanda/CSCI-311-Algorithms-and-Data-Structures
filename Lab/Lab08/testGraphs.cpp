#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"
#include<iostream>
#include<iomanip>
using namespace std;

void print_degrees(Graph* gp)
{
  cout << "Vertex degrees" << endl;
  cout << "  vertex: ";
  for(int i=0; i<gp->order(); ++i)
    cout << setw(2) << i << " ";
  cout << endl;
  cout << "  degree: ";
  for(int i=0; i<gp->order(); ++i)
    cout << setw(2) << gp->degree(i) << " ";
  cout << endl;
}

void exerciseA_graph(Graph* gp)
{
  gp->add_edge(0,1);
  gp->add_edge(0,2);
  gp->add_edge(1,2);
  gp->add_edge(1,2); //Adding an existing edge fails silently
  gp->add_edge(2,1); //Adding an existing edge fails silently
  cout << "Exercise-A display\n";
  gp->display();
  print_degrees(gp);
}

void exerciseB_graph(Graph* gp)
{
  gp->add_vertex(); //add four vertices
  gp->add_vertex();
  gp->add_vertex();
  gp->add_vertex();

  gp->add_edge(0,1);
  gp->add_edge(0,2);
  gp->add_edge(0,3);
  gp->add_edge(1,2);
  gp->add_edge(1,3);
  gp->add_edge(2,3);
  cout << "First exercise-B display\n";
  gp->display();
  print_degrees(gp);
  gp->remove_vertex(1);
  cout << "Second exercise-B display\n";
  gp->display();
  print_degrees(gp);
  gp->remove_edge(2,0);
  cout << "Third exercise-B display\n";
  gp->display();
  print_degrees(gp);

}

int main()
{
  Graph* g;

  g=new AdjacencyList(3);
  exerciseA_graph(g);
  delete g;
  g=new AdjacencyList;
  exerciseB_graph(g);
  delete g;

  g=new AdjacencyMatrix(3);
  exerciseA_graph(g);
  delete g;
  g=new AdjacencyMatrix;
  exerciseB_graph(g);
  delete g;

  return 0;
}
