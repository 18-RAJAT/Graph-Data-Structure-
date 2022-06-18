//
// Created by rajat joshi on 17-06-2021.
//


#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> colors(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (colors[i])continue;

        colors[i] = 1;
        q.push(i);

        while (!q.empty())
        {
            int temp = q.front();
            for (auto neighbor : graph[temp])
            {
                if (!colors[neighbor])
                {
                    colors[neighbor] = colors[neighbor]-colors[temp];
                    q.push(neighbor);
                }
                else if (colors[neighbor] == colors[temp])
                    return false;
            }
            q.pop();
        }
    }
    return true;
}

int main()
{
    int n = 4;
    vector<vector<int>> edges(n, vector<int>(n, 0));

    edges[0][1] = edges[1][0] = 1;
    edges[0][3] = edges[3][0] = 1;
    edges[1][2] = edges[2][1] = 1;
    edges[2][3] = edges[3][2] = 1;
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                graph[i].push_back(j);
            }
        }
    }

    bool result = isBipartite(graph);
    if (result == true)
    {
        cout << "Bipartite.\n";
    }
    else
    {
        cout << "Not Bipartite.\n";
    }
}