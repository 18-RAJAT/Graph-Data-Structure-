
// //This is the basic DFS....!!

// #include<bits/stdc++.h>
// using namespace std;

// const int N = 1e5+10;

// vector<int> g[N];

// void dfs(int vertex,int parent=0)
// {

//     for(int child : g[vertex])
//     {
//         if(child == parent)

//         continue;

//         dfs(child,vertex);
//     }

// }

// int main()
// {
//     int n;
//     cin>>n;

//     for(int i=0;i<n-1;++i)
//     {
//         int x,y;
//         cin>>x;
//         cin>>y;

//         g[x].push_back(y);
//         g[y].push_back(x);

//     }
//       dfs(1);
// }


#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

vector<int> g[N];

int depth[N], height[N];

void dfs(int vertex,int parent=0)
{

    for(int child : g[vertex])
    {
        if(child == parent)

        continue;

        depth[child] = depth[vertex]+1;

        dfs(child,vertex);

        //vertex ki height

        height[vertex] = max(height[vertex],height[child]+1);
    }

}

//graph input...!!
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
      dfs(1);

    //sari vertices ki height print


      for(int i=0;i<=n;++i)
      {
          cout<<depth[i]<<" "<<height[i]<<endl;
      }
}