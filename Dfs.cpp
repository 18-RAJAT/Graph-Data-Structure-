
#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin>>t;

    while(t--)
    {
        //no of vertices is n
        //no of edegs is e

        int n,e;
        cin>>n;
        cin>>e;

       //using adj list methood...!!

        vector<int>g[n];
 
        bool vis[n];


        //set all the values... use memset

        memset(vis,false,sizeof(vis));

        for(int i=0;i<e;i++)
        {
            int u,v;
            cin>>u;
            cin>>v;

            g[u].push_back(v);
            g[v].push_back(u);

        }

         dfs(0,g,vis);

        cout<<endl;
    }
}

void dfs (int s,vector<int>g[],bool *vis )
{
  vis[s] = true;

  cout<<" ";

  for(int i=0;i<g[s].size();i++)
  {
   if(vis[g[s][i]] == false)

   dfs(vis[g[s][i]],g,vis);
  }
}

//all about dfs(depth for search)