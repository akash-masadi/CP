/*

https://www.naukri.com/code360/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

*/

#include<bits/stdc++.h>
using namespace std;
int f(vector<int> &prices,int n,int i,int holdings)
{
    if(i>=n) return 0;
    int profit=0;
    if(holdings==0) // i can buy
    {
        profit=f(prices,n,i+1,1)-prices[i];
    }
    else  // sell
    {
        profit = prices[i]+f(prices,n,i+2,0);
    }
    int doNothing=f(prices,n,i+1,holdings);
    return max(profit,doNothing);
}
int stockProfit(vector<int> &prices){
    int n=prices.size();
    // return f(prices,n,0,0);
    vector<vector<int>> dp(n+2,vector<int>(2,0));
    for(int i=n-1;i>=0;i--)
    {
        dp[i][0] = max(dp[i+1][0],dp[i+1][1]-prices[i]);
        dp[i][1] = max(dp[i+1][1],dp[i+2][0]+prices[i]);
    }
    return dp[0][0];
}