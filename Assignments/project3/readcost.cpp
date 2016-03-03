#include<iostream>
#include<map>
#include<fstream>

using namespace std;

int main()
{
    std::map<char, int> cost;
    char terrain_type;
    int type_cost = 0;
    ifstream file("terrain_costs.data");
    while(file >> terrain_type >> type_cost)
    {
        cost[terrain_type] = type_cost;
    }

    cout << cost['.'] << endl;
    string weight = ".wtrufht";
    int w;
    for(int i = 0; i < weight.length(); i++)
    {
        //cout<<weight.length()<<endl;
        //cout<<"i ="<< i <<endl;
        //cout<<"cost of i ="<< cost[weight[i]] <<endl;
        w += cost[weight[i]];
    }
        cout<<w<<endl;
}
