//Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
//
//For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].


//可以先倒序排序，然后把1，2交换，3，4交换。。。

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        for(int i = 0; i+1 < nums.size(); i+=2) {
            swap(nums[i],nums[i+1]);
        }
        
    }
};