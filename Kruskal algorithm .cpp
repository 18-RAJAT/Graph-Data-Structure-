#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<pair<int,pair<int,int>>>viii;

viii Kruksals(viii g , int V)
{
    vii result;
    int s,d,w;
    int parent[V];
    for(int i=0;i<V;++i)
    parent[i] = -1;

    sort(g.begin(),g.end());
    int E = g.size();
    for(int i=0;i<E;++i)
    {
        s=g[i].second.first;
        d=g[i].second.second;
        w=g[i].first;

        if(find(s,parent)!=find(d,parent))
        {
            result.push_back(g[i]);
            UnionByWeight(s,d,parent);
        }
    }
    return result;
}


int main()
{
    viii g,result;
    int V,E,s,d,w;
    cin>>V>>E;
    for(int i=0;i<E;++i)
    {
        cin>>s>>d>>w;
        g.push_back(make_pair(w,make_pair(s,d)));
    }
    result = Kruksals(g,V);
    int sum=0;
    for(int i=0;i<result.size();++i)
    {
        int w = result[i].first;
        cout<<result[i].second.first<<" "<<result[i].second.second<<endl;
        sum += w;
    }
    cout<<"Sum of weights is = "<<sum<<endl;
}