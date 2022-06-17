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
        cout << "Enter the : \n Source - Destination \n";
        cin >> source  >> destination >> weight;

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
        cout<<x.first<<" -> "<<x.second<<" "<<"\n";
    }

    cout<<"Total weight of MST is :";
    cout<<"\n";

    cout<<totalWeight<<" ";
    return 0;
}
//
////-------------------------------------------------------------------------------------------------------------------------------------//
//
//
//#include<bits/stdc++.h>
//using namespace std;
//const int M=1e6-1;
//int parent[M];
//
//int find(int a)
//{
//    while(parent[a]!=a)
//    {
//        parent[a]=parent[parent[a]];
//        a=parent[a];
//    }
//    return a;
//}
//
//void unionFind(int a,int b)
//{
//    int d= find(a);
//    int e= find(b);
//
//    parent[d]=parent[e];
//}
//
//int main()
//{
//    int vertices,edges;
//    cout<<"Enter the Vertices:"<<"\n";
//    cin>>vertices;
//
//    cout<<"Enter the edges:"<<"\n";
//    cin>>edges;
//
//    vector<pair<int,pair<int,int>>>adj;
//    for(int i=0;i<edges;++i)
//    {
//        int s,d,w;cin>>s>>d>>w;
//        adj.push_back({w,{s,d}});
//
//    }
//    sort(adj.begin(),adj.end());
//    for(int i=0;i<M;++i)
//    {
//        parent[i]=i;
//    }
//    vector<pair<int,int>>TreeNode;
//    int totalWeight=0;
//
//    for(auto x : adj)
//    {
//        int a=x.second.second;
//        int b=x.second.first;
//
//        int cost=x.first;
//
//        if(find(a)!=find(b))
//        {
//            totalWeight+=cost;
//            unionFind(a,b);
//            TreeNode.push_back({a,b});
//        }
//        cout<<"Edges";
//        for(auto x: TreeNode)
//        {
//            cout<<x.first<<" "<<x.second<<" ";
//        }
//        cout<<"Total weight of MST is :"<<totalWeight<<" "<<"\n";
//    }
//}