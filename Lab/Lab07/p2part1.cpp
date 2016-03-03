#include<iostream>
#include<map>

#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"

using namespace std;

int main()
{
    int tog=0;
    unsigned int V=0;
    unsigned int E=0;
    unsigned int v1=0 , v2 =0;

    Graph* g;
    cin >> tog >> V >> E;
    switch (tog)
    {
        case 1:
            {
                g=new AdjacencyList(V);
                break;
            }
        case 2 :
            {
                g=new AdjacencyMatrix(V);
                break;
            }
        default:
            {
                cout<<"Does not compute\n";
                return 1;
            }
    }
    for(int i = 0; i < E; i++)
    {
        cin >> v1 >>v2;
        g->add_edge(v1,v2);
    }
    //g->display();
    map<unsigned int,unsigned int> sp;
    sp = g->breadth_first_search(0);
    unsigned int current=34;
    while(sp.count(current)==1)
    {
        cout << current << endl;
        //cout << "current " << current << " sp[current] " << sp[current] << endl;
        current=sp[current]; //assigns the previous 
        //cout << "count " << sp.count(current) << endl;
    }
    cout<<current<<endl;
    /*
    cout<<"Return to main with set"<<endl;
    
    for (auto iter=sp.begin(); iter!=sp.end(); iter++)
    {
        cout << iter->first <<"," << iter->second << "," << endl;
    }
    g->display();
    */
    return 0;
    
}
