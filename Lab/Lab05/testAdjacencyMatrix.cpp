#include "AdjacencyMatrix.h"
#include<iostream>
using namespace std;
int main()
{
  AdjacencyMatrix gA(3); //Create a graph with 3 vertices
  /*
  gA.add_edge(0,1);
  gA.add_edge(0,2);
  gA.add_edge(1,2);
  gA.add_edge(1,2); //Adding an existing edge fails silently
  gA.add_edge(2,1); //Adding an existing edge fails silently
  gA.display();
  */


  AdjacencyMatrix gB; //create empty graph
  gB.add_vertex(); //add four vertices
  gB.add_vertex();
  gB.add_vertex();
  gB.add_vertex();

  gB.add_edge(0,1);
  gB.add_edge(0,2);
  gB.add_edge(0,3);
  gB.add_edge(1,2);
  gB.add_edge(1,3);
  gB.add_edge(2,3);
  // First display
  gB.display();
  gB.remove_vertex(1);
  // Second display
  gB.display();
  gB.remove_edge(2,0);
  // Third display
  gB.display();

  return 0;
}
