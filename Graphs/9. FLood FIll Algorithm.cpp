#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int dir[4][2] = {
        {-1,0},
      {0,-1},{0,1},
      {1,0}
    };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int i, int j, int nc) 
    {
        int n = image.size();
        int m = image[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        int req = image[i][j];
        
        if(req==nc) return image;
        
        image[i][j]=nc;
        while(!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int ni = i + dir[k][0];
                int nj = j + dir[k][1];
                if(ni>=0 && nj>=0 && ni<n && nj<m && image[ni][nj]==req)
                {
                    image[ni][nj]=nc;
                    q.push({ni,nj});
                }
            }
        }
        return image;
    }
};
