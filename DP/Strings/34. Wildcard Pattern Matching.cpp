/*

https://www.naukri.com/code360/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/

#include<bits/stdc++.h>
using namespace std;
bool f(string p,string t,int i,int j)
{
   if(i==0) return j==0;
   // patern is not exhausted but the string is not exhausted
   if(j==0)
   {
      return  p[i-1]=='*' && f(p,t,i-1,j);
   }
   if(p[i-1]==t[j-1] || p[i-1]=='?')
   {
      return f(p,t,i-1,j-1); // move back
   }
   else if(p[i-1]=='*')
   {
      return f(p,t,i-1,j)||f(p,t,i,j-1); // not pick anyone
   }
   return false;
}
bool wildcardMatching(string p, string t)
{
   int n=p.length();
   int m=t.length();
   vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));

   dp[0][0]=true;// base 1
   // base 2 --> j==0
   for(int i=1;i<=n;i++)
   {
      dp[i][0]=(p[i-1]=='*' && dp[i-1][0]);
   }
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=m;j++)
      {
         if(p[i-1]==t[j-1] || p[i-1]=='?')
         {
            dp[i][j]=dp[i-1][j-1];
         }
         else if(p[i-1]=='*')
         {
            dp[i][j]=(dp[i-1][j] || dp[i][j-1]);
         }
      }
   }
   // return f(p,t,n,m);
   return dp[n][m];
}
/*

*************************************************
SPace Optimized version
**************************************************




#include<bits/stdc++.h>
using namespace std;
bool wildcardMatching(string p, string t)
{
   int n=p.length();
   int m=t.length();
   vector<bool> prev(m+1,false);

   prev[0]=true;// base 1]
   for(int i=1;i<=n;i++)
   {
      vector<bool> curr(m+1,false);
      curr[0]=(p[i-1]=='*' && prev[0]);
      for(int j=1;j<=m;j++)
      {
         if(p[i-1]==t[j-1] || p[i-1]=='?')
         {
            curr[j]=prev[j-1]; // unchanged previous one
         }
         else if(p[i-1]=='*')
         {
            curr[j]=(prev[j] || curr[j-1]); // changed previous one
         }
      }
      prev=curr;
   }
   return prev[m];
}

*/
