#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int>g[N];
bool vis[N];
//creating a DFS function...!!

void dfs(int vertex)
{
   /*1. TAKE action on vertex after entering 
   the VERTEX*/

   cout<<vertex<<endl;

   vis[vertex] = true;


   //for loop is use >>> children ka loop-->recursion type call
   for(int child : g[vertex])
   {
       cout<<"parent"<<vertex<< " "<<"child"<<child<<endl;

       /*2. TAKE action on child before entering 
       the child NODE*/
      if(vis[child]) continue;

       dfs(child);

       /* 3.TAKE action on child after exiting 
       child NODE*/
   }

  /*4. TAKE action on vertex before exiting 
   the VERTEX */ 
}

int main()
{
    int n,e;
    cin>>n;
    cin>>e;

    for(int i=0;i<e;i++)
    {
      int x,y;
      cin>>x>>y;

      g[x].push_back(y);
      g[y].push_back(x);
    }

    int ct = 0;
    for(int i=0;i<=n;i++)
    {
        if(vis[i])
        continue;

        dfs(i);

        ct++;
    }

    cout <<ct<<endl;
}