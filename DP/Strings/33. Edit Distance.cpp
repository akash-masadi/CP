/*

https://www.naukri.com/code360/problems/edit-distance_630420?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int f(string a,string b,int i,int j)
{
    if(i==0) return j;
    if(j==0) return i;
    int same=1e6,insert=1e6,del=1e6,replace=1e6;

    if(a[i-1]==b[j-1])
    {
        return f(a,b,i-1,j-1);
    }
    del=f(a,b,i-1,j); // del a[i] and check for b[j]
    insert=f(a,b,i,j-1); // insert b[j] at a[i]
    replace=f(a,b,i-1,j-1); // replace a[i] with b[j];
    return 1+min(min(del,insert),replace);
} 
int editDistance(string str1, string str2)
{
    int n=str1.length();
    int m=str2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0)); 
    for(int i=0;i<=n;i++) dp[i][0]=i;
    for(int j=0;j<=m;j++) dp[0][j]=j;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            }
        }
    }
    // return f(str1,str2,n,m);
    return dp[n][m];
}

/*

whgtdwhgtdg
ascfwg
    wg
ascf -4
ascfwg
ascfwg hgtdg -5


acdefgd
aawdfg
  
adfg

acdefgd
acdfg


awadfg -2
acdefgd



*/
