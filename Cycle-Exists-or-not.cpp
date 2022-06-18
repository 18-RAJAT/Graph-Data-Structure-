//
// Created by rajat joshi on 17-06-2021.
//


#include<iostream>
#include<set>
#define NODE 5
using namespace std;
int graph[NODE][NODE] =
        {{0, 1, 1, 0,0},
         {1, 0, 1, 1,1},
         {1, 1, 0, 1,0},
         {0, 1, 1, 0,1},
         {0, 1, 0, 1,0}
        };

bool dfs(int curr, set<int>&wSet, set<int>&gSet, set<int>&bSet) {

    wSet.erase(wSet.find(curr));
    gSet.insert(curr);

    for(int v = 0; v < NODE; v++) {
        if(graph[curr][v] != 0) {
            if(bSet.find(v) != bSet.end())
                continue; if(gSet.find(v)
                             != gSet.end()) return true;

            if(dfs(v, wSet, gSet, bSet))
                return true;
        }
    }
    gSet.erase(gSet.find(curr));
    bSet.insert(curr); return
            false;
}
bool hasCycle() { set<int>
            wSet, gSet, bSet; for(int
                                          i = 0; i<NODE; i++)
        wSet.insert(i);

    while(wSet.size() > 0) { for(int current = 0; current < NODE; current++) {
            if(wSet.find(current) != wSet.end())
                if(dfs(current, wSet, gSet, bSet)) return
                            true;
        }
    }
    return false;
}

int main() {
    bool res;
    res =hasCycle();
    if(res)
        cout << "The graph has a cycle." << endl;
    else
        cout << "The graph has no cycle." << endl;
}