#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
vector<int> divisibleSet(vector<int> &arr)
{
    sort(arr.begin(),arr.end());
    int n=arr.size();
    vector<int> dp(n,1);
    vector<int> idx(n);

    int max_len=1;
    int max_idx=0;
    for(int i=0;i<n;i++) idx[i]=i;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]%arr[j]==0)
            {
                if(dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    idx[i]=j;
                }
            }
        }
        if(dp[i]>max_len)
        {
            max_len=dp[i];
            max_idx=i;
        }
    }
    vector<int> ans(max_len);
    int i=max_len-1;
    while(idx[max_idx]!=max_idx)
    {
        ans[i]=arr[max_idx];
        max_idx=idx[max_idx];
        i--;
    }
    ans[i]=arr[max_idx];
    // for(i=0;i<n;i++)
    // {
    //     cout<<i<<" -> "<<dp[i]<<" "<<idx[i]<<'\n';
    // }
    // cout<<'\n';
    // for(i=0;i<max_len;i++)
    // {
    //     cout<<ans[i]<<' ';
    // }
    // cout<<'\n';
    return ans;
}