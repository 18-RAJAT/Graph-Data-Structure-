#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>>g[N];
vector<int>lev(N,INF);

int n,m;

//BREDTH FIRST SEARCH
int bfs()
{
    deque<int>q;
    q.push_back(1);
    
    lev[1]=0;

    while(!q.empty())
    {
        int current_v = q.front();
        q.pop_front();

        for(auto child : g[current_v])
        {
            int child_v = child.first;
            int weight = child.second;

            if(lev[current_v]+weight<lev[child_v])
            {
                lev[child_v] = lev[current_v]+weight;

                if(weight == 1)
                {
                    q.push_back(child_v);
                }

                else
                {
                    q.push_back(child_v);
                }
            }
        }
    }

    return lev[N] = INF ? -1 : lev[N]; 
}

int main()
{
    cin>>n;
    cin>>m;

    for(int i = 0;i<n;++i)
    {
        int x,y;
        cin>>x;
        cin>>y;

        g[x].push_back({y,0});
        g[y].push_back({x,1});
    }

    cout<< bfs() <<endl;
}