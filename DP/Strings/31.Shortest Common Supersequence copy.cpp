#include <bits/stdc++.h> 
using namespace std;
string shortestSupersequence(string a, string b)
{
	int n=a.length();
	int m=b.length();
	vector<vector<string>> dp(n+1,vector<string>(m+1,""));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i-1]==b[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+a[i-1];
			}
			else
			{
				dp[i][j]=dp[i][j-1];
				if(dp[i-1][j].length() > dp[i][j-1].length())
				{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
	}

	// for(int j=0;j<=m;j++) cout<<b[j]<<" ";
	// cout<<'\n';
	// for(int i=0;i<=n;i++)
	// {
	// 	// cout<<a[i]<<" - \n";
	// 	for(int j=0;j<=m;j++) cout<<dp[i][j]<<" ";
	// 	cout<<'\n';
	// }
	string curr = dp[n][m];
	// cout<<curr<<'\n';

	string ans="";
	int i=0,j=0,k=0;
	while(k<curr.length())
	{
		while(i<n && curr[k]!=a[i]) 
		{
			ans+=a[i];
			i++;
		}
		while(j<m && curr[k]!=b[j]) 
		{
			ans+=b[j];
			j++;
		}
		ans+=curr[k];
		k++;
		i++;
		j++;
		// cout<<i<<" | "<<j<<" | "<<k<<'\n';
	}
	while(i<n) 
	{
		ans+=a[i];
		i++;
	}
	while(j<m) 
	{
		ans+=b[j];
		j++;
	}
	return ans;
}
/*

t
	b r u t e
g	0 0 0 0 0
r	0 1 0 0 0
o	
o	
t	

brute --> rt
groot -->

bleed  ->  ble
bl ue  -> 


bleed
blueed


g r o o t  
      
      
  r r r r 
  r r r r 
  r r r rt 

rt -> bgruoote
8
b l u e  
     
 b b b b 
 b bl bl bl 
 b bl bl ble 
 b bl bl blee 
blee -> blueed
6
n i n j a s  
       
       
       
       
  i i i i i 
 n n in in in in 
in -> codningjas
10
l i g h t s  
       
	l i g h t s      
	l l l l l l 
l	l li li li li li 
i	l li li li li li 
n	l li li li li li 
d	l lii lii lii lii lii 
i	l lii lii lii lii lii 
liig -> blindghtsing
12
*/