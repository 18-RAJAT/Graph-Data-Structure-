#include<bits/stdc++.h>
using namespace std;

//edges maximum limit is...!!
const int N =1e3;

//global variable is already 0
int graph [N][N];

int main()
{
    int n,m;
    cin>>n;
    cin>>m;

    int graph[n+1] [n+1];

    for(int i=0;i<m;i++)
    {

        //vertex 1 and vertex 2
        int v1,v2;
        cin>>v1;
        cin>>v2;

     //connected the graph in adj matrix
        graph [v1] [v2] = 1;
        graph [v2] [v1] = 1;
    }
    
    //space complexity is O(n^2)-->not efficient...!!

    //N = 10^6-->maximum matrix limit and this code is cross...!! 

    //then we wll use adj list XD:)
}
