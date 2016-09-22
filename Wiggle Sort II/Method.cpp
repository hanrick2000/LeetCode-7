//Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//
//Example:
//(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
//(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
//
//Note:
//You may assume all input has valid answer.
//
//Follow Up:
//Can you do it in O(n) time and/or in-place with O(1) extra space?

//把nums排序, 再从末尾开始，分到nums的偶数位(奇数index)上， 剩下的再分到奇数位(偶数index)上。
//O（nlg n)时间    O(n)空间

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        vector<int> nums_copy = nums;
        
        sort(nums_copy.begin(), nums_copy.end());
        
        int i = nums.size()-1;
        for(int j = 1; i >= 0&& j < nums.size(); --i, j+=2) {
            nums[j] = nums_copy[i];
        }
        
        for(int j = 0; i >= 0&& j < nums.size(); --i, j+=2) {
            nums[j] = nums_copy[i];
        }
        
        return;
        
    }
};