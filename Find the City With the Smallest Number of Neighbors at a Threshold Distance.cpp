class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
    
     vector<vector<int>> distance(n, vector<int>(n, INT_MAX / 2));
        
        for(auto & EDGE : edges )

        {
            distance[EDGE[0]][EDGE[1]] = EDGE[2];
            distance[EDGE[1]][EDGE[0]] = EDGE[2];
        }
        for(int k=0;k<n;++k)
        {
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j)
                {
                     
                 distance[i][j] = min(distance[i][j] , distance[i][k] + distance[k][j]);
                }
            }
        }
        
        int present_result = -1;
        int count = INT_MAX;
        
        for(int i=0;i<n;++i)
        {
            int current_count = 0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && distance[i][j] <=distanceThreshold )
                    current_count ++;
            }
            
            
            if(current_count <=count)
            {
                count = current_count;
                present_result = i;
            }
        }
        return present_result;=
    }
};