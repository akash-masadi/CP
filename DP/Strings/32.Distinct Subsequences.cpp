#include <bits/stdc++.h> 
using namespace std;


int mod= 1e9+7;
// int f(string s,string t,int i,int j) // j for sub // indexing shifting
// {
// 	if(j==0) return 1;
// 	if(i==0) return 0;
// 	int take=0;
// 	if(s[i-1]==t[j-1])
// 	{
// 		take=f(s,t,i-1,j-1);
// 	}
// 	int notake=f(s,t,i-1,j);
// 	return take+notake;
// }
int distinctSubsequences(string &str, string &sub)
{
	int n=str.length();
	int m=sub.length();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<n;i++)
	{
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(str[i-1]==sub[j-1])
			{
				dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
			}
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
		}
	}
	return dp[n][m];
	// return f(str,sub,n,m);
}
