#include<bits/stdc++.h>
using namespace std;

const int N =1e5+10;
vector<int>g[N];

//find  the depth

int depth[N];

void dfs(int v,int par=-1)
{
    for(int child : g[v])
    {
        if(child==par) continue;

        depth[child] = depth[v]+1;

        dfs(child,v);
    }
}

int main()
{
   int n;
   cin>>n;

   for(int i=0;i<n;++i)
   {
       int x,y;
       cin>>x;
       cin>>y;

       g[x].push_back(y);
       g[y].push_back(x);
   }

   dfs(1);

   //maximum depth node

    int max_depth =-1;
    int max_d_node;

    

    for(int i=1;i<n;i++)
    {
        if(max_depth < depth[i])

        {
            max_depth = depth[i];
            max_d_node = i;
        }

        depth[i] = 0;
    }

    dfs (max_d_node);

    max_depth = -1;

    for(int i=0;i<=n;++i)
    {
        if(max_depth < depth[i])
        {
            max_depth = depth[i];
        }
    }

    cout<<max_depth<<endl;
}