//Follow up for "Find Minimum in Rotated Sorted Array":
//What if duplicates are allowed?
//
//Would this affect the run-time complexity? How and why?
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//Find the minimum element.
//
//The array may contain duplicates.


//递归的话和I很类似，无非是考虑a,b,c三个端点值的很多情况罢了。

class Solution {
public:
    int findMinHelper(vector<int>& nums, int start, int end) {
        
        if(start+1==end) return nums[start];
        
        if(start + 2 == end) return min(nums[start],nums[start+1]);
        
        int mid = (start + end)/2;
        
        if(nums[start] > nums[mid]) {
            return findMinHelper(nums,start,mid+1);
        }
        
        if(nums[mid]>nums[end-1]) {
            return findMinHelper(nums, mid, end);
        }
        
        if(nums[mid]<nums[end-1]) {
            return nums[start];
        }
        
        return min(findMinHelper(nums,start,mid+1),findMinHelper(nums, mid, end));
        
        
    }
    
    int findMin(vector<int>& nums) {
        return findMinHelper(nums, 0, nums.size());
    }
};