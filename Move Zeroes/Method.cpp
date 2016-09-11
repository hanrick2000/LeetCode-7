//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
//For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
//
//Note:
//You must do this in-place without making a copy of the array.
//Minimize the total number of operations.

不能该顺序，不能使用sort color.所以只能使用顺序覆盖的做法。

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i]) nums[count++] = nums[i];
        }
        
        for(int i = count; i <nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};