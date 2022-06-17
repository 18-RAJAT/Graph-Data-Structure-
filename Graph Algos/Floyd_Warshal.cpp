#include"bits/stdc++.h"
using namespace std;

int main(){

    int v,e;
    cin>>v>>e;

    vector<vector<int>> dp(v+1,vector<int>(v+1,INT_MAX/2));
    vector<vector<pair<int,int>>> graph(v+1);
    for(int i=0;i<e;i++){
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back({y,w});
        dp[x][y]=w;
    }

    for(int i=1;i<=v;i++)
        dp[i][i]=0;

    for(int k=1;k<=v;k++){
        for(int i=1;i<=v;i++){
            for(int j=1;j<=v;j++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        }
    }
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}