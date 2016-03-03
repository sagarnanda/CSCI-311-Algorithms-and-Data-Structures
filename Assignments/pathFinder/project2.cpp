#include<iostream>
#include<stdlib.h>
#include<map>
#include"AdjacencyList.h"
#include"AdjacencyMatrix.h"
#include"HexMap.h"
#include"Graph.h"
#include<fstream>

using namespace std;

int main()
{
    std::map<unsigned int, unsigned int> hexToVertex;
    std::map<unsigned int, unsigned int> vertexToHex;
    int hex1 = 0, hex2 =0;
    string weight;
    string hex1_str;
    string hex2_str;
    ifstream file("mapedges.data");
    AdjacencyList mygameboard;
    //while(!file.eof())
    while(file >> hex1 >> hex2 >> weight)
    {
        if(weight == "w")
            continue;
        if(hexToVertex.count(hex1)==0)
        {
            unsigned int v1=mygameboard.add_vertex(); //x will be ??
            //cout << "vertex " << v1 << " hex " << hex1 << endl;
            hexToVertex[hex1]=v1;
            vertexToHex[v1]=hex1;
        }
        if(hexToVertex.count(hex2)==0)
        {
            unsigned int v2=mygameboard.add_vertex(); //x will be ??
            //cout << "vertex " << v2 << " hex " << hex2 << endl;
            hexToVertex[hex2]=v2;
            vertexToHex[v2]=hex2;
        }
        mygameboard.add_edge(hexToVertex[hex1], hexToVertex[hex2]);
    }
    //end of while loop //file read

    //Add edges to map
    Graph *g = new AdjacencyList(hexToVertex.size());
    for(int i =0; i < mygameboard.order(); i++)
    {
        set<unsigned int> neighbor = mygameboard.neighbors(i);
        for(auto it = neighbor.begin(); it != neighbor.end(); it++)
        {
            g->add_edge(i, *it);
        }
    }
    //TODO- test if the graph g is correct
    //cout << "************* Graph " << endl;
    //g->display();
    //cout << "************* Graph " << endl;
    /*
    int size = g->order();
    cout << " size is " << size << endl;
    for(int i =0; i < size; i++)
    {
        cout << i << "(" << vertexToHex[i] << ")";
        set<unsigned int> n = g->neighbors(i);
        for(auto it = n.begin(); it != n.end(); it++)
        {
            cout << ", " << *it << "(" << vertexToHex[*it] << ")";
        }
        cout << endl;
    }
    */

    unsigned int startVertex = hexToVertex[1605];
    unsigned int endVertex = hexToVertex[309];
    //cout << "start " << startVertex << " end " << endVertex << endl;

    //Implement BFS on the graph g
    map<unsigned int, unsigned int> sc;
    HexMap hexMap(309);
    //hexMap.add(endVertex);
    sc = g->breadth_first_search(startVertex);
    /*
    cout << "size of the sc " << sc.size() << endl;
    for(auto it = sc.begin(); it != sc.end(); it++)
    {
        cout << vertexToHex[it->first] << "-->" << vertexToHex[it->second] << endl;
    }
    */
    while(sc.count(endVertex)==1)
    {
        int hex = vertexToHex[endVertex];
        //cout << hex << endl;
        hexMap.add(hex); 
        endVertex=sc[endVertex]; //assigns the previous 
    }
    return 0;
}
