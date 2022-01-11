#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
const int infinity = 1e9+10; 
vector<int>g[N];

//visited array size and level size...!!

int visited[8] [8];
int level[8] [8];

//X and Y codinate>>

int getX(string s)
{
    return s[0]-'a';
}

int getY(string s)
{
    return s[1]-'1';
}

vector<pair<int,int>>movements={{-1,2},{1,2},{-1,-2},{1,-2},{2,-1},{2,1},{-2,-1},{-2,1}};

int bfs(string source,string destination)
{
    int sourceX = getX(source);
    int sourceY = getY(source);

    int destinationX = getX(destination);
    int destinationY = getY(destination);

    queue<pair<int,int>>q;
    q.push({sourceX,sourceY});

    visited[sourceX] [sourceY] = 1;
    level[sourceX] [sourceY] = 1;

    while(!q.empty())
    {
        pair<int,int>v = q.front();

        int x = v.first, y =v.second;
        q.pop();

        for(auto movement:movements)
        {
            int childX = movement.first + x;
            int childY = movement.second + y;

            if(!isValid (childX,childY))
            continue;

            if(!visited[childX] [childY])
            {
                q.push({childX,childY});

                level[childX][childY] = level[x][y]+1;

                visited[childX][childY]=1;
            }
        }

        if(level[destinationX] [destinationY] != infinity)
        {
            break;
        }
    }

    return level[destinationX][destinationY];
}

//making reset function>>

void reset()
{
    for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++i)
        {
            level[i][j]=infinity;
            level[i][j]=0;
        }
    }
}

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        reset();

        string s1,s2;

        cin>>s1;
        cin>>s2;

        cout<<bfs(s1,s2);
    }
}