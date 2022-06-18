//
// Created by rajat joshi on 05-06-2022.
//
#include<bits/stdc++.h>
using namespace std;
#define V 5
#define pb push_back

unordered_map<int,vector<int>> adj;

void DFS(int u,vector<int>& disc,vector<int>& low,vector<int>& parent,vector<pair<int,int>>& bridge)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time+=1;

    for(int v: adj[u])
    {
        if(disc[v]==-1)	//If v is not visited
        {
            parent[v] = u;
            DFS(v,disc,low,parent,bridge);
            low[u] = min(low[u],low[v]);

            if(low[v] > disc[u])
                bridge.pb({u,v});
        }
        else if(v!=parent[u])	//Ignore child to parent edge
            low[u] = min(low[u],disc[v]);
    }
}

void findBridges_Tarjan()
{
    vector<int> disc(V,-1),low(V,-1),parent(V,-1);
    vector<pair<int,int>> bridge;

    for(int i=0;i<V;++i)
        if(disc[i]==-1)
            DFS(i,disc,low,parent,bridge);

    cout<<"Bridges are: \n";
    for(auto it: bridge)
        cout<<it.first<<"-->"<<it.second<<"\n";
}

int main()
{
    adj[0].pb(2);
    adj[2].pb(0);
    adj[0].pb(3);
    adj[3].pb(0);
    adj[1].pb(0);
    adj[0].pb(1);
    adj[2].pb(1);
    adj[1].pb(2);
    adj[3].pb(4);
    adj[4].pb(3);

    findBridges_Tarjan();
    return 0;
}

//TIME COMPLEXITY: O(V+E)