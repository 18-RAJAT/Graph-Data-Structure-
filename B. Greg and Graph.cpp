/*                         <PROBLEM STATEMENT>

Greg has a weighed directed graph, consisting of n vertices. In this graph any pair of distinct vertices has an edge between 
them in both directions. Greg loves playing with the graph and now he has invented a new game:

The game consists of n steps.
On the i-th step Greg removes vertex number xi from the graph. As Greg removes a vertex, he also removes all the edges that
go in and out of this vertex.
Before executing each step, Greg wants to know the sum of lengths of the shortest paths between all pairs of the remaining 
vertices. The shortest path can go through any remaining vertex. In other words, if we assume that d(i, v, u) is the shortest
path between vertices v and u in the graph that formed before deleting vertex xi, then Greg wants to know the value of the
following sum: .
Help Greg, print the value of the required sum before each step.


*/

#include<bits/stdc++.h>
using namespace std;

const int N = 510;
const int INF = 1e5+10;

long long dist [N][N];

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>dist[i][j];
        }
    }

    vector<int> deletion_order(n);
    for(int i=0;i<n;++i)
    {
        cin>>deletion_order[i];
    }

    //reverse order floyd algorithm

    reverse(deletion_order.begin(),deletion_order.end());
    vector<long long>ans;

     //flyod warshall
    for(int k=0;k<n;++k)
    {
        int kthlevel_v = deletion_order[k];
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                long long new_distance = dist[i][kthlevel_v] + dist[kthlevel_v][j];
                dist[i][j] = min(dist[i][j],new_distance);
            }
        }
        
        long long sum =0;
        for(int i=0;i<=n;++i)
        {
        for(int j=0;j<=n;++j)
        {
            sum += dist[deletion_order[i]] [deletion_order[j]];
        }
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());

    for(auto val : ans)
    {
        cout<<val<<" "<<endl;
    }
}
