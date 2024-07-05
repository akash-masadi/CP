#include<bits/stdc++.h>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

///always-    small   big
bool check(string a,string b)
{
    int n=a.length();
    int m=b.length();
    if(n+1!=m) return false;
    int i=0,j=0;
    while(j<m)
    {
        if(a[i]==b[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return i==n;
}
struct compare
{
    bool operator() (string a,string b)
    {
        return a.length()<b.length();
    }
};
int longestStrChain(vector<string> &arr){
    sort(arr.begin(), arr.end(),compare());
    int n=arr.size();
    // copy(arr.begin(),arr.end(),ostream_iterator<string>(cout," "));
    // cout<<'\n';
    // cout<<check("bacd","ac")<<'\n';
    vector<int> dp(n+1,1);
    int ans=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(check(arr[j],arr[i]) && dp[i]<dp[j]+1)
            {
                dp[i]=dp[j]+1;
                ans=max(dp[i],ans);
            }
        }
    }
    return ans;

}