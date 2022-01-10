#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

bool vis[N];

vector<int>g[N];
//creating a DFS function...!!

bool dfs(int vertex,int parent )
{
   /*1. TAKE action on vertex after entering 
   the VERTEX*/

   cout<<vertex<<endl;

   vis[vertex] = true;

   bool isloopexist =false;


   //for loop is use >>> children ka loop-->recursion type call
   for(int child : g[vertex])
   {
       cout<<"parent"<<vertex<< " "<<"child"<<child<<endl;

       /*2. TAKE action on child before entering 
       the child NODE*/

    if(vis[child] && child == parent) continue;

      if(vis[child]) return true;

    isloopexist |= dfs(child,vertex);

       /* 3.TAKE action on child after exiting 
       child NODE*/
   }

  /*4. TAKE action on vertex before exiting 
   the VERTEX */ 

   return isloopexist;
}

int main()

{

    //int edegs and vertices input....!!
    int n,e;
    cin>>n;
    cin>>e;
   
   //graph input....!!
    for(int i=0;i<e;i++)
    {
        //edegs input.....!!

        int x,y;
        cin>>x;
        cin>>y;

        g[x].push_back(y);
        g[y].push_back(x);

    }
  
    bool isloopexist = false;
   
   for(int i=0;i<-n;i++)
   {
       if(vis[i])
       continue;

       if(dfs(i,0)) // 0 isliye bheja kyuki parent hai...!!
       {
           isloopexist = true;
           break;
       }
   }
    
    cout<<" CYCLE DETECT "<<endl;

   cout<< isloopexist<<endl;
}


/* line no --->> 77....if we gave the parent is 0 output is also 0 becz of 0 is not a part of 
this segment 1 se n tk hai aur 0 part nahi hai kisi ka bhii...!!
*/