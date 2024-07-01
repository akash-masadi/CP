#include<bits/stdc++.h>
#include<vector>
#include <iostream>
using namespace std;
/*

https://www.naukri.com/code360/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

Just calculate the longest common subsequence
calculate the no of deletions in Str A which are not in B 
&&
 the no of insertions in A which are in B not in A 
 */

int lcs(string s,string t)
{
	int n=s.length();
	int m=t.length();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=0;i<m;i++)
	{
		if(s[0]==t[i])
		{
			dp[0][i]=1;
		}
		else
		{
			dp[0][i] = (i>0 ? dp[0][i-1]:0);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(s[i]==t[j])
			{
				dp[i][j] = 1 + (j>0?dp[i-1][j-1]:0);
			}
			else{
				dp[i][j]=max(dp[i-1][j], (j>0?dp[i][j-1]:0));
			}
		}
	}
	return dp[n-1][m-1];
}

int canYouMake(string &s1, string &s2){
    int longest = lcs(s1,s2);
    int n=s1.length();
    int m=s2.length();
    return m+n-longest*2; 
}