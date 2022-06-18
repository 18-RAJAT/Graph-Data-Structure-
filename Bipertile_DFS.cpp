//
// Created by rajat joshi on 18-06-2022.
//

// Bipartite graph

#include<bits/stdc++.h>
using namespace std;
vector<int> arr[100];
int visited[100];
// array for colour
int col[100];

// function for dfs
bool dfs(int v,int c)
{
    visited[v]=1;
    col[v]=c;
    for(int child:arr[v])
    {
        if(visited[child]==0)
        {
            auto f=dfs(child,c^1);
            if(f==false)
            {
                return false;
            }
        }
        else
        {
            if(col[v]==col[child])
                return false;
        }
    }
    return true;
}

//Driver function
int main()
{
    int n,m;
    printf("Enter number vertex and number of edges\n");
    cin>>n>>m;
    int a,b;
    cout<<"Enter all the edges"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    auto c=dfs(1,1);
    if(c==false)
        cout<<"Not a Bipartite graph";
    else
        cout<<"Bipartite graph";
    return 0;
}