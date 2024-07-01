#include<bits/stdc++.h>
#include<vector>
#include <iostream>
using namespace std;
/*

https://www.naukri.com/code360/problems/minimum-insertions-to-make-palindrome_985293?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
The easiest way is to add the reverse of the string at the back of the original string
 */
int lps(string s,string t)
{
	int n=s.length();
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	for(int i=0;i<n;i++)
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
		for(int j=0;j<n;j++)
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
	return dp[n-1][n-1];
}

/*

  a b c a
a 1 1 1 1
c 1 1 2 2	
b 1 2 2 2 
a 1 2 2 3 
*/

int minimumInsertions(string &str)
{
	string s1=str;
	reverse(str.begin(),str.end());
	return str.length()-lps(s1,str);
}
/*
abca
acba

acbca
abcba

*/