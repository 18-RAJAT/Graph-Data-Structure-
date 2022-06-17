//#include"bits/stdc++.h"
//using namespace std;
//
//int main(){
//    int v,e;
//    cin>>v>>e;
//
//    vector<vector<pair<int,int>>> graph(v+1);
//
//    vector<pair<int,pair<int,int>>> p;
//
//    for(int i=0;i<e;i++){
//        int x,y,w;
//        cin>>x>>y>>w;
//        graph[x].push_back({y,w});
//        p.push_back({w,{x,y}});
//    }
//
//    vector<int> dis(v+1,INT_MAX/2);
//    dis[0]=0; //setting staring node's distance = 0
//
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



#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;cin>>v>>e;
    vector<vector<pair<int,int>>>graph(v+1);
    vector<pair<int,pair<int,int>>>p;

    for(int i=0;i<e;++i)
    {
        int x,y,w;cin>>x>>y>>w;
        graph[x].push_back({y,w});
        p.push_back({w,{x,y}});
    }
    vector<int>dis(v+1,INT_MAX/2);
    dis[0]=0;
    for(int i=0;i<v-1;++i)
    {
        for(auto it: p)
        {
            int x=it.second.first;
            int y=it.second.second;
            int w=it.first;

            if(dis[x]!=INT_MAX and dis[x]+w<dis[y])
            {
                dis[w]=dis[x]+w;
            }
        }

        for(int i=1;i<=e;++i)
        {
            cout<<dis[i]<<" ";
        }
    }
}