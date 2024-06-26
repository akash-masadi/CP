/*LEET CODE
34. Find First and Last Position of Element in Sorted Array

 * Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 */

 // Solution 1:
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int leftIndex = binarySearch(nums, target, true);
        int rightIndex = binarySearch(nums, target, false);

        if (leftIndex <= rightIndex) {
            return new int[]{leftIndex, rightIndex};
        } else {
            return new int[]{-1, -1};
        }
    }

    private int binarySearch(int[] nums, int target, boolean findLeft) {
        int low = 0;
        int high = nums.length - 1;
        int index = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                index = mid;
                if (findLeft) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return index;
    }
}
 /// Solution 2:

class mySolution {
    public int[] searchRange(int[] nums, int target) {
        int left;
        int right;
        int mid=0;
        left = 0;
        right = nums.length-1;
        if(right+1!=0)
        while(left<=right)
        {
            mid = left+(right - left)/2;
            // System.out.println("m "+mid+" "+"l "+left+"r "+right);
            if(nums[mid]==target)
            {
                left = mid;
                right = mid;
                while(left-1>-1 && target == nums[left-1])
                {
                        --left;
                } 
                while(right+1<nums.length && target == nums[right+1])
                {
                        ++right;
                }
                return new int[]{left,right};
            } 
            else if (nums[mid] < target)    left = mid+1;
            else right = mid-1;
        }
        return new int[]{-1,-1};
    }
}
public class findFirstandLast
{
    public static void main(String[] args) {
        long start_milli;
        long start_nano;
        long end_milli;
        long end_nano;
        int[] res;
        int nums[]={5,7,7,8,8,10};
        Solution ob1 = new Solution();
        mySolution ob2 = new mySolution();



        start_nano=System.nanoTime();
        start_milli=System.currentTimeMillis();
        //
        res = ob1.searchRange(nums, 7);
        System.out.println(res[0]+" "+res[1]); // Solution
        //
        end_milli=System.currentTimeMillis();
        end_nano=System.nanoTime();
        System.out.println("Solution 1 : "+(end_milli-start_milli)/1000.0);
        System.out.println(end_nano-start_nano);
        
        start_nano=System.nanoTime();
        start_milli=System.currentTimeMillis();
        //
        res = ob2.searchRange(nums, 7);
        System.out.println(res[0]+" "+res[1]); // Solution
        //

        end_milli=System.currentTimeMillis();
        end_nano=System.nanoTime();
        System.out.println("mySolution  : "+ (end_milli-start_milli)/1000.0);
        System.out.println(end_nano-start_nano);
    }
}