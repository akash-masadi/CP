/*

https://www.naukri.com/code360/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
 
*/


#include<bits/stdc++.h>
#include<vector>
#include <iostream>
using namespace std;
int lcs1(string s, string t)
{
	
	int n=s.length();
	int m=t.length();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
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
	string ans="";
	int i=n-1,j=m-1;
	while(i>-1 && j>-1)
	{
		if(s[i]==t[j])
		{
			ans=s[i]+ans;
			i--;j--;
		} 
		else
		{
			if(i>0 && j>0 && dp[i-1][j] > dp[i][j-1] )
			{
				i--;
			}
			else
			{
				j--;
			}
		}
	}

	cout<<"  ";
    for(int i=0;i<m;i++)
    {
        cout<<t[i]<<' ';
    }
    cout<<'\n';
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<" ";
        for(int j=0;j<m;j++)
        {
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
	cout<<ans<<'\n';
	return dp[n-1][m-1];
}
int lcs(string s, string t)
{
	string s1=s;
	reverse(s.begin(),s.end());
	cout<<lcs1(s,s1)<<'\n';
	string t1=t;
	reverse(t.begin(),t.end());
	cout<<lcs1(t,t1)<<'\n';
	return 0;
}


/*
*/


