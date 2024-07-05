#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
int f(vector<int>& arr,int i,int j,vector<vector<int>> &dp)
{
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int min_steps=1e9;
    for(int k=i;k<j;k++)
    {
        int steps=arr[i-1]*arr[k]*arr[j]+f(arr,i,k,dp)+f(arr,k+1,j,dp);
        min_steps=min(steps,min_steps);
    }
    return dp[i][j]=min_steps;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
    return f(arr,1,N-1,dp);
}
/*

*/