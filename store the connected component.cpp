#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int>g[N];


//how to store connected components ....!!

vector<vector<int>>cc;

//global
vector<int>current_cc;


bool vis[N];
//creating a DFS function...!!

void dfs(int vertex)
{
   /*1. TAKE action on vertex after entering 
   the VERTEX*/

   cout<<vertex<<endl;

   vis[vertex] = true;

   current_cc.push_back(vertex);


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

    int ct =0;

    //all k lie nodes dfs 
    for(int i=1;i<=n;i++)
    {

        //i th node is true ...!!
        if(vis[i])
       
        //current connect component ko khali.....!!
        current_cc.clear();


        continue;
       //not visited and when the visited number is find then the get is....!!
        dfs(i);

         //is dfs m jitne nodes ko traverse kia hoga un sbhi ko store krna ....!!
         cc.push_back(current_cc);


        //connected component count....!!
        ct++;

    }

    cout<<cc.size()<<endl;
   
   for (auto c_cc : cc)
   {
       for (int vertex : c_cc)
       {
           cout<<vertex<<" ";
       }

       cout<<endl;

   }

}

/* time complexity is -->>


O(n + e)

   |||

same as dfs 
   
   |||

dfs tc 0(v +e)

*/