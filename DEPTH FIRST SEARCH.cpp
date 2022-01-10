#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int>g[N];
bool vis[N];
//creating a DFS function...!!

void dfs(int vertex)
{
   /*1. TAKE action on vertex after entering 

   the VERTEX*  >>>>>>>>>>>>>   ye section neeche*/

   cout<<vertex<<endl;

   vis[vertex] = true;


   //for loop is use >>> children ka loop-->recursion type call
   for(int child : g[vertex])
   {
       cout<<"parent"<<vertex<< " "<<"child"<<child<<endl;

       /*2. TAKE action on child before entering 

       the child NODE    >>>>>>>>>>>>>   ye section neeche*/
      if(vis[child]) continue;

       dfs(child);

       /* 3.TAKE action on child after exiting 

       child NODE      >>>>>>>>>>>>>   ye section upper ko*/
   }

  /*4. TAKE action on vertex before exiting 

   the VERTEX      >>>>>>>>>>>>>   ye section upper ko*/ 
}

int main()
{
  int n,m;
  cin>>n;
  cin>>m;
  
  for(int i=0;i<9;++i)
  {
      int v1 , v2;

      cin>>v1;
      cin>>v2;
     
     //undirected graph...!!

      g[v1].push_back(v2);
      g[v2].push_back(v1);     
  }

}

/*TIME COMPPLEXITY----->>>>>
(recursive function) combine

total number of computation is = edegs count

then O(V+E)-->combined for loop

*/