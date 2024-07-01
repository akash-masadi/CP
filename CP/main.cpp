#include<bits/stdc++.h>
using namespace std;

long countWaysToMakeChange(int *arr, int n, int value)
{
    vector<vector<long>> dp(n,vector<long>(value+1,0));
    sort(arr,arr+n);
    for(int j=0;j<=value;j+=arr[0])
    {
            dp[0][j]=1;
    } 
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=value;j++)
        {
            int notTake=dp[i-1][j],take=0;
            if(j>=arr[i])
            {
                take=dp[i][j-arr[i]];
            }
            dp[i][j]=take+notTake;
        }
    }
    return dp[n-1][value];
}

int main() {
    int arr[] = {1 ,2 ,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value = 4;
    cout << countWaysToMakeChange(arr, n, value) << endl;
    return 0;
}
