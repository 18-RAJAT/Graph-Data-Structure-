class Solution {
public:
    
    bool answer = 0;
    void dfs(vector<int>adj[],vector<int>& visited,int source,int destination)
    {
         visited[source] = true;
        if(source == destination)
        {
            answer = 1;
            return;
        }
        
        for(auto V : adj[source])
        {
            if(!visited[V])
            
            dfs(adj,visited,V,destination);
        }
    }
        
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int destination) {
        
        vector<int>adj[n];
        
        for(auto edge :  edges)
        {
           adj[edge[0]].push_back(edge[1]);
           adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int>visited(n,0);
        dfs(adj,visited,start,destination);
        
        return answer;
       
    }
};

