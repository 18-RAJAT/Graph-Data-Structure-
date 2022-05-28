// #include<bits/stdc++.h>
// #include<algorithm>
// using namespace std;
// typedef vector<pair<int,pair<int,int>>>viii;

// viii Kruksals(viii g , int V)
// {
//     vii result;
//     int s,d,w;
//     int parent[V];
//     for(int i=0;i<V;++i)
//     parent[i] = -1;

//     sort(g.begin(),g.end());
//     int E = g.size();
//     for(int i=0;i<E;++i)
//     {
//         s=g[i].second.first;
//         d=g[i].second.second;
//         w=g[i].first;

//         if(find(s,parent)!=find(d,parent))
//         {
//             result.push_back(g[i]);
//             UnionByWeight(s,d,parent);
//         }
//     }
//     return result;
// }


// int main()
// {
//     viii g,result;
//     int V,E,s,d,w;
//     cin>>V>>E;
//     for(int i=0;i<E;++i)
//     {
//         cin>>s>>d>>w;
//         g.push_back(make_pair(w,make_pair(s,d)));
//     }
//     result = Kruksals(g,V);
//     int sum=0;
//     for(int i=0;i<result.size();++i)
//     {
//         int w = result[i].first;
//         cout<<result[i].second.first<<" "<<result[i].second.second<<endl;
//         sum += w;
//     }
//     cout<<"Sum of weights is = "<<sum<<endl;
// }




///////////----------------------------------------------------------------------------------------------------------------------------------------/////////////


#include<bits/stdc++.h>
using namespace std;

const int M=1e6-1;
int parent[M];

int find(int a)
{
    while(parent[a]!=a)
    {
        parent[a]=parent[parent[a]];
        a=parent[a];
    }
    return a;
}
void unionFind(int a,int b)
{
    int d = find(a);
    int e = find(b);

    parent[d]=parent[e];
}

int main()
{
    int vertices;
    cout<<"Enter the vertices:"<<"\n";
    cin>>vertices;

    int edges;
    cout<<"Enter the edges:"<<"\n";
    cin>>edges;

    vector<pair<int,pair<int,int>>>adj;
    for(int i=0;i<edges;++i)
    {
        int source, destination, weight;
        cout << "Enter the : \n source - destination - weight \n";
        cin >> source >> destination >> weight;

        adj.push_back({weight, {source, destination}});
    }
    sort(adj.begin(),adj.end());

    for(int i=0;i<M;++i)
    {
        parent[i]=i;
    }
    vector<pair<int,int>>TreeEdge;
    int totalWeight=0;

    for(auto x : adj)
    {
        int a=x.second.first;
        int b=x.second.second;

        int cost=x.first;

        if(find(a) != find(b))
        {
            totalWeight=totalWeight+cost;
            unionFind(a,b);
            TreeEdge.push_back({a,b});
        }
    }

    cout<<"Edges are :"<<"\n";
    for(auto x : TreeEdge)
    {
        cout<<x.first<<" "<<x.second<<" "<<"\n";
    }

    cout<<"Total weight of MST is :";
    cout<<"\n";

    cout<<totalWeight<<" ";
    return 0;
}
