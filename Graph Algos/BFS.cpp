//#include<bits/stdc++.h>
//using namespace std;
//
//void edge(vector<int>adj[],int u,int v)
//{
//    adj[u].push_back(v);
//}
//void bfs(int s,vector<int>adj[],bool visit[])
//{
//    queue<int>q;
//    q.push(s);
//    visit[s]=true;
//
//    while(!q.empty())
//    {
//        int u=q.front();
//        cout<<u<<" ";
//        q.pop();
//
//        for(int i=0;i<adj[u].size();++i)
//        {
//            if(!visit[adj[u][i]])
//            {
//                q.push(adj[u][i]);
//                visit[adj[u][i]]=true;
//            }
//        }
//    }
//}
//
//
//int main()
//{
//    vector<int>adj[5];
//    bool visit[5];
//
//    for(int i=0;i<5;++i)
//    visit[i]=false;
//
//edge(adj,0,1);
//edge(adj,0,2);
//edge(adj,0,3);
//edge(adj,1,2);
//edge(adj,1,3);
//
//    bfs(0,adj,visit);
//
//
//    bfs(0,adj,visit);
//    cout<<"\n";
//}
//
//
//////-----------------------------------------------------------------------------------------------------------------------------//

#include<bits/stdc++.h>
using namespace std;

void edge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
}

void bfs(int s,vector<int>adj[],bool visit[])
{
    queue<int>q;
    q.push(s);
    visit[s]=true;

    while(!q.empty())
    {
        int u=q.front();
        cout<<u<<" ";
        q.pop();

        for(int i=0;i<adj[u].size();++i)
        {
            if(!visit[adj[u][i]])
            {
                q.push(adj[u][i]);
                visit[adj[u][i]];
            }
        }
    }
}


int main()
{
    vector<int>adj[5];
    bool visit[5];

    for(int i=0;i<5;++i)
    {
        visit[i]=false;
    }
    edge(adj,0,1);
edge(adj,0,2);
edge(adj,0,3);
edge(adj,1,2);
edge(adj,1,3);

    bfs(0,adj,visit);
}