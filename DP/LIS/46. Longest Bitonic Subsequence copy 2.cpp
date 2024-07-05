#include<bits/stdc++.h>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	vector<int> dp1(n,1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i])
			{
				dp1[i]=max(dp1[i],dp1[j]+1);
			}
		}
	}
	vector<int> dp2(n,1);
	int ans=1;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[i])
			{
				dp2[i]=max(dp2[i],dp2[j]+1);
			}
		}
		ans=max(ans,dp1[i]+dp2[i]-1);
	}
	return ans;
}

/*

23 6 24 26 39 39 33 17 10 45 16 30
1  1  2  3  4  4  4  2  2  5  3  5
                              2  1
*/
