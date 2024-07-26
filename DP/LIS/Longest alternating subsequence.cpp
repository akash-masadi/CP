#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) 
    {
        int n = arr.size();
        int ans = 1;
        int inc = 1;
        int dec = 1;
        for(int i=1;i<n;i++)
        {
            if(arr[i] < arr[i-1])
            {
                dec = inc+1;
            }
            else if(arr[i] > arr[i-1])
            {
                inc = dec+1;
            }
        }
        ans=max(inc,dec);
        return ans;
    }
};