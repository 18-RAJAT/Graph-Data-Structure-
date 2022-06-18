//#include<bits/stdc++.h>
//using namespace std;
//
//void edge(vector<int>adj[],int u,int v)
//{
//    adj[u].push_back(v);
//}
//
//void dfs(int s,vector<int>adj[],bool visit[])
//{
//    stack<int>stk;
//    stk.push(s);
//    visit[s]=true;
//    while(!stk.empty())
//    {
//        int u=stk.top();
//        cout<<u<<" ";
//        stk.pop();
//
//        for(int i=0;i<adj[u].size();++i)
//        {
//            if(!visit[adj[u][i]])
//            {
//                stk.push(adj[u][i]);
//                visit[adj[u][i]]=true;
//            }
//        }
//    }
//}
//
//int main()
//{
//    vector<int>adj[5];
//    bool visit[5];
//
//    for (int i=0;i<5;++i) {
//        visit[i]=false;
//    }
//
//    edge(adj,0,1);
//    edge(adj,0,2);
//    edge(adj,1,3);
//    edge(adj,1,2);
//    edge(adj,2,1);
//
//    cout<<"DFS TRAVERSAL is :"<<" ";
//    dfs(0,adj,visit);
//    cout<<endl;
//}






#include<bits/stdc++.h>
using namespace std;

void edge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
}

void dfs(int s,vector<int>adj[],bool visited[])
{
    stack<int>stk;
    stk.push(s);
    visited[s]=true;

    while(!stk.empty())
    {
        int u=stk.top();
        cout<<u<<" ";
        stk.pop();

        for(int i=0;i<adj[u].size();++i)
        {
            if(!visited[adj[u][i]])
            {
                stk.push(adj[u][i]);
                visited[adj[u][i]]=true;
            }
        }
    }
}


int main() {
    vector<int> adj[5];
    bool visit[5];

    for (int i = 0; i < 5; ++i) {
        visit[i] = false;
    }

    edge(adj, 0, 1);
    edge(adj, 0, 2);
    edge(adj, 1, 3);
    edge(adj, 1, 2);
    edge(adj, 2, 1);

    cout << "DFS TRAVERSAL is :" << " ";
    dfs(0, adj, visit);

}
