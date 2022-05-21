#include<bits/stdc++.h>
using namespace std;

vector<int>disjoint_set_union_find;

//find operation
int find(int V)
{

    if(disjoint_set_union_find[V] == -1)
    return V;
    return find(disjoint_set_union_find[V]);

}

void union_operation(int from,int to)   //here from = first and to = second
{

    from = find(from);
    to = find(to);
    disjoint_set_union_find[from] = to;

}

bool iscycle(vector<pair<int,int>>& edge_list)
{


    for(auto p : edge_list)
    {

        int from = find(p.first); //Find absolute parent of subset
        int to = find(p.second);

        if(from == to)
        return true;

        //UNION OPERATION...!!
        union_operation(from,to);    //union of 2 sets

    }
    return false;

}

int main()
{
    int E; //no of edges
    int V; //no of vertices (0 to V-1)

    cin>>E;
    cin>>V;

    disjoint_set_union_find.resize(V-1); //Mark all vertices  as separate subsets with only 1 element
    vector<pair<int,int>>edge_list; //adjacency list

    for(int i=0;i<E;++i)
    {

        int from,to;
        cin>>from;
        cin>>to;

        edge_list.push_back({from,to});

    }

    if(iscycle(edge_list))
   {
    cout<<"True"<<endl;
   }

   else
   {
       cout<<"False"<<endl;
   }
   return 0;
    
}


//TIME COMPLEXITY: o(E*V)