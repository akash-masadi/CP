#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<vector<int>> q;    
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push(vector<int>{i,j,0}); // 0 - i , 1 - j , 2- steps
                }
                else if (grid[i][j] == 1)
                {
                    count++;
                }
            }
        }
        const int dir[4][2]={ {0,-1} , {0,1} , {-1,0} , {1,0}};
        int ans = 0;
        while(!q.empty())
        {
            vector<int> curr = q.front();
            int x = curr[0];
            int y = curr[1];
            int steps = curr[2];
            ans = max(ans,steps);
            q.pop();
            for(int i=0;i < 4;i++)
            {
                int nextX = x+dir[i][0];
                int nextY = y+dir[i][1];
                if( nextX >= 0 && nextY >= 0 && nextX < n && nextY < m  && grid[nextX][nextY]==1)
                {
                    grid[nextX][nextY] = 2;
                    q.push(vector<int> {nextX,nextY,steps+1});
                    count--;
                }
            }
        }
        return count == 0 ? ans : -1;
    }
};