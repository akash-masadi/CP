/*
# Leetcode Search Insertion
 * Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
 */

 class binaryInsertion {
    public static int searchInsert(int[] nums, int target) {
        int l=0,h=nums.length-1;
        int mid=0;
        //as we are using mid = l + (h-l)/2, we have use the condition l<=h 
        while(l<=h)
        {
            // System.out.println(mid+" "+l+" "+h); 
            //Mid = (l+h)/2 is not apt here;
            //
            mid = l+(h-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }

        }
        return l;
    }
    public static void main(String[] args) {
        int nums[]={1,3,4,5,6,7,8};
        System.out.println(searchInsert(nums,2));
        System.out.println(searchInsert(nums,7));
    }
}