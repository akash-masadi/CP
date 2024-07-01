/*
https://www.naukri.com/code360/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int lcs(string &s, string &t){
    if(s.length()>t.length()) return lcs(t,s);
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // for(int j=0;j<=m;j++) dp[0][j]=(s[0]==t[j-1]);
    int ans=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            ans=max(dp[i][j],ans);
        }
    }

    // cout<<"  ";
    // for(int i=0;i<m;i++)
    // {
    //     cout<<t[i]<<' ';
    // }
    // cout<<'\n';
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<s[i-1]<<" ";
    //     for(int j=1;j<=m;j++)
    //     {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // for(int j=0;j<=m;j++)
    // {
    //     ans=max(ans,dp[n][j]);
    // }
    return ans;
}



//     w a s d i j k l
// w   1 0 0 0 0 0 0 0
// s   0 0 1 0 0 0 0 0
// j   0 0 0 0 0 1 0 0
// d   0 0 0 1 0 0 0 0
// k   0 0 0 0 0 0 1 0
// l   0 0 0 0 0 0 0 2 


//     t y f g
// c   0 0 0 0
// v   0 0 0 0
// b   0 0 0 0
// n   0 0 0 0
// u   0 0 0 0
// t   1 0 0 0
// y   1 2 0 0