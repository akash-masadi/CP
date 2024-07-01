/*

https://www.naukri.com/code360/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
 
 
 
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;
// int f(string s,string t,int i,int j,vector<vector<int>> &dp)
// {
// 	if(i<0 || j<0)
// 	{
// 		return 0;
// 	}
// 	if(dp[i][j]!=-1) return dp[i][j];
// 	int take=0,notake=0;
// 	if(s[i]==t[j])
// 	{
// 		take=1+f(s,t,i-1,j-1,dp);
// 	}
// 	notake=max(f(s,t,i,j-1,dp),f(s,t,i-1,j,dp));
// 	return dp[i][j]=max(take,notake);
// }
int lcs(string s, string t)
{
	int n=s.length();
	int m=t.length();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	// if s = row wise f = column wise
	for(int i=0;i<m;i++)
	{
		if(s[0]==t[i])	dp[0][i]=1;
		else dp[0][i]=(i>0 ? dp[0][i-1]:0);
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i]==t[j])
			{
				dp[i][j]=1+(j>0?dp[i-1][j-1]:0);
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],(j>0? dp[i][j-1] :0));
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<" - \n";
		for(int j=0;j<m;j++) cout<<t[j]<<" ";
		cout<<'\n';
		for(int j=0;j<m;j++) cout<<dp[i][j]<<" ";
		cout<<'\n';

	}
	return dp[n-1][m-1];
}







/*

a - 
d c a d b 
0 0 1 0 0 d - 
d c a d b 
1 1 1 2 2 e - 
d c a d b 
1 1 1 2 2 b - 
d c a d b 
1 1 1 2 3 c - 
d c a d b 
1 2 2 2 3 3







*/