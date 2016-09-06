//Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
//Solve it without division and in O(n).
//
//For example, given [1,2,3,4], return [24,12,8,6].
//
//Follow up:
//Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

//这题思路很简单，先建立一个数组,使得res[i] 记录 nums[0...i-1]的乘积。再反向建立一个数组记录res1[i]，nums[n...i+1]的成绩，这样最后只要求得nums[i] = res[i]*res1[i].
//虽然不能使用额外的空间，但可以充分利用nums和另一个结果vector<int>.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        if(!nums.size()) return {};
        
        vector<int> res(nums.size()+1,1);
        res[1] = nums[0];
        
        for(int i = 2; i < res.size(); ++i) {
            res[i] = nums[i-1]*res[i-1];
        }
        
        for(int i = nums.size()-2; i >=0; --i) {
            nums[i] *= nums[i+1];
        }
        
        nums.push_back(1);
        
        for(int i = 0; i < nums.size()-1; ++i) {
            nums[i] = res[i]*nums[i+1];
        }
        
        nums.pop_back();
        return nums;
    
    }
};
