class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        //1st value of pair denotes how many trusts he trusts...
        
        //2nd value of pair denotes how many trusts him...
        
        vector<pair<int,int>> arr(n+1,{0,0});
        
        for(int i=0;i<trust.size();++i)
        {
            arr[trust[i][0]].first +=1;
            arr[trust[i][1]].second +=1;
        }
        
        //now find who trusted by n-1 others and he/she do not trusts others...!!
        
        for(int i=1;i<=n;++i)
            
            if(arr[i].first==0 && arr[i].second==n-1)
                return i;
        
        return -1;
        
    }
};