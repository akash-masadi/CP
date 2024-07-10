#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(vector<int> adj[],vector<bool> &visited,int i)
    {
        queue<pair<int,int>> q;
        q.push({i,i});
        while(!q.empty())
        {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int next :adj[curr])
            {
                if(next==parent) continue;
                else
                {
                    if(!visited[next])
                    {
                        visited[next]=true;
                        q.push({next,curr});
                    }
                    else
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isCycle(int v, vector<int> adj[]) 
    {
        vector<bool> visited(v,false);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                visited[i]=true;
                if(bfs(adj,visited,i))
                {
                    return true;
                }
            }
        }
        return false;
    }
};