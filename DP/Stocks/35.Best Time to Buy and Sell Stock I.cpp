/*
https://www.naukri.com/code360/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/
#include <bits/stdc++.h> 
using namespace std;
int maximumProfit(vector<int> &prices){
    int ans=0;
    for(int i=1;i<prices.size();i++)
    {
        ans=max(ans,prices[i]-prices[i-1]);
        prices[i]= min(prices[i],prices[i-1]);
    }
    return ans;
}