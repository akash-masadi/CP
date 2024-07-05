/*

https://www.naukri.com/code360/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION

*/

/*

holding ==0 -> buy 
holding == 1-> buy and sell
holding == 2 -> sell

*/
#include<bits/stdc++.h>
using namespace std;
int f(vector<int> prices, int n,int i,int holding,int cap)
{
    if(cap==0) return 0;
    if(i==n) return 0;
    // buys stock if prev==0 or skip
    long profit=0;
    // if not holding ANYTHING buy that by reducing your current profit
    if(holding==0) // i can buy stock --> index 0 
    {
        // bought by it 
        profit = f(prices,n,i+1,1,cap)-prices[i];
    }
    else // i can't buy stock -> holdings == 2 
    {
        //sell it
        profit = f(prices,n,i+1,0,cap-1)+prices[i];
    }
    long doNothing = f(prices,n,i+1,holding,cap);
    return max(doNothing,profit);
}
int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    if(n<=1) return 0;
    // return f(prices,n,0,0,2);

    vector<vector<vector<long>>> dp(n+1,vector<vector<long>>(2,vector<long>(3,0)));
    for(int i=n-1;i>=0;i--)
    {
        //0 -> false
        for(int cap=1;cap<=2;cap++)
        {
            dp[i][0][cap]=max(dp[i+1][1][cap]-prices[i],dp[i+1][0][cap]);
            dp[i][1][cap]=max(dp[i+1][0][cap-1]+prices[i],dp[i+1][1][cap]);
        }
    }
    return dp[0][0][2];
}

/*

holding ==0 -> buy 
holding == 1-> buy and sell
holding == 2 -> sell





int maxProfit(vector<int>& prices)
{
    int n=prices.size();
    if(n<=1) return 0;
    // return f(prices,n,0,0,2);

    vector<vector<long>> next(2,vector<long>(3,0));
    vector<vector<long>> curr(2,vector<long>(3,0));
    for(int i=n-1;i>=0;i--)
    {
        //0 -> false
        for(int cap=1;cap<=2;cap++)
        {
            curr[0][cap]=max(next[1][cap]-prices[i],next[0][cap]);
            curr[1][cap]=max(next[0][cap-1]+prices[i],next[1][cap]);
        }
        next=curr;
    }
    return next[0][2];
}

*/