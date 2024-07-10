#include<bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(vector<vector<int>> adj, vector<bool> &visited,int s)
    {
        visited[s]=true;
        
        if(adj[s].empty()) return;
        
        for(int i:adj[s])
        {
            if(!visited[i])
                dfs(adj,visited,i);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> visited(V,false);
        int ans=0;
        vector<vector<int>> adjList;
        for(int i=0;i<V;i++)
        {
            vector<int> temp;
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1)
                {
                    temp.push_back(j);
                }
            }
            adjList.push_back(temp);
        }
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                ans++;
                dfs(adjList,visited,i);
            }
        }
        return ans;
    }
};