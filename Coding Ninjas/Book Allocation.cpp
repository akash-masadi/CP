#include<bits/stdc++.h>
using namespace std;
int check(vector<int> arr,int n,int pages)
{
    int m=1;
    int curr=0;
    for(int i=0;i<n;i++)
    {
        if(curr+arr[i]<=pages)
        {
            curr+=arr[i];
        }
        else
        {
            m++; 
            curr=arr[i];
            if(curr>pages) return m;
        }
    }
    return m;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int h=accumulate(arr.begin(),arr.end(),0);
    int l=*max_element(arr.begin(),arr.end());
    int ans=-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        int can = check(arr,n,mid); // pages 
        if(can<=m)
        {
            ans=mid;
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}