#include <bits/stdc++.h> 
using namespace std;


string shortestSupersequence(string a, string b)
{
	int n=a.length();
	int m=b.length();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i-1]==b[j-1])
			{
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	
			}
		}
	}
	int i=n,j=m;
	string ans="";
	while(j>0 && i>0)
	{
		if(a[i-1]==b[j-1])
		{
			ans=a[i-1]+ans;
			i--;
			j--;
		}
		else
		{
			if(dp[i][j-1]>dp[i-1][j])
			{
				ans=b[j-1]+ans;
				j--;
			}
			else{
				ans=a[i-1]+ans;
				i--;
			}
		}
	}
	while(i>0)
	{
		ans=a[i-1]+ans;
		i--;
	}
	while(j>0)
	{
		ans=b[j-1]+ans;
		j--;
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