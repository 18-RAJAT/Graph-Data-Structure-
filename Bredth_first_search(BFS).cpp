//using queue data structure like FIFO order....!!

#include<bits/stdc++.h>
using namespace std;

const int N =1e5+10;
vector<int>g[N];

int vis[N];
int level[N];

void bfs(int source)
{
   queue<int>q;
   q.push(source);

   vis[source] = 1;

   while(!q.empty())
   {
       int current_v = q.front();

       q.pop();

       //print the order is >>
       cout<< current_v <<endl;

       //sare connected child ko queue main daalne k liee
       for(int child : g[current_v])
       {Z
          if (!vis[child])
        {
           q.push(child);
           vis[child]=1;   //insert krne k baad un sbko visited 1 show krne k liee...!!

          //stroing the level...!!

          level[child] = level[current_v]+1;
       }
    }
   }
}

int main()
{
    int n;
    cin>>n;

    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x;
        cin>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);

    for(int i=1;i<=n;++i)
    {
        cout<<i<<"->"<<level[i]<<endl;

    }
    return 0;

}