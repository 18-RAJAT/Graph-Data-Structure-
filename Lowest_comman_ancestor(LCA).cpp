#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int>g[N];

int par[N];

//store the parent...!!

void dfs(int v,int p=-1)  //p =-1 is a default value...!!
{

    //store the parent
    par[v] = p;
    for(int child : g[v])
    {
        if(child == p) continue;

        dfs (child,v);
    }
}


vector<int>path(int v)
{
    //path store is here
    vector<int>ans;

    while(v !=-1)
    {
        ans.push_back(v);

        v = par[v];
    }

    //ulta vector we will get , XD:)

    reverse(ans.begin() , ans.end());
    {
        return ans;
    }

}

//tree construct
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
      
      //parent store...!!

     dfs(1);//default


    //jin 2 node ka lca find krna hai uska input...!!

    int x,y;
    
    cin>>x;
    cin>>y;

    vector<int> path_x = path(x);

    vector<int> path_y = path(y);

    //find the minimum length is ....!!

    int min_length = min(path_x.size(),path_y.size());

    int lca = -1;
    for(int i =0;i<min_length;++i)
    {
        if(path_x[i] == path_y[i])
        {
            lca = path_x[i];
        }

        else
        {
            break;
        }
    }

    cout << lca <<endl;

}
