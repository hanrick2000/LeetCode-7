//Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
//Example:
//
//nums = [1, 2, 3]
//target = 4
//
//The possible combination ways are:
//(1, 1, 1, 1)
//(1, 1, 2)
//(1, 2, 1)
//(1, 3)
//(2, 1, 1)
//(2, 2)
//(3, 1)
//
//Note that different sequences are counted as different combinations.
//
//Therefore the output is 7.
//Follow up:
//What if negative numbers are allowed in the given array?
//How does it change the problem?
//What limitation we need to add to the question to allow negative numbers?

这题和之前的题也太像了，要是dfs直接超时，因为他只要计数，不需要枚举，所以直接dp+ memo做 其实更像dfs + memo


class Solution {
public:

    int dfs(vector<int>& nums, int target, vector<int> &dp) {
        if(target < 0) return 0;
        
        if(dp[target]!=-1) return dp[target];
        
        if(target == 0) {
            dp[target] = 1;
            return 1;
        }

        int a = 0;
        
        for(auto x: nums) {
        
            a += dfs(nums, target - x, dp);
        }
        
        dp[target] = a;
        
        return a;
    }

    int combinationSum4(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> dp(target+1,-1);

        return dfs(nums,target,dp);
        
    }
};