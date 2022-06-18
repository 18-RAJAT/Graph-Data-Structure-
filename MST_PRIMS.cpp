#include<bits/stdc++.h>
using namespace std;

int main() {

    int N, m;
    cin >> N >> m;

    vector<pair<int, int>> adj[N];

    int a, b, wt;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }
    int parent[N];
    int key[N];
    bool mstSet[N];

    for (int i = 0; i < N; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        mstSet[u] = true;

        for (auto it: adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
                pq.push({key[v], v});
            }
        }

    }

    for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << " \n";
    return 0;
}





//    int N=5,m=6;
//    vector<pair<int,int> > adj[N];
//    adj[0].push_back({1,2});
//    adj[0].push_back({3,6});
//    adj[1].push_back({0,2});
//    adj[1].push_back({2,3});
//    adj[1].push_back({3,8});
//    adj[1].push_back({4,5});
//    adj[2].push_back({1,3});
//    adj[2].push_back({4,7});
//    adj[3].push_back({0,6});
//    adj[3].push_back({1,8});
//    adj[4].push_back({1,5});
//    adj[4].push_back({2,7});