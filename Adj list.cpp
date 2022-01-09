#include<bits/stdc++.h>
using namespace std;

//benifit of list is space otimization O(v+e)-->here v is vertices and e is edges

//maximum edegs in a graph is v^2 edges -->higher then constantes...!!


const int N =1e3;

//global variable is already 0
int graph [N][N];


//make n vectors...!! 
vector<int>graph2[N];
int main()
{
    int n,m;
    cin>>n;
    cin>>m;

    int graph[n+1] [n+1];

    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1;
        cin>>v2;

        graph [v1] [v2] = 1;
        graph [v2] [v1] = 1;
        


        //MAKING LIST>>>
        //kon kon kisse connected hai code-->>
        
        //and here v1 vali list mai  v2 ko dalna
        graph2[v1].push_back(v2); 
        
        //and v2 vali list  mai v1 vale ko dalna     
        graph2[v2].push_back(v1);        

    }

    //adj list space complexty is
    
    //O(n+m)

    //N = 10^5
}
