/*
https://www.naukri.com/code360/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION
*/
#include<bits/stdc++.h>
using namespace std;
int f(long *values, int n,int i,bool holding)
{
    if(i==n) return 0;
    // buys stock if prev==0 or skip
    long profit=0;
    // if not holding ANYTHING buy that by reducing your current profit
    if(!holding) // false --> index 0
    {
        // bought by it
        profit = f(values,n,i+1,true)-values[i];
    }
    // holding stock
    else // true --> index 1 
    {
        //sell it
        profit = f(values,n,i+1,false)+values[i];
    }
    long doNothing = f(values,n,i+1,holding);
    return max(doNothing,profit);
}
long getMaximumProfit(long *values, int n)
{
    if(n<=1) return 0;
    // return f(values,n,0,false);

    vector<vector<long>> dp(n+1,vector<long>(2,0)); // 1 = true(holding) 0=false
    dp[n][0]=0;
    dp[n][1]=0;
    for(int i=n-1;i>=0;i--)
    {
        //0 -> false
        dp[i][0]=max(dp[i+1][1]-values[i],dp[i+1][0]);
        // 1 -> true
        dp[i][1]=max(dp[i+1][0]+values[i],dp[i+1][1]);
    }
    return dp[0][0];
}