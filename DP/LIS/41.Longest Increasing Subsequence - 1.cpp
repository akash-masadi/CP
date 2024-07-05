#include <bits/stdc++.h>
#include<climits>

using namespace std;
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
    int len=1;
    for(int i=1;i<n;i++)
    {
        if(v.back()<arr[i])
        {
            v.push_back(arr[i]);
            len++;
        }
        else
        {
            int idx=bs(v,0,len,arr[i]);
            v[idx]=arr[i];
        }
    }
    return len;
}
