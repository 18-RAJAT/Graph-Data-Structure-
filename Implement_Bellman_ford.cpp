//
// Created by rajat joshi on 17-06-2022.
//


#include<bits/stdc++.h>
using namespace std;

struct edge{
    int src,dst,wt;
};
int V,E;

void bellmanFord(vector<edge>& Edges)
{
    int parent[V];
    int cost_parent[V];
    vector<int> value(V,INT_MAX);

    parent[0] = -1;
    value[0] = 0;
    bool updated;
    for(int i=0;i<V-1;++i)
    {
        updated = false;
        for(int j=0;j<E;++j)
        {
            int U = Edges[j].src;
            int V = Edges[j].dst;
            int wt = Edges[j].wt;
            if(value[U]!=INT_MAX and value[U]+wt<value[V])
            {
                value[V] = value[U]+wt;
                parent[V] = U;
                cost_parent[V] = value[V];
                updated = true;
            }
        }
        if(updated==false)
            break;
    }
    for(int j=0;j<E and updated==true;++j)
    {
        int U = Edges[j].src;
        int V = Edges[j].dst;
        int wt = Edges[j].wt;
        if(value[U]!=INT_MAX and value[U]+wt<value[V])
        {
            cout<<"Graph has -VE edge cycle\n";
            return;
        }
    }
    for(int i=1;i<V;++i)
        cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Time to reach "<<parent[i]<<"from source 0 => "<<value[i]<<"\n";
}

int main()
{
    cin>>V>>E;
    vector<edge> Edges(E);
    int src,dst,wt;
    for(int i=0;i<E;++i)
    {
        cin>>src>>dst>>wt;
        Edges[i].src = src;
        Edges[i].dst = dst;
        Edges[i].wt = wt;
    }

    bellmanFord(Edges);
    return 0;
}





//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    int v,e;
//    cin>>v>>e;
//
//    // Making directed graph
//    vector<vector<pair<int,int>>> graph(v+1);
//    vector<pair<int,pair<int,int>>> p;
//
//    for(int i=0;i<e;i++){
//        int x,y,w;
//        cin>>x>>y>>w;
//        graph[x].push_back({y,w});
//        p.push_back({w,{x,y}});
//    }
//    vector<int> dis(v+1,INT_MAX/2);
//    dis[0]=0;
//    for(int i=0;i<v-1;i++){
//        for(auto it:p){
//            int x=it.second.first; // source node
//            int y=it.second.second; // destination node
//            int w=it.first; // weight
//            if(dis[x]!=INT_MAX && dis[x]+w<dis[y])
//                dis[y]=dis[x]+w;
//        }
//    }
//
//    for(int i=1;i<=v;i++){
//        cout<<dis[i]<<" ";
//    }
//}