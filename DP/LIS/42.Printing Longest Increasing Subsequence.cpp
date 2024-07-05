#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n) 
{
    vector<vector<int>> dp(n);
    int ans=0;
    vector<int> s;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                if(dp[i].size() < dp[j].size())
                    dp[i]=dp[j];
            }
        }
        dp[i].push_back(arr[i]);
        if(dp[i].size()>ans)
        {
            ans=dp[i].size();
            s=dp[i];
        }
    }
    for(int i:s) cout<<i<<' ';
    cout<<'\n';
    return ans;
}
/*
    5 4 11 1 16 8
5   1 1  2  2 3  
4 
11 
1 
16 
8

*/

// #include <algorithm>
// #include <climits>
// #include <vector>
// using namespace std;
// // int f(int arr[],int prev,int i,int n)
// // {
// //     if(i>n) return 0;
// //     int take=0,notake=0;
// //     if(prev==0 || arr[prev-1]<arr[i-1])
// //     {
// //         take = 1 + f(arr,i,i+1,n);
// //     }
// //     notake = f(arr,prev,i+1,n);
// //     return max(take,notake);
// // }
// int longestIncreasingSubsequence(int arr[], int n) 
// {
//     vector<int> dp(n,1);
//     vector<int> idx(n);
//     for(int i=0;i<n;i++) idx[i]=i;
//     int ans=0;
//     int ansIdx=0;
//     vector<int> s;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<i;j++)
//         {
//             if(arr[j]<arr[i])
//             {
//                 if(dp[i] < dp[j]+1)
//                 {
//                     dp[i]=1+dp[j];
//                     idx[i]=j;
//                 }
//             }
//         }
//         if(dp[i]>ans)
//         {
//             ans=dp[i];
//             ansIdx=i;
//         }
//     }
//     // for(int i=0;i<n;i++)
//     // {
//     //     cout<<i<<" "<<idx[i]<<" "<<dp[i]<<"\n";
//     // }
//     int start = 0;
//     while(idx[ansIdx]!=ansIdx)
//     {
//         cout<<arr[ansIdx]<<" ";
//         ansIdx=idx[ansIdx];
//     }
//     cout<<arr[ansIdx];
//     cout<<'\n';
//     return ans;
// }

