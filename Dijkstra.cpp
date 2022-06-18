#include<bits/stdc++.h>
using namespace std;
#define v 7

int selectMinVertices(vector<int>&value, vector<int>&processed)
{
    int minimum=INT_MAX;
    int vertex;
    for(int i=0;i<v;++i)
    {
        if(processed[i]==false and value[i]<minimum)
        {
            vertex=i;
            minimum=value[i];
        }
    }
    return vertex;
}

void Dijkstra(int graph[v][v])
{
    int parent[v];
    vector<int> value(v,INT_MAX);
    vector<int> processed(v,false);

    parent[0]=-1;
    value[0]=0;

    for(int i=0;i<v-1;++i)
    {
        int u= selectMinVertices(value,processed);
        processed[u]=true;

        for(int j=0;j<v;++j)
        {
            if(graph[u][j]!=0 and processed[j]==false and value[u]!=INT_MAX and (value[u]+graph[u][j]<value[j]))
            {
                value[j]=value[u]+graph[u][j];
                parent[j]=u;
            }
        }
    }
    for(int i=1;i<v;++i)
    {
        cout<<"u to v "<<parent[i]<<"--->"<<i<<"   "<<"Weight is : "<<graph[parent[i]][i]<<"\n";
    }
}


int main()
{
    int graph[v][v] =
            {
                    {0,0,7,5,0,0,0},
                    {0,0,8,5,0,0,0},
                    {7,8,0,9,7,0,0},
                    {5,0,9,0,15,6,0},
                    {0,5,7,15,0,8,9},
                    {0,0,0,6,8,0,11},
                    {0,0,0,0,9,11,0}
            };
    Dijkstra(graph);
    return 0;
}