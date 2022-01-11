
//if weight is given>>>

#include<bits/stdc++.h>
using namespace std;

const int N =1e3;

int graph [N][N];

vector<pair <int,int> >graph2[N];
int main()
{
    int n,m;
    cin>>n;
    cin>>m;

    int graph[n+1] [n+1];

    for(int i=0;i<m;i++)
    {
        int v1,v2,wt;
        cin>>v1;
        cin>>v2;
       
       //weighted graph input..!!

        graph [v1] [v2] = wt;
        graph [v2] [v1] = wt;
     
        graph2[v1].push_back({v2 , wt}); 
        
        graph2[v2].push_back({v1 , wt});        

    }
      //i,j connected ? and i,j>wt? -->this ans is given by O(1)time 
    
    if(graph [n][m] == 1 )
    {
       //connected
    }

    graph [n][m];

    for(pair<int,int>child : graph2[n])
    {
        if(child.first == m)
        {
            //connected
            child.second;
        }
    } 
}