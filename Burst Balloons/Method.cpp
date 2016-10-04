//Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
//
//Find the maximum coins you can collect by bursting the balloons wisely.
//
//Note: 
//(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
//(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
//
//Example:
//
//Given [3, 1, 5, 8]
//
//Return 167
//
//    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

//这题的动态规划思路是这样的：假设dp[l][r]表示的是扎破数组区间(l,r)之间的最大分数值。那么dp[l][r] = max(nums[l] * nums[i] * nums[r] + dp[l][i] + dp[i][r])   其中 (l<i<r)
//计算时矩阵是对角线这样填。初始时先在数组两边填上两个1。


class Solution {
public:
    int maxCoins(vector<int>& nums) {

        // dp[l][r]（关于i） = nums[l] * nums[i] * nums[r] + dp[l][i] + dp[i][r]    l<i<r
        
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(),0));
        
        for(int i = 2; i < dp.size(); ++i) {
            for(int j = i; j < dp.size(); ++j) {
                
                for(int k = j-i+1; k < j; ++k) {
                    dp[j-i][j] = max(dp[j-i][j], nums[j-i]*nums[k]*nums[j] + dp[j-i][k] + dp[k][j]);
                    
                }

            }
        }
        
        return dp[0].back();
        
    }
};