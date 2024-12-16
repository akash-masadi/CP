#include <bits/stdc++.h>
using namespace std;
/*
Use quick sort algo to find the kth largest element in the array.
but the catch here is we will only sort the elements (n-k)th location.
If the partition index is consists of (N-k) index, then we will sort that part of the array.
*/
class Solution {
public:
    void quickselect(vector<int> &nums,int k,int l,int h)
    {
        if(l<h)
        {
            int i = l;
            int j = h;
            int pivot = nums[l];
            while(i<j)
            {
                while(i<=h && nums[i] <= pivot) i++;
                while(j>=l && nums[j] > pivot) j--;
                if(i<j)
                {
                    swap(nums[i],nums[j]);
                }
            }
            swap(nums[j],nums[l]);
            if(k<j)
                quickselect(nums,k,l,j-1);
            else
                quickselect(nums,k,j+1,h);
        }
    }
    int findKthLargest(vector<int>& nums, int k) 
    {
        int n = nums.size();
        quickselect(nums,n-k,0,n-1);
        return nums[n-k];  
    }
};