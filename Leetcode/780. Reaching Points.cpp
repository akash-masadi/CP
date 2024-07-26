/*

Main Intelligent finding is - 
Instead of working from start to end, we can work from end to start.
We can work from tx,ty to sx,sy.


*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) 
    {
        if(sx > tx || sy > ty) return false;
        while(tx > sx && ty > sy)
        {
            if(tx > ty)
            {
                tx = tx%ty;
            }
            else
            {
                ty = ty%tx;
            }
        } 
        if(tx==sx && (ty - sy)%sx ==0)
        {
            return true;
        } 
        if(ty==sy && (tx - sx)%sy ==0)
        {
            return true;
        } 
        return false;
    }
};
int main()
{
    Solution s;
    cout<<s.reachingPoints(1,1,3,5)<<endl;
    return 0;
}