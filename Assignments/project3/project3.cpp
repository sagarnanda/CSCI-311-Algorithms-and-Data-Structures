#include<iostream>
#include<map>
#include<fstream>
#include<algorithm>

#include "AdjacencyMatrix.h"
#include "HexMap.h"
#include "distance_between_hexes.h"

using namespace std;

int *total_est_dist; //global variable
std::map<unsigned int, unsigned int> hexToVertex;
std::map<unsigned int, unsigned int> vertexToHex;

bool which_is_closer(unsigned int a, unsigned int b)
{
    return total_est_dist[a] > total_est_dist[b];
}

//returns map to previous, 'best/shortest' vertex
std::map<unsigned int, unsigned int> astar(
        unsigned int start, 
        unsigned int finish, 
        AdjacencyMatrix& am)
{
    int no_of_vertices = am.order();
    set<unsigned int> closed; //holds vertices we no longer process
    vector<unsigned int> open; //holds vertices we still need to process XXX
    // XXX no longer needed: set<unsigned int> visited;

    std::map<unsigned int, unsigned int> parent;//what is returned

    //should be number of vertices
    //holds the distance already traveled for each vertex
    std::vector<int> distance_traveled(no_of_vertices, 99999);

    //recall, total_est_dist is a global variable
    //Here, initialize it to infinity for all entries. # entries
    //equals number of vertices
    //total_est_dist  // = -1;
    total_est_dist = new int[no_of_vertices];
    for(int i = 0; i < no_of_vertices; i++)
    {
        total_est_dist[i]= -1;
    }
    //BTW, total_est_dist for a vertex i is: 
    //distance_traveled[i]+distance_between_hexes(starthex, i)

    //also, initialize to infinity: XXX
    //distance_traveled...

    //get ready to loop
    distance_traveled[start]=0; //XXX
    //est_tot_dist[start]= distance_traveled[start] + distance_between_hexes(start,finish); //XXX
    total_est_dist[start]= distance_traveled[start] + distance_between_hexes(start,finish); //XXX
    open.push_back(start); //add our starting point to 
    std::make_heap(open.begin(), open.end(), which_is_closer);
    //XXX no longer needed  visited.insert(start); //add to our helper set

    //start the loop
    int current  = 0;
    while(!open.empty())
    {
        //XXX
        //use pop_heap on open vector. then current=open.back(), then pop_back to remove it
        std::pop_heap(open.begin(),open.end());
        current = open.back();
        open.pop_back();

        if(current==finish)//stopping condition
            return parent;
        //now don't forget to pop it off of open
        closed.insert(current); 
        //make sure that we don't see this vertex again.
        set<unsigned int> nbor = am.out_neighbors(current);
        for(auto iter = nbor.begin(); iter != nbor.end(); iter++)
        {
           //for(loop on nbor: neighbors of current):
           //    if(nbor is in closed) //don't do it again. We've done it before
           //    continue;
           auto it = closed.find((*iter));
           if( it != closed.end() )
              continue;
           /*
           set a tentative distance traveled for the nbor
               =distance_traveled[current] +
               myAdjacencyMatrix.weight(current, nbor);
               */
           int tentative_dist_traveled =  distance_traveled[current] + am.weight(current, (*iter));
           //XXX      if(visited.count(nbor)==0)  
           //XXX      {
           //XXX        //add nbor to visited
           //XXX        //add nbor to the priority queue "open"
           //XXX      }
           //if nbor isn't in open vector
               //add nbor to open vector
               //(re)make the heap
           //unsigned int nbor_vertex = *iter;
           if(std::find(open.begin(), open.end(), (*iter)) == open.end())
           {
              open.push_back((*iter));
              std::make_heap(open.begin(), open.end(), which_is_closer);
           }
           else if(tentative_dist_traveled >= distance_traveled[(*iter)])
           {
               continue; //Nope, visit next neighbor
           }
           parent[(*iter)]=current; //best predecessor for this neighbor
           distance_traveled[(*iter)]= tentative_dist_traveled;
           //est_tot_dist[nbor]=distance_traveled[nbor]+ distance_between_hexes(vertexToHex(nbor), vertexToHex(finish));
           total_est_dist[(*iter)]=distance_traveled[(*iter)]+ distance_between_hexes(vertexToHex[(*iter)], vertexToHex[finish]);
           std::make_heap(open.begin(), open.end(), which_is_closer);
           //note that nbor and finish are vertices, 
           //but, distance_between_hexes takes two hex numbers.
           //Be sure to use vertexToHex for nbor and finish
           //XXX  here, (re)make_heap
        }//end for loop
        //end while loop
    }
    return parent;
}

int main()
{   
    int hex1 = 0, hex2 =0;
    string weight;
    AdjacencyMatrix mygameboard;
    //Reading terrain_costs.data 
    std::map<char, int> cost;
    char terrain_type;
    int type_cost = 0;
    ifstream file("terrain_costs.data");
    while(file >> terrain_type >> type_cost)
    {
        cost[terrain_type] = type_cost;
    }
    //Reading mapedges.data
    ifstream file1("mapedges.data");
    while(file1>>hex1>>hex2>>weight)
    {
        if(hexToVertex.count(hex1)==0)
        {
            unsigned int v1=mygameboard.add_vertex(); //x will be ??
            hexToVertex[hex1]=v1;
            vertexToHex[v1]=hex1;
        }
        if(hexToVertex.count(hex2)==0)
        {
            unsigned int v2=mygameboard.add_vertex(); //x will be ??
            hexToVertex[hex2]=v2;
            vertexToHex[v2]=hex2;
        }
        //Calculating weight
        int w =0;
        for(int i = 0; i < weight.length(); i++)
        {
            w += cost[weight[i]];
        }
        mygameboard.add_edge(hexToVertex[hex1], hexToVertex[hex2], w);       
    }

    unsigned int startVertex = hexToVertex[1605];
    unsigned int endVertex = hexToVertex[309];
    std::map<unsigned int, unsigned int> sc = astar(startVertex, endVertex, mygameboard);
    HexMap hexMap(309);
    /*
    cout << "Start vertex " << startVertex << endl;
    cout << "End vertex " << endVertex << endl;
    cout << sc.size() << endl;
    for(auto iter = sc.begin(); iter != sc.end(); iter++)
    {
        cout << iter->first << ", ";
        cout << iter->second << endl;
    }
    */
    while(sc.count(endVertex)==1)
    {
        int hex = vertexToHex[endVertex];
        hexMap.add(hex);
        endVertex=sc[endVertex]; //assigns the previous 
    }

    return 0;
}
