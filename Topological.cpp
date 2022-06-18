////#include<bits/stdc++.h>
////using namespace std;
////
////void topologicalSortUtils(vector<int>graph[],bool visited[],stack<int>&st,int i)
////{
////    visited[i]=true;
////    int n=graph[i].size();
////
////    for(int j=0;j<n;++j)
////    {
////        if(!visited[graph[i][j]])
////        {
////            topologicalSortUtils(graph,visited,st,graph[i][j]);
////        }
////    }
////    st.push(i);
////}
////
////void topologicalSort(vector<int>graph[],int v)
////{
////    bool visited[v];
////    stack<int>st;
////
////    for(int i=0;i<v;++i)
////        visited[i]=false;
////    for(int i=0;i<v;++i) {
////        if (!visited[i]) {
////            topologicalSortUtils(graph, visited, st, i);
////        }
////    }
////        while(!st.empty())
////        {
////            cout<<st.top()<<" ";
////            st.pop();
////        }
////    }
////
////int main()
////{
////    int v,e,s,d;cin>>v>>e;
////    vector<int>graph[v];
////    for(int i=0;i<e;++i)
////    {
////        cout<<"Enter the source and destination"<<" ";
////        cin>>s>>d;
////        graph[s].push_back(d);
////    }
////    topologicalSort(graph,v);
////}
//
//
//
//
//#include<bits/stdc++.h>
//using namespace std;
//
//void topologicalSortUtil(vector<int>graph[],bool visited[],stack<int>&st,int i)
//{
//    visited[i]=true;
//    int n=graph[i].size();
//
//    for(int j=0;j<n;++j)
//    {
//        if(!visited[graph[i][j]])
//        {
//            topologicalSortUtil(graph,visited,st,graph[i][j]);
//        }
//    }
//    st.push(i);
//}
//
//void topologicalSort(vector<int>graph[],int v)
//{
//    bool visited[v];
//    stack<int>st;
//
//    for(int i=0;i<v;++i)
//        visited[v]=false;
//    for(int i=0;i<v;++i)
//    {
//        if(!visited[i])
//        {
//            topologicalSortUtil(graph,visited,st,i);
//        }
//    }
//    while(!st.empty())
//    {
//        cout<<st.top();
//        st.pop();
//    }
//}
//
//int main()
//{
//    int v,e,s,d;
//    cout<<"Enter the Vertex and Edges -> "<<"\n";
//    cin>>v>>e;
//    vector<int>graph[v];
//    for(int i=0;i<e;++i)
//    {
//        cout<<"Enter the Source and Destination:"<<"\n";
//        cin>>s>>d;
//
//        graph[s].push_back(d);
//    }
//    cout<<"TOPOLOGICAL SORT representation :"<<"\n";
//    topologicalSort(graph,v);
//}


#include<bits/stdc++.h>
using namespace std;

void topologicalSortUtils(vector<int>graph[],bool visited[],stack<int>&st,int i)
{
    visited[i]=true;
    int n=graph[i].size();

    for(int j=0;j<n;++j)
    {
      if(!visited[graph[i][j]])
      {
          topologicalSortUtils(graph,visited,st,graph[i][j]);
      }
    }
    st.push(i);
}

void topologicalSort(vector<int>graph[],int v)
{
    bool visited[v];
    stack<int>st;

    for(int i=0;i<v;++i)
        visited[i]=false;
    for(int i=0;i<v;++i) {
        if (!visited[i]) {
            topologicalSortUtils(graph, visited, st, i);
        }
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}


int main()
{
    int v,e,s,d;
    cout<<"Enter the Vertex and Edges -> "<<"\n";
    cin>>v>>e;
    vector<int>graph[v];
    for(int i=0;i<e;++i)
    {
        cout<<"Enter the Source and Destination:"<<"\n";
        cin>>s>>d;

        graph[s].push_back(d);
    }
    cout<<"TOPOLOGICAL SORT representation :"<<"\n";
    topologicalSort(graph,v);
}




