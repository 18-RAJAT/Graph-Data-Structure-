#include<bits/stdc++.h>
using namespace std;

int find(int u,int*parent)
{
    if(parent[u]<0)return u;
    return find(parent[u],parent);
}

void UnionByWeight(int u,int v,int *parent)
{
    int pu = find(u,parent);
    int pv = find(v,parent);

    if(pu != pv)
    {
        if(parent[pu] < parent[pv])
        {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else
        {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}