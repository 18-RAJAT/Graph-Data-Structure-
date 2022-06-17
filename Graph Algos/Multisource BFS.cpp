////
//// Created by rajat joshi on 09-06-2022.
////
//#include<bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    vector<int> sources;
//
//    unordered_map<int,bool> vis;
//    unordered_map<int,int> dist;
//    queue<int> q;
//
//    for(int i = 0;i<sources.size();i++){
//        vis[sources[i]] = true;
//        dist[sources[i]] = 0;
//        q.push(sources[i]);
//    }
//// then proceed as usual
//
//
//    while(!q.empty()){
//        int p = q.front();
//        q.pop();
//
//        for(int i = 0;i< g[p].size();i++){
//            if(!vis[g[p][i]]){
//                vis[g[p][i]] = true;
//                dist[g[p][i]] = dist[p] + 1;
//                q.push(g[p][i]);
//            }
//        }
//    }
//}