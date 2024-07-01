/*'
https://www.naukri.com/code360/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/
	#include<bits/stdc++.h>
	#include <iostream>
	using namespace std;
	string f(string s,string t,int i,int j,vector<vector<string>> &dp)
	{
		if(i<0 || j<0)
		{
			return "";
		}
		if(dp[i][j]!="") return dp[i][j];
		if(s[i]==t[j])
		{
			return f(s,t,i-1,j-1,dp)+s[i];
		}
		string prev=f(s,t,i,j-1,dp);
		string prevRow=f(s,t,i-1,j,dp);
		return dp[i][j]=(prev.length()>prevRow.length())?prev:prevRow;
	}
	int lcs(string s, string t)
	{
		int n=s.length();
		int m=t.length();
		vector<vector<string>> dp(n+1,vector<string>(m+1,""));
		// if s = row wise f = column wise
		for(int i=0;i<m;i++)
		{
			if(s[0]==t[i])	dp[0][i]+=s[0];
			else dp[0][i]+=(i>0 ? dp[0][i-1]:"");
		}
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(s[i]==t[j])
				{
					dp[i][j]+=(j>0?dp[i-1][j-1]:"")+s[i];
				}
				else
				{
					dp[i][j]=dp[i-1][j];
					if(j>0)
					{
						if(dp[i][j].length()<dp[i][j-1].length())
						{
							dp[i][j]=dp[i][j-1];
						}
					}
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
		return 0;
	}





//  ************* Second Approach **************************
//   do same dp and traverse back accordingly
// ---------------------------------------------------------------------------
// int lcs(string s, string t)
// {
// 	int n=s.length();
// 	int m=t.length();
// 	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
// 	for(int i=0;i<m;i++)
// 	{
// 		if(s[0]==t[i])	dp[0][i]=1;
// 		else dp[0][i]=(i>0 ? dp[0][i-1]:0);
// 	}
// 	for(int i=1;i<n;i++)
// 	{
// 		for(int j=0;j<m;j++)
// 		{
// 			if(s[i]==t[j])
// 			{
// 				dp[i][j]=1+(j>0?dp[i-1][j-1]:0);
// 			}
// 			else
// 			{
// 				dp[i][j]=max(dp[i-1][j],(j>0? dp[i][j-1] :0));
// 			}
// 		}
// 	}
// 	string ans="";
// 	int i=n-1,j=m-1;
// 	while(i>-1 && j>-1)
// 	{
// 		if(s[i]==t[j])
// 		{
// 			ans=s[i]+ans;
// 			i--;j--;
// 		} 
// 		else
// 		{
// 			if(i>0 && j>0 && dp[i-1][j] > dp[i][j-1] )
// 			{
// 				i--;
// 			}
// 			else
// 			{
// 				j--;
// 			}
// 		}
// 	}
// 	cout<<ans<<'\n';
// 	return dp[n-1][m-1];
// }


/*

d - 
a d e b c 
 d d d d 
c - 
a d e b c 
 d d d dc 
a - 
a d e b c 
a d d d dc 
d - 
a d e b c 
a ad ad ad dc 
b - 
a d e b c 
a ad ad adb adb 
0





*/