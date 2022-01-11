#include<bits/stdc++.h>
using namespace std;
#define V 6 //no of vertices

int selectMinVertices(vector<int>& value,vector<bool>& processed)
{
    int minimum = INT_MAX;
    int vertex;
    for(int i=0;i<V;++i)
    {
        if(processed[i]==false && value[i]<minimum)
        {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}


void dijkstra(int graph[V][V])
{
    int parent[V];   //store shortest path structure

    vector<int> value(V,INT_MAX); //keeps shortest path values to each vertex from source

    vector<bool> processed(V,false); //True->vertex is processed


    //Assuming start point as node-0

    parent[0] = -1; //start node has no parent

    value[0] = 0; //start node has value=0 to picked 1st

    //include (v-1) edges to cover all the V-vertices
    for(int i =0;i<V-1;++i)
    {
        //select best vertex by applying GREEDY_METHOOD...!!

        int U = selectMinVertices(value,processed);

        processed[U] = true; //include new vertices in shortest path graph

        //relex adjacement vertices (not yet include in shortest path graph)

        for(int j=0;j<V;++j)
        {
            /*
                3 CONDITIONS TO RELEX->
                
                1.edge is permanent from U to j
                2.vertex j is not included in shortest path graph
                3.edge weight is smaller than current edge weight
            */

           if(graph[U][j] !=0 && processed[j] == false && value[U] != INT_MAX
           && (value[U] + graph[U][j] < value[j]))
           {
               //update the value(parent)
               value[j] = value[U] + graph[U][j];
               parent[j] = U;
           }
        }
    }

    //print shortest path graph

    for(int i =1;i<V;++i)
    {
        cout<<"U->V: "<<parent[i]<<"->"<<i<<" wt = "<<graph[parent[i]][i]<<endl;
    }
}

int main()
{
    int graph[V][V] = 
    {
        {0,1,4,0,0,0},
        {1,0,4,2,7,0},
        {4,4,0,3,5,0},
        {0,2,3,0,4,6},
        {0,7,5,4,0,7},
        {0,0,0,6,7,0}
    };

    dijkstra(graph);
    return 0;
}