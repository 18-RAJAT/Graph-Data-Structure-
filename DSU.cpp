////
//// Created by rajat joshi on 29-05-2022.
////
//
//#include<bits/stdc++.h>
//using namespace std;
//
//vector<int> dsuf;
////FIND operation
//int find(int v)
//{
//    if(dsuf[v]==-1)
//        return v;
//    return find(dsuf[v]);
//}
//
//void union_op(int fromP,int toP)
//{
//    fromP = find(fromP);
//    toP = find(toP);
//    dsuf[fromP] = toP;
//}
//
//bool isCyclic(vector<pair<int,int>>& edge_List)
//{
//    for(auto p: edge_List)
//    {
//        int fromP = find(p.first);	//FIND absolute parent of subset
//        int toP = find(p.second);
//
//        if(fromP == toP)
//            return true;
//
//        //UNION operation
//        union_op(fromP,toP);	//UNION of 2 sets
//    }
//    return false;
//}
//
//int main()
//{
//    int E;	//No of edges
//    int V;	//No of vertices (0 to V-1)
//    cin>>E>>V;
//
//    dsuf.resize(V,-1);	//Mark all vertices as separate subsets with only 1 element
//    vector<pair<int,int>> edge_List;	//Adjacency list
//    for(int i=0;i<E;++i)
//    {
//        int from,to;
//        cin>>from>>to;
//        edge_List.push_back({from,to});
//    }
//
//    if(isCyclic(edge_List))
//        cout<<"TRUE\n";
//    else
//        cout<<"FALSE\n";
//
//    return 0;
//}
//
//
////

#include<bits/stdc++.h>
using namespace std;

vector<int>dsuFind;
int find(int v)
{
    if(dsuFind[v]==-1){return v;}
    return (dsuFind[v]);
}

void unionOp(int from,int to)
{
    from=find(from);
    to=find(to);
    dsuFind[from]=to;
//    return from==to;
}

bool isCycle(vector<pair<int,int>>&edge)
{
    for(auto p : edge)
    {
        int from=find(p.first);
        int to=find(p.second);

        if(from==true){return true;}

        unionOp(from,to);
    }
    return false;
}

int main()
{
    int v,e;cin>>e>>v;
    dsuFind.resize(v,-1);
    vector<pair<int,int>>edge;

    for(int i=0;i<e;++i)
    {
        int from,to;cin>>from>>to;
        edge.push_back({from,to});

        if(isCycle(edge))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}