#include <bits/stdc++.h>
// BS
using namespace std;
#include<algorithm>
#include<climits>
int bs(vector<int> arr,int l,int h,int key)
{
    while(l<h)
    {
        int mid=(l+h)/2;
        if(arr[mid]<=key)
        {
            l=mid+1;
        }
        else
        {
            h=mid;
        }
    }
    return l;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> v;
    v.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(v.back()<arr[i])
        {
            v.push_back(arr[i]);
        }
        else
        {
            int idx=lower_bound(v.begin(),v.end(),arr[i]) - v.begin();
            v[idx]=arr[i];
        }
    }
    return v.size();
}





/*

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int bs(vector<int>& v, int l, int h, int key) {
    while (l < h) {
        int mid = (l + h) / 2;
        if (v[mid] < key) {
            l = mid + 1;
        } else {
            h = mid;
        }
    }
    return l;
}

int longestIncreasingSubsequence(int arr[], int n) {
    if (n == 0) return 0;

    vector<int> v;
    v.push_back(arr[0]);
    int ans = 1;

    for (int i = 1; i < n; i++) {
        if (v.back() < arr[i]) {
            v.push_back(arr[i]);
            ans = max(ans, (int)v.size());
        } else {
            int idx = bs(v, 0, v.size(), arr[i]);
            v[idx] = arr[i];
        }
    }
    return ans;
}


*******************************************************
N*N approach

int longestIncreasingSubsequence(int arr[], int n) 
{
    vector<int> dp(n,1);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        ans=max(dp[i],ans);
    }
    return ans;
}


 */

