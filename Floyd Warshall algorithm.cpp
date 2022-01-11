#include<bits/stdc++.h>
using namespace std;
#define V 6
void  Floyd_Warshall(int graph[V][V])
{
    int dist[V][V];

    //Assign all values of the graph to all pairs shortest path

    //These are the copying steps....!!
    for(int i =0;i<V;++i)
    for(int j=0;j<V;++j)

    dist[i][j] = graph[i][j];

    //find all pair shortest path by trying all possible paths
    for(int k=0;k<V;++k) //Try all intermediate nodes 
    for(int i=0;i<V;++i) //Try of all possible starting position
    for(int j=0;j<V;++j) //Try for all possible ending position
    {
        if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) //skip if k is unreachable from i or j is unreachable from k
        continue;

        else if(dist[i][k] + dist[k][j] < dist[i][j]) //check if now distance is shorter via vertex k
        dist[i][j] = dist[i][k] + dist[k][j];
    }

    //Check for negative edge weight cycle
    for(int i=0;i<V;++i)
    if(dist[i][i] < 0)
    {
        cout<<"NEGATIVE EDGE CYCLE IS PRESENT"<<endl;
        return;
    }

    //Print shortest path graph
    
    ////>>>>(Values printed as  INT_MAX defines there is no path)
    for(int i=1;i<V;++i)
    {
        for(int j=0;j<V;j++)
        cout<<i<<" To "<<j<<" Distance is "<<dist[i][j]<<" "<<endl;
    }
}

int main()
{
	int graph[V][V] = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
						{INT_MAX, 0, 4, 2, 7, INT_MAX},
						{INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
						{INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
						{INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
						{INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0} };

	Floyd_Warshall(graph);
	return 0;
}



