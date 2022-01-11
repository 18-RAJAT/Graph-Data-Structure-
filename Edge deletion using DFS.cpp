#include<bits/stdc++.h>
using namespace std;

const int N =1e5+10;
const int M =1e9+7;

vector<int>g[N];

int subtree_sum[N];

void dfs(int vertex,int par)
{
     
     //weight store...!!

    subtree_sum[vertex] += val[vertex-1];
    for(int child : g[vertex])
    {
        if(child == par) continue;

        dfs(child,vertex);

        subtree_sum[vertex] += subtree_sum[child];
    }
}

//tree input

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
    dfs(1,0);  //default parent value is initialy 0...!!


     //we can not seeing any overflow...!!
     long long ans = 0;

     for(int i=2;i<=n;++i)
     {
     //i k upper vali edge delete aur uske lie ek part ka sun find krenge and then i subtree sun...!!
     
     int part1 = subtree_sum[i];

     //total sum...
     int part2 = subtree_sum[1] - part1;

     ans = max(ans,(part1 * 1LL * part2)%M );



     }

}


