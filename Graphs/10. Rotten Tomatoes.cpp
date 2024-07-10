// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges

#include <bits/stdc++.h>
using namespace std;
#define f(i,k,b) for(int i=k;i<b;i++)
class Solution 
{
    public:
    int dir[4][2] =
    {
      {-1,0},{0,-1},{0,1},{1,0}  
    };
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid)
    {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        queue<pair<int,int>> q;
        f(i,0,n)
        {
            f(j,0,m)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            bool hasRotten = false;
            int size = q.size();
            while(size--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int ni = i + dir[k][0];
                    int nj = j + dir[k][1];
                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1)
                    {
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                        hasRotten = true;
                    }
                }
            }
            ans+=hasRotten;
        }
        f(i,0,n)
        {
            f(j,0,m)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};