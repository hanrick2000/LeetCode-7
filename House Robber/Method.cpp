//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

//很简单的动态规划。出bug可以去死了


class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(!nums.size()) return 0;
        
        
        for(int i = 1; i < nums.size(); ++i) {
            if(i==1) nums[i] == max(nums[1],nums[0]);
            nums[i] = max(nums[i]+nums[i-2], nums[i-1]);
        }
        
        return nums.back();
    }
};